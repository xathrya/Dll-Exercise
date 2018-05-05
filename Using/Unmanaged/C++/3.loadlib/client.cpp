/*
Load library on runtime.
Use Win32 API to load the library and then get function address.

Explicit linking

Compile:
	(gcc)
	$ g++ client.cpp -o client.exe

	(msvc)
	$ cl /nologo client.cpp
	
run:
	$ client.exe
*/

#include <windows.h>
#include <cstdio>

#ifdef _MSC_VER
#pragma comment(lib,"advapi32")
#pragma comment(lib,"kernel32")
#pragma comment(lib,"user32")
#endif

#ifdef __cplusplus
extern "C" {
#endif

/*
Every function has type signature which gives several information
such as:
	- type of return value
	- number of arguments
	- type of each arguments.

The GetProcAddress() API only return the address of function.
The address would be a function pointer.
It is the responsible of user to cast it for correct type signature. 
*/

// Alt 1: We can create a typedef
typedef void (__stdcall* func_world)();

int main()
{
	int result;

	// Load DLL module =================================================
	// Before getting the address of function, we need to load the library
	// and let it mapped to our memory.
	HMODULE hDll = LoadLibrary("unmanaged.dll");
	if (hDll == NULL) 
	{
		MessageBox(NULL, "Cannot locate the DLL file", "Error", MB_OK);
		return 1;
	}
	
	// Get function by name ============================================
	// Alt 1: create a new type for type signature.
	//        and then cast the address
	func_world world = (func_world) GetProcAddress(hDll, "world");

	// Alt 2: Create a function pointer directly
	//        and then cast the address
	int (*calculate)(int) = (int (*)(int)) GetProcAddress(hDll, "calculate");

	// Check if any function is unresolved
	if (world==NULL || calculate == NULL) 
	{
		MessageBox(NULL, "Could not locate the function", "Error", MB_OK);
		return 2;
	}

	// Call the function ===============================================
	// Call the world()
	world();

	// Call the calculate(0)
	result = calculate(0);
	printf("The result of calculation(0) is %d\n", result);
		
	FreeLibrary(hDll);
}

#ifdef __cplusplus
}
#endif