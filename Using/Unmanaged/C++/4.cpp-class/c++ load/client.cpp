/*
Simple client to use dll. 
The dll has .lib which is used to create definition of IAT

using gcc:
	$ g++ client.cpp -o client.exe -L. -lunmanaged
using MSVC:
	$ cl /nologo client.cpp unmanaged.lib
	
run:
	$ client.exe
*/
#include <cstdio>
#include "DllClass.hpp"

int main()
{
	DllClass dc;
	
	dc.set("Satria Ady Pradana");
	printf("%s\n", dc.get());
	
	return 0;
}
