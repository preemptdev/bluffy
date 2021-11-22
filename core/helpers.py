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


def write_text_to_file(name: str, data: str) -> None:
    """Take in the name of the mask and turn it into a .c filename"""
    try:
        fp: Path = Path(name)
        fp.write_text(data)
        logger.good(f"Written to {fp}")
    except Exception as e:
        logger.bad(f"Failed to write {name}: {str(e)}")
    # doesnt really matter if it works or not, this is the last step and the try/except will tell the user what went wrong anyway
    return


def get_c_var(declaration: str, code: list[str]) -> str:
    """Given a C Variable declaration and a list of (lines of) code, format it into something C will be happy with"""

    # this will contain the final payload
    payload: str = ""

    # add the declaration and open the braces
    payload += f"{declaration} = {{\n"

    # for each line of code...
    for idx, line in enumerate(code):

        # if its the last line, dont add a comma
        if idx == len(code) - 1:
            end = "\n"
        else:
            end = ",\n"

        # escape any "
        if '"' in line:
            line = line.replace('"', '\\"')

        # add it
        payload += f'    "{line}"{end}'

    # close stuff
    payload += "};"

    return payload


def get_size_filecontent_size(path: str) -> str:
    """Wrap the read file from disk function to return the len of the bytes"""
    return str(len(get_bytes_from_file(path)))

def get_xor_logic_c(key: int) -> str:
    """Return the XOR logic"""

    if key == 0:
        return ""
    else:
        return f"for (int i = 0; i < count; ++i)\n\t{{\n\t\tshellcode[i] = (unsigned char)shellcode[i] ^ {hex(key)};\n\t}}"
    