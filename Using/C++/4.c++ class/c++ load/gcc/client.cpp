/*
Simple client to use dll. 
The dll has .lib which is used to create definition of IAT

using gcc:
	$ g++ client.cpp -o client.exe -L. -ldllclass
using MSVC:
	$ cl /nologo client.cpp cfoo.lib
	
run:
	client.exe
*/
#include <stdio.h>

#ifdef _MSC_VER
#pragma comment(lib,"kernel32")
#pragma comment(lib,"user32")
#pragma comment(linker,"/subsystem:windows /entry:main")
#endif

#include "DllClass.hpp"

int main()
{
	DllClass dc;
	
	dc.set("Satria Ady Pradana");
	printf("%s\n", dc.get());
	
	return 0;
}
