/*
Simple DLL creation with import lib

To export functions to DLL, a special macro should be used.
__declspec is specific to building DLL.

Compilation
	(gcc)
	$ g++ -shared -o unmanaged.dll -Wl,--out-implib,libunmanaged.a unmanaged.cpp

	(msvc)
	$ cl /LD unmanaged.cpp kernel32.lib advapi32.lib
	
run
	$ rundll32 unmanaged.dll,world
*/

#include <windows.h>

/* Need these libraries for some functions. */
#ifdef _MSC_VER
#pragma comment(lib,"advapi32")
#pragma comment(lib,"kernel32")
#pragma comment(lib,"user32")
#endif

#ifdef __cplusplus
extern "C" {
#endif


/* Exporting function world() by __declspec(dllexport) */
__declspec(dllexport) 
void world()
{
	DWORD dwtemp = 62;
	TCHAR szname[64], szbuff[MAX_PATH+1];
	
	if (GetUserName(szname, &dwtemp))
		wsprintf(szbuff, "Hello %s, how are you?", szname);
	else
		lstrcpyn(szbuff, "Hello stranger! :D", 18);
	MessageBox(NULL, szbuff, TEXT("Title"), MB_OK | MB_ICONINFORMATION);
}

/* Exporting function calculate() by __declspec(dllexport) */
__declspec(dllexport)
int calculate(int n)
{
	return n + 135;
}

BOOL WINAPI _DllMainCRTStartup(HINSTANCE hInst, DWORD dwReason, LPVOID lpReserved)
{
	return 1;
}

#ifdef __cplusplus
}
#endif