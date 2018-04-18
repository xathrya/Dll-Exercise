/*
Standard DLL creation with DllMain function.

Compilation
	using gcc:
	$ gcc -shared -o kerangka.dll kerangka.c -Wl,--out-implib,libkerangka.a
	
	using MSVC:
	$ cl /nologo /LD /0x /GS /sdl kerangka.c

Run (test):
	$ rundll32 kerandka.dll
*/
#include <windows.h>

#ifdef __cplusplus
extern "C" {
#endif

/*
__declspec(dllexport) void function(int arguments)
{ 
	
}
*/

/*
	DLL Entry point
	All DLLs can contain an optional entry-point function DllMain(). It is called for both
	initialization (attach) and termination (detach). This gives an opportunity to allocate
	or release additional resources as needed.

	Reference: https://github.com/MicrosoftDocs/cpp-docs/blob/master/docs/build/run-time-library-behavior.md

	Never perform following tasks from within DllMain:
	- Never call following functions (either directly or indirectly). This can cause a deadlock or crash.
		- LoadLibrary() or LoadLibraryEx()
		- Call GetStringTypeA(), GetStringTypeEx(), or GetStringTypeW()
		- Call the registry functions. Registry functions are implemented in Advapi32.dll which might 
		  not be initialized before this DLL.
		- Call CreateProcess(), might load another DLL
		- Call ExitThread(). Exiting thread during DLL detach can cause the loader lock to be acquired 
		  again, causing deadlock or a crash
	- Synchronize with other threads, to avoid deadlock
	- Acquire a synchronization object that is owned by code that is waiting to acquire the loader lock, 
	  to avoid deadlock.
	- Initialize COM threads by using CoInitializeEx(), under certain conditions this function will call LoadLibraryEx()
	- Use memory management function from the dynamic C Run Time (CRT). If CRT is not initialized, calling 
	  these functions might cause crash.
	- Call functions in User32.dll or Gdi32.dll.
	- Use managed code.

	Following tasks are safe to perform within DllMain:
	- Initialize static data structures and members at compile time.
	- Create and initialize synchronization objects.
	- Allocate memory and initialize dynamic data structures (avoiding the functions listed above.)
	- Set up thread local storage (TLS).
	- Open, read from, and write to files.
	- Call functions in Kernel32.dll (except the functions that are listed above).
	- Set global pointers to NULL, putting off the initialization of dynamic members. 
	  In Microsoft Windows Vista™, you can use the one-time initialization functions to ensure that a block of code 
	  is executed only once in a multithreaded environment.
*/
BOOL WINAPI DllMain(HINSTANCE instance, DWORD reason, LPVOID reserved)
{
	switch (reason)
	{
		case DLL_PROCESS_ATTACH: 
			// Initialize once for each new process
			// Return FALSE to fail DLL load
			MessageBox(NULL, TEXT("Message when attached in process."), TEXT("greeting"), MB_OK);
            break;
		case DLL_THREAD_ATTACH:  
			// Do thread-specific initialization
			MessageBox(NULL, TEXT("Message when attached in thread."), TEXT("greeting"), MB_OK);
            break;
		case DLL_THREAD_DETACH:  
			// Do thread-specific cleanup
			MessageBox(NULL, TEXT("Message when detached from thread."), TEXT("greeting"), MB_OK);
            break;
		case DLL_PROCESS_DETACH: 
			// Perform any necessary cleanup
			MessageBox(NULL, TEXT("Message when detached from process."), TEXT("greeting"), MB_OK);
            break;
	}
}

#ifdef __cplusplus
}
#endif