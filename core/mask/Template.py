class SVGMgr:
    def __init__(self, blob: bytes):
        self.blob = blob
        self.payload_name = "unsigned char* payload[]"
        self.chunk_size = 10

    def mask(self) -> dict[str:str]:
        """Mask the data as a X"""

        # format the blob!
        return self.format_blob()

    def format_blob(self):
        """Below is an example of a generic c formatter"""

        # convert the blob into hex
        hex_data: list[str] = utilities.get_bytes_as_hex_list(self.blob)

        # create a c array of comma seperated hex
        payload = (
            f"{self.payload_name} = {{ {utilities.join_hex_by_comma(hex_data)} }};"
        )

        data: dict[str, str] = {"payload": payload, "name": "SVG"}

        # return it
        return data
