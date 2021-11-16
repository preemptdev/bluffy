from abc import ABC, abstractmethod
from core.mask.svg import SVGMgr
from core.mask.uuid import UUIDMgr


class MaskHandler(ABC):
    """Basic representation of a mask handler."""

    def __init__(self):
        self.name = ""

    @abstractmethod
    def mask(self, blob: bytes):
        """mask some data"""


class SVGMasker(MaskHandler):
    """mask with SVG"""

    def mask(self, blob: bytes):
        SVG = SVGMgr(blob)
        return SVG.mask()


class UUIDMasker(MaskHandler):
    """mask with UUID"""

    def mask(self, blob: bytes):
        UUID = UUIDMgr(blob)
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


def get_mask_factory(mask_required: str) -> MaskFactory:
    """Determine the Mask Class"""

    factories = {"svg": SVG(), "uuid": UUID(), "clsid": CLSID()}
    if mask_required.lower() in factories:
        return factories[mask_required]
