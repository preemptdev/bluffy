from core.ArgumentHandler import Args
from core import helpers
from core.mask.MaskFactory import get_mask_factory, MaskFactory
from core import logger, banner


def mask_bin(input_file: str, mask_required: str) -> None:
    """Given an input, output, and mask type: read the bytes, identify the factory, mask the bytes, write them to disk."""

    # get the bytes of the input bin
    blob: bytes = helpers.get_bytes_from_file(input_file)

    # if that isnt possible, return.
    if blob == None:
        return

    logger.info(f"Loaded {input_file} ({len(blob)} bytes)")

    # get the correct factory
    factory = get_mask_factory(mask_required)

    # if that fails, return.
    if factory == None:
        return

    # if the factory is obtained, grab the class for the mask
    mask = factory.get_mask_type()
    logger.info(f"Masking shellcode with: {factory.name}")

    # give the blob to the class and perform whatever transformations... This should then return a multiline string containing the transformed data
    bluff = mask.mask(blob)

    # try write it to disk, if it doesnt, helpers will print the exception so it doesnt matter.
    # Note: this function appends .c to the file name
    helpers.write_text_to_cfile(factory.name, bluff)

    # hopefully its done!
    return


def main() -> None:
    """Get args and execute"""

    banner.show()

    # get args
    args = Args.get_args()

    # do the thing!
    mask_bin(input_file=args.bin, mask_required=args.mask)


if __name__ == "__main__":
    main()
