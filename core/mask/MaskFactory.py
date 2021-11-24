from abc import ABC, abstractmethod
from core.mask.svg import SVGMgr
from core.mask.css import CSSMgr
from core.mask.uuid import UUIDMgr


class MaskHandler(ABC):
    """Basic representation of a mask handler."""

    def __init__(self):
        self.name = ""

    @abstractmethod
    def mask(self, blob: bytes, payload_preview: bool):
        """mask some data"""


class SVGMasker(MaskHandler):
    """mask with SVG"""

    def mask(self, blob: bytes, payload_preview: bool):
        SVG = SVGMgr(blob, payload_preview)
        return SVG.mask()

class CSSMasker(MaskHandler):
    """mask with CSS"""

    def mask(self, blob: bytes, payload_preview: bool):
        CSS = CSSMgr(blob, payload_preview)
        return CSS.mask()

class UUIDMasker(MaskHandler):
    """mask with UUID"""

    def mask(self, blob: bytes, payload_preview: bool):
        UUID = UUIDMgr(blob, payload_preview)
        return UUID.mask()


class MaskFactory(ABC):
    """Factory that represents a the listener."""

    def __init__(self):
        self.name = ""

    @abstractmethod
    def get_mask_type(self) -> MaskHandler:
        """Returns a new handler for the listener"""


class SVG(MaskFactory):
    """Return the correct SVG Masker object"""

    def __init__(self):
        self.name = "SVG"

    def get_mask_type(self) -> MaskHandler:
        return SVGMasker()

class CSS(MaskFactory):
    """Return the correct CSS Masker object"""

    def __init__(self):
        self.name = "CSS"

    def get_mask_type(self) -> MaskHandler:
        return CSSMasker()


class UUID(MaskFactory):
    """Return the correct UUID Masker object"""

    def __init__(self):
        self.name = "UUID"

    def get_mask_type(self) -> MaskHandler:
        return UUIDMasker()


class CLSID(MaskFactory):
    """Return the correct CLSID Masker object"""

    def __init__(self):
        self.name = "CLSID"

    # NOTE: This is a rare thing. A UUID is a CLSID, but the WinAPI code to parse this is different.
    # So, it will just return the UUID because there isnt any point redoing it all.
    def get_mask_type(self) -> MaskHandler:
        return UUIDMasker()

def get_factories() -> dict[str, MaskFactory]:
    return {"svg": SVG(), "css": CSS(), "uuid": UUID(), "clsid": CLSID()}


def get_mask_factory(mask_required: str) -> MaskFactory:
    """Determine the Mask Class"""
    factories:[str, MaskFactory] = get_factories()
    if mask_required.lower() in factories:
        return factories[mask_required]
