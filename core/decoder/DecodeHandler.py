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

        stub_path = None

        try:
            stub_path = [i for i in self.c_stubs if self.mask in str(i)][0]
        except IndexError:
            stubbo = self.path.glob("core/decoder/stubs/*.c")
            logger.bad(f"Failed to find a C stub for '{self.mask}' within 'core/decoder/stubs'!")
            logger.bad(f"  Identified {len(self.c_stubs)} stubs within 'core/decoder/stubs':")
            stub_path = [i for i in self.c_stubs if self.mask in str(i)]
            for stub in self.c_stubs:
                logger.bad(f"    '{stub}'")
            logger.bad("Exiting program")
            return None;

        code = stub_path.read_text()

        return code

        # outpath: Path = Path(f"{self.mask.upper()}_decoder")

        # if helpers.write_text_to_cfile(str(outpath), code):
        #     return True
        # else:
        #     return False
