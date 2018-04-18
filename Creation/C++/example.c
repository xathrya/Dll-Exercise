/*
Simple DLL exporting a function.
Call exported function via rundll32.

Compilation
	using gcc
	$ g++ -shared -o hasmain.dll -Wl,--out-implib,libhasmain.a hasmain.cpp

	using MSVC
	$ cl /nologo /LD /Ox /GS /sdl hasmain.cpp
	
run
	rundll32 hasmain.dll,_DllMainCRTStartup
*/

#include <windows.h>

void world()
{
	MessageBox(NULL, TEXT("Halo dunia"), TEXT("Title"), MB_OK | MB_ICONINFORMATION);
}

BOOL WINAPI _DllMainCRTStartup(HINSTANCE hinst, DWORD dwReason, LPVOID lpres)
{
	world();
	world();
}