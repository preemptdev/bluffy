import random
from core import helpers


class SVGMgr:
    def __init__(self, blob: bytes):
        self.blob = blob
        self.blob_size = len(blob)
        self.payload_name = "const char* payload[]"
        self.chunk_size = 16
        self.nop = b"\x90"

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

        svg_groups: str = ""

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

            svg_groups += self.get_svg_group(chunk)

        svg_payload: str = ""

        # xml declaration string
        svg_payload += '<?xml version="1.0" standalone="no"?>\n'

        # open the svg tag
        svg_payload += '<svg xmlns="http://www.w3.org/2000/svg" version="1.1" width="5cm" height="5cm">\n'

        # add a random description
        svg_payload += f"<desc>{helpers.random_string(size=36)}</desc>\n"

        # add the groups
        svg_payload += svg_groups

        # close the tag
        svg_payload += "</svg>\n"

        return svg_payload

    def get_svg_group(self, chunk) -> str:
        """Create the svg <g id=x> struct"""

        # get a random string for the group name
        group_name: str = helpers.random_string(size=12)

        # pick a random colour
        colour: str = self.random_colour()

        # empty string to append to
        svg_group: str = ""

        # add the group declaration
        svg_group += f'<g id="{group_name}" fill="{colour}">\n'

        # split the chunk up into a list of ints
        data: list[int] = [idx for idx in chunk]

        # amount of svg attrs that are going to be used
        attrs: int = 4

        # split all the chunks to fit into the attrs require
        for chunk_set in list(helpers.chunker(to_chunk=data, size=attrs)):
            # for every attribute
            for attr in range(0, attrs):
                # for each chunk of a chunk
                svg_group += f'    <rect x="{chunk_set[attr]}cm" y="{chunk_set[attr]}cm" width="{chunk_set[attr]}cm" height="{chunk_set[attr]}cm"/>\n'

        # close the group
        svg_group += "</g>\n"

        return svg_group

    def random_colour(self):
        """Choose a random colour"""
        return random.choice(["red", "blue", "green", "purple", "orange"])
