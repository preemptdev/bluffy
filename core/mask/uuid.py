from uuid import UUID
from core import helpers


class UUIDMgr:
    def __init__(self, blob: bytes):
        self.blob = blob
        self.blob_size = len(blob)
        self.payload_name = "const char* payload[]"
        self.chunk_size = 16
        self.nop = b"\x90"

    def mask(self) -> dict[str:str]:
        """Mask the data as a X"""

        # format the blob!
        return self.format_blob()

    def format_blob(self) -> str:
        """Mask the data as a list of UIDs"""

        # as the bytes are looped through, this will track how much is remaining
        remainder = self.blob_size

        # start at 0, it will increment at 16 and will indicate where to start reading the chunk from
        start = 0

        uuids: list[str] = []

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
            if len(chunk) < 16:
                padding = 16 - len(chunk)
                chunk = chunk + (self.nop * padding)

            # create the uuid
            uuid = UUID(bytes_le=chunk)

            # append to the list
            uuids.append(str(uuid))

        # call the helper function with the payload declaration string and the list of code to transform
        payload: str = helpers.get_c_var(self.payload_name, uuids)

        # return!
        return payload
