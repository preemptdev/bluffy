from core import logger
from pathlib import Path
import random, string
from core import logger

def get_bytes_from_file(fpath: str) -> bytes:
    """Read a file and return its bytes"""
    try:
        fp: Path = Path(fpath)
        return fp.read_bytes()
    except Exception as e:
        logger.bad(f"Failed to read {fpath}: {str(e)}")
        return None


def random_string(size: int) -> str:
    """Get a random string"""
    return "".join(
        random.choice(string.ascii_uppercase + string.digits) for _ in range(size)
    )


def chunker(to_chunk: list, size: int) -> list:
    """Yield successive n-sized chunks from to_chunk."""
    for i in range(0, len(to_chunk), size):
        yield to_chunk[i : i + size]

def write_text_to_file(fpath: str, data: str) -> bool:
    try:
        fp: Path = Path(fpath)
        fp.write_text(data)
        return True
    except Exception as e:
        logger.bad(f"Failed to write {fpath}: {str(e)}")
        return False