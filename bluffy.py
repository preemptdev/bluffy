from core.ArgumentHandler import Args
from core import helpers
from core.mask.MaskFactory import get_mask_factory, get_factories, MaskFactory
from core.decoder.DecodeHandler import DecodeHandler
from core import logger, banner, preview
from core.Templater import Templater


def get_masked_bin(args) -> str:
    """Given an input, output, and mask type: read the bytes, identify the factory, mask the bytes, write them to disk."""

    if args.bin == None or args.mask == None:
        logger.bad("Please specify -b AND -m (bin file and mask)")
        return None

    # get the bytes of the input bin
    blob: bytes = helpers.get_bytes_from_file(args.bin)

    # if that isnt possible, return.
    if blob == None:
        return None

    logger.info(f"Loaded {args.bin} ({len(blob)} bytes)")

    # get the correct factory
    factory = get_mask_factory(args.mask)

    # if that fails, return.
    if factory == None:
        return None

    # if the factory is obtained, grab the class for the mask
    mask = factory.get_mask_type()
    logger.info(f"Masking shellcode with: {factory.name}")

    # give the blob to the class and perform whatever transformations... This should then return a multiline string containing the transformed data
    return mask.mask(blob)


def build_header_file(args) -> str:
    """Mask the bin and fill out the template!"""

    # mask the bin
    payload: str = get_masked_bin(args)
    if payload == None:
        return None

    # the decodehandler basically pulls the C code that is used to unmask/decode/whatever the bin
    decoder: DecodeHandler = DecodeHandler(args.mask)

    # this is the code with the tempates
    decode_stub = decoder.get_stub()

    if decode_stub == None:
        return None

    # instantiate the templater
    templater = Templater()

    # replace the payload
    decode_stub = decode_stub.replace(templater.payload, payload)

    # replace the size
    decode_stub = decode_stub.replace(
        templater.size, (helpers.get_size_filecontent_size(args.bin))
    )

    # return the code
    return decode_stub


def show_masks() -> None:
    """Call the get_factories() function to get the available options and pretty print them in logger.py"""
    logger.masks(get_factories())
    return


def main() -> None:
    """Get args and execute"""

    banner.show()

    # get args
    args = Args.get_args()

    # if listing, show and quit
    if args.list:
        show_masks()
        quit()

    # otherwise do the thing!
    code: str = build_header_file(args)
    if code == None:
        return

    helpers.write_text_to_file(f"{args.mask}.h", code)

    if args.preview:
        logger.info(f"Loading preview:")
        preview.print_preview(code, "c")

    return


if __name__ == "__main__":
    main()
