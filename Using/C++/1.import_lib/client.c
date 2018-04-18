/*
Simple client to use hello.dll. 
The dll has .lib which is used to create definition of IAT

Implicit linking

using gcc:
	$ gcc client.c -o client.exe -L. -lhello
using MSVC:
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

int main()
{
	// There would be a warning because we haven't declare world()
	world();
	
	return 0;
}


#ifdef __cplusplus
}
#endif