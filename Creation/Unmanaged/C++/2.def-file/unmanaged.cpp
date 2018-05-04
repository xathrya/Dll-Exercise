/*
Create DLL using definition file.

Def file or definition file is used to define the characteristic
of produced object (executable / library).

compilation:
	(gcc)
	$ g++ -shared -o unmanaged.dll unmanaged.cpp

	(msvc)
	$ cl /LD unmanaged.cpp unmanaged.def
	
run:
	$ rundll32 unmanaged.dll,world

ps:
GCC doesn't need DEF file. However, MinGW can produce DEF file from a DLL file
	$ dlltool -z output.def --export-all-symbol unmanaged.dll

or it can also create an interface lib from DEF file
	$ dlltool -d input.def -l unmanaged.a 
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


/* Exporting function world() by def file */
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

/* Exporting function calculate() by def file */
int calculate(int n)
{
	return n + 135;
}

BOOL WINAPI _DllMainCRTStartup(HINSTANCE hinst, DWORD dwReason, LPVOID lpres)
{
	return 1;
}

#ifdef __cplusplus
}
#endif