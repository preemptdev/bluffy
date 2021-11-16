from rich.console import Console
from rich.syntax import Syntax

def print_preview(code, language):
	print()
	console = Console()
	console.print(Syntax(code, language))
	print()