/*
DLL creation with entrypoint of _DllMainCRTStartup()

Compilation
	using gcc:
	$ g++ -shared -o unmanaged.dll DllMainCRTStartup.cpp -Wl,--out-implib,libDllMainCRTStartup.a
	
	using MSVC:
	$ cl /Feunmanaged.dll /LD DllMainCRTStartup.cpp

Run (test):
	$ rundll32 unmanaged.dll
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
	By default, this function is the entry point and will initialize C Run Time. 
	When created and managed by compiler, it will then call the supplied DllMain(), if any.
	The DllMain is user-supplied function that will initialize user logic. 

	If we provide _DllMainCRTStartup by our own, we will make minimum DLL without CRT.
	
	If you want to do something when Dll is attached, detached then use DllMain().

	Reference: https://github.com/MicrosoftDocs/cpp-docs/blob/master/docs/build/run-time-library-behavior.md
	On process attach, the _DllMainCRTStartup() sets up buffer security checks, initializes the CRT and other
	libraries, initialize run-time type information, initializes and calls constructors for static and 
	non-local data, initializes thread-local storage, increments an internal static counter for each attach, 
	and then calls a user- or library-supplied DllMain

	On process detach, the function goes through these steps in reverse. It calls DllMain, decrements 
	the internal counter, calls destructors, calls CRT termination functions and registered atexit functions, 
	and notifies any other libraries of termination. When the attachment counter goes to zero, the function 
	returns FALSE to indicate to Windows that the DLL can be unloaded
*/
BOOL WINAPI _DllMainCRTStartup(HINSTANCE hInst, DWORD dwReason, LPVOID lpReserved)
{
	return 1;
}

#ifdef __cplusplus
}
#endif