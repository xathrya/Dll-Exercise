/*
Simple client to use unmanaged.dll. 

Implicit linking
The DLL has .lib which is used to create definition of IAT.
This is the case where the .lib file is available.

Compile:
	(dmd)
    {x64 target}
	    $ dmd -m64 client.d unmanaged.lib

    {x86 target}
        $ dmd -m32 client.d unmanaged.lib

run:
	$ client.exe
*/

import std.stdio;

// Import the interfaces
// Tell compiler which functions we will import
import unmanaged;

int main()
{
    int result;

	// Call world()
	world();

	// Call calculate()
	result = calculate(0);
	writefln("The result of calculation(0) is %d\n", result);
	
	return 0;
}