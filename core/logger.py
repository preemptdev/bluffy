from rich.console import Console
from rich import print

console = Console()


def good(string):
    print(f"[bold green]\\_[/bold green] {string}")


def info(string):
    print(f"[bold blue]\\_[/bold blue] {string}")


def bad(string):
    print(f"[bold red]\\_[/bold red] {string}")
