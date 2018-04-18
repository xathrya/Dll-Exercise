/*
Load library on runtime.
Use Win32 API to load the library and then get function address.

Explicit linking

using gcc:
	$ gcc loadlib.c -o loadlib.exe
using MSVC:
	$ cl /nologo loadlib.c hello.lib
	
run:
	loadlib.exe
*/

#include <windows.h>

#ifdef _MSC_VER
#pragma comment(lib,"kernel32")
#pragma comment(lib,"user32")
#pragma comment(linker,"/subsystem:windows /entry:main")
#endif

#ifdef __cplusplus
extern "C" {
#endif

// Generic function pointer type
typedef int (__stdcall* func_ptr)();

int main()
{
	// Load DLL module to executable mapped memory
	HMODULE hDll = LoadLibrary("hello.dll");
	if (hDll == NULL) 
	{
		MessageBox(NULL, "Cannot locate the DLL file", "Error", MB_OK);
		return 1;
	}
	
	// Get function by name
	func_ptr world = (func_ptr) GetProcAddress(hDll, "world");
	if (!world)
	{
		MessageBox(NULL, "Could not locate the function", "Error", MB_OK);
		return 2;
	}

	// Call the function
	world();
		
	FreeLibrary(hDll);
}




#ifdef __cplusplus
}
#endif