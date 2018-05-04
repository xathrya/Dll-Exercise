/*
Create a DLL where no original .lib / .a file found.
Implicit linking.

Create a .DEF file and then use it to generate a .lib file.

Creating import lib:
	(gcc)
	$ dlltool -l unmanaged.lib -d unmanaged.def

	(msvc)
	$ lib /def:unmanaged.def /machine:x64

Compiling:
	(gcc)
	$ g++ client.cpp -o client.exe -L. -lunmanaged

	(msvc)
	$ cl /nologo client.cpp unmanaged.lib
	
run:
	client.exe
*/
#include <windows.h>
#include <cstdio>

#ifdef __cplusplus
extern "C" {
#endif

/*
Declare the functions to be imported.
*/
__declspec(dllimport) void world();
__declspec(dllimport) int  calculate(int n);

int main()
{
	int result;

	// Call world()
	world();

	// Call calculate()
	result = calculate(0);
	printf("The result of calculation(0) is %d\n", result);
	
	return 0;
}


#ifdef __cplusplus
}
#endif