from dataclasses import dataclass


@dataclass(order=True)
class Templater:
    """Dataclass to hold all the template variable names used throughout bluffy"""

    # payload
    payload: str = "###PAYLOAD###"

    # Size of the payload
    size: str = "###SIZE###"

    # Logic to handle de-XOR-ing (aka XOR)
    xor_logic: str = "###XOR_LOGIC###"