import random
from core import helpers, logger, preview


class CSSMgr:
    def __init__(self, blob: bytes,  payload_preview: bool):
        self.blob = blob
        self.blob_size = len(blob)
        self.payload_name = "const char* payload[]"
        self.chunk_size = 16
        self.nop = b"\x90"
        self.payload_preview = payload_preview

    def mask(self) -> None:
        """Mask the data as a X"""

        # format the blob!
        return self.format_blob()

    def format_blob(self):
        """format the blob into an svg!"""

        # as the bytes are looped through, this will track how much is remaining
        remainder = self.blob_size

        # start at 0, it will increment at 16 and will indicate where to start reading the chunk from
        start = 0

        code: list[str] = []

        # start root element
        code.append(':root {{')
        code.append("}}")

        # loop over 16 bytes at a time
        for idx in range(start, self.blob_size, self.chunk_size):

            # subtract 16 from the remainder
            remainder -= self.chunk_size

            # set where to start readin the chunk from
            read_from = start

            # where to finish reading
            read_to = idx + self.chunk_size

            # increment the start for next time
            start += self.chunk_size

            # read the chunk. for example: 0-16, 16-32, etc.
            chunk = self.blob[read_from:read_to]

            # if the chunk isnt 16, pad it with 0x90
            if len(chunk) < self.chunk_size:
                padding = self.chunk_size - len(chunk)
                chunk = chunk + (self.nop * padding)

            # for every group formatted, add it into the code
            for group in self.get_css_group(chunk):
                code.append(group)

        if self.payload_preview:
            logger.info("Loading payload preview:")
            preview.print_payload_preview('\n'.join(map(str, code)), "c")

        payload: str = helpers.get_c_var(self.payload_name, code)

        return payload

    def get_css_group(self, chunk) -> str:
        """Create the css <g id=x> struct"""

        code: list[str] = []

        # get a random string for the group name
        group_name: str = helpers.random_string(size=12)

        # add the group declaration
        code.append(f'.{group_name} div p {{')

        # split the chunk up into a list of ints
        data: list[int] = [idx for idx in chunk]

        # amount of css attrs that are going to be used
        attrs: int = 4

        # split all the chunks to fit into the attrs require
        for chunk_set in list(helpers.chunker(to_chunk=data, size=attrs)):
            # for every attribute
            for attr in range(0, attrs):
                # for each chunk of a chunk
                code.append(
                    f'    border: 2px 2px solid rgb({chunk_set[attr]}, {random.randrange(0,255)}, {random.randrange(0,255)});'
                )

        # close the group
        code.append("}")

        return code