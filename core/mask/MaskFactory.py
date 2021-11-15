from abc import ABC, abstractmethod
from core.mask.svg import SVGMgr


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


class MaskFactory(ABC):
    """Factory that represents a the listener."""

    def __init__(self):
        self.name = ""

    @abstractmethod
    def get_mask_type(self) -> MaskHandler:
        """Returns a new handler for the listener"""


class SVG(MaskFactory):
    """Return the correct SVG Cryptor object"""

    def __init__(self):
        self.name = "SVG"

    def get_mask_type(self) -> MaskHandler:
        return SVGMasker()


def get_mask_factory(mask_required: str) -> MaskFactory:
    """Determine the Mask Class"""

    factories = {"svg": SVG()}
    if mask_required.lower() in factories:
        return factories[mask_required]
