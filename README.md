# Single instance applications
Some applications are built to allow users to run as many instances of the application as the user desires. Other applications allow only a single instance of the application to be run.

## Using a mutex
The term mutex comes from the words "mutually exclusive." A mutex is a synchronization object typically used to insure that two or more threads do not attempt to simultaneously access shared memory. 

Using a mutex is relatively straightforward. When used in this context, the mutex is used in the main() function as follows:

* Attempt to Create the mutex. 
   * If the mutex does not exist then this is the first instance of the application.
   *  If the mutex exist then terminate the second instance by returning from main().
* Create the mutex if it does not already exist.
* Release the mutex before returns. This only happens when the application closes.
* close Pointer (HANDLE/void*)

The following code is the simplest main() that can be written given the above steps:

    #include <windows.h>

    int main(int argc, char* argv[])
    {
    // you can use void* Instead of HANDLE

        HANDLE hMutexHandle = CreateMutex(NULL, // Ignored. Must be set to NULL.
        TRUE, //Specifies the initial owner of the mutex object:
                // TRUE : the caller created the mutex Calling thread obtains ownership of the mutex object.
                // FALSE : Calling thread does not obtain ownership of the mutex.
        L"MutexName"
        ); 
        // Nonzero indicates success. Zero indicates failure. To get extended error information, call GetLastError

        if (GetLastError() == ERROR_ALREADY_EXISTS) 
            return 0;
    
        // Your Code 

        ReleaseMutex(hMutexHandle); // Releases ownership of the specified mutex object.
        // you can use delete(hMutexHandle) Instead of CloseHandle(hMutexHandle)
        CloseHandle(hMutexHandle);
        return 0;
    }
 
 [CreateMutex Fintion](https://docs.microsoft.com/en-us/windows/win32/api/synchapi/nf-synchapi-createmutexa)
 [GetLastError Function](https://docs.microsoft.com/en-us/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror).
