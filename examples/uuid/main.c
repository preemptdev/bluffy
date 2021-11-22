#include <windows.h>
#include "uuid.h"

int main()
{
    LPVOID pAddress = WriteUuidToMem();
    int (*go)() = (int(*)())pAddress;
    go();
    return 0;
}