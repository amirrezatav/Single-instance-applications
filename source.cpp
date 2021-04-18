#include <windows.h>

int main()
{

    HANDLE hMutex = CreateMutex(0, 0 , L"MutexName");

    if (GetLastError() == ERROR_ALREADY_EXISTS)
        return 0;
  
    // your code

    ReleaseMutex(hMutex);
    CloseHandle(hMutex);

    return 0;
}
