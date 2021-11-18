from core.ArgumentHandler import Args
from core import helpers
from core.mask.MaskFactory import get_mask_factory, get_factories, MaskFactory
from core import logger, banner, preview


def mask_bin(args) -> bool:
    """Given an input, output, and mask type: read the bytes, identify the factory, mask the bytes, write them to disk."""

    if args.bin == None or args.mask == None:
        logger.bad("Please specify -b AND -m (bin file and mask)")
        return False

    # get the bytes of the input bin
    blob: bytes = helpers.get_bytes_from_file(args.bin)

    # if that isnt possible, return.
    if blob == None:
        return False

    logger.info(f"Loaded {args.bin} ({len(blob)} bytes)")

    # get the correct factory
    factory = get_mask_factory(args.mask)

    # if that fails, return.
    if factory == None:
        return False

    # if the factory is obtained, grab the class for the mask
    mask = factory.get_mask_type()
    logger.info(f"Masking shellcode with: {factory.name}")

    # give the blob to the class and perform whatever transformations... This should then return a multiline string containing the transformed data
    bluff = mask.mask(blob)

    if args.preview:
        logger.info(f"Loading preview:")
        preview.print_preview(bluff, "c")

    # try write it to disk, if it doesnt, helpers will print the exception so it doesnt matter.
    # Note: this function appends .c to the file name
    helpers.write_text_to_cfile(factory.name, bluff)

    # hopefully its done!
    return True


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
    mask_bin(args)

    return


if __name__ == "__main__":
    main()
