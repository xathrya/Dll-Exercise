/*
Simple client to use unmanaged.dll. 

Implicit linking
The DLL has .lib which is used to create definition of IAT.
This is the case where the .lib file is available.

Compile:
	(gcc)
	$ g++ client.cpp -o client.exe -L. -lunmanaged

	(msvc)
	$ cl /nologo client.cpp unmanaged.lib
	
run:
	$ client.exe
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