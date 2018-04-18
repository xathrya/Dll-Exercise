/*
Create a DLL where no original .lib / .a file found.
Generate a .DEF file from DLL and use it to create a lib file.

Implicit linking.

using gcc:
	1. creating import lib file
		$ dlltool 
	2. compile
		$ gcc client.c -o client.exe -L. -lhello

using msvc:
	1. creating import lib file
		$ lib /def:hello.def /machine:x64
	2. compile
		$ cl /nologo client.c hello.lib
	
run:
	client.exe
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

void __declspec(dllimport) world();

int main()
{
	world();
	
	return 0;
}


#ifdef __cplusplus
}
#endif