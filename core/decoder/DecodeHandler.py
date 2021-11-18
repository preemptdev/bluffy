from core.mask.MaskFactory import get_factories
from core import logger, helpers
from pathlib import Path


class DecodeHandler:
    def __init__(self, mask: str) -> None:
        self.mask = mask
        self.path: Path = Path()
        self.c_stubs = list(self.path.glob("core/decoder/stubs/*.c"))

    def get_stub(self) -> str:
        if self.mask not in get_factories().keys():
            return False

        stub_path = [i for i in self.c_stubs if self.mask in str(i)][0]
        if stub_path == None:
            logger.bad(f"Failed to find a C stub for {self.mask}!")
            return None

        code = stub_path.read_text()

        return code

        # outpath: Path = Path(f"{self.mask.upper()}_decoder")

        # if helpers.write_text_to_cfile(str(outpath), code):
        #     return True
        # else:
        #     return False
