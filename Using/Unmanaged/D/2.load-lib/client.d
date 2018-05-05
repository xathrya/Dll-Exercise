/*
Load library on runtime.
Use Win32 API to load the library and then get function address.

Explicit linking

Compile:
	(dmd)
    {x64 target}
	    $ dmd -m64 client.d unmanaged.lib

    {x86 target}
        $ dmd -m32 client.d unmanaged.lib
	
run:
	$ client.exe
*/

import core.runtime;

// Import these functions so we can load functions from DLL
extern(Windows) void* LoadLibraryA(const char* filename);
extern(Windows) void* GetProcAddress(void*, const char*); 
extern(Windows) bool  FreeLibrary(void*);

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

// Create a new alias / typedef
alias extern(C) void function()    func_world;
alias extern(C) int  function(int) func_calculate;

int main()
{
    import std.stdio;

    int result;

    // Load DLL module =================================================
	// Before getting the address of function, we need to load the library
	// and let it mapped to our memory.
	auto dll = LoadLibraryA("unmanaged.dll");
	if (dll is null) 
	{
		writeln("Cannot locate the DLL file");
		return 1;
	}
	
	// Get function by name ============================================
	auto world     = cast(func_world)     GetProcAddress(dll, "world");
    auto calculate = cast(func_calculate) GetProcAddress(dll, "calculate");

	// Check if any function is unresolved
	if ((world is null) || (calculate is null)) 
	{
		writeln("Could not locate the function");
		return 2;
	}

	// Call the function ===============================================
	// Call the world()
	world();

	// Call the calculate(0)
	result = calculate(0);
	writefln("The result of calculation(0) is %d\n", result);
		
	FreeLibrary(dll);

    return 0;
}