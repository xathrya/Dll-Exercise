/*
Exporting C++ class to DLL

Declaring a class to DLL is a bit tricky.
Only function can be exported.
When we are exporting whole class, each functions in the class 
will be exported.
Thus, name mangling will be depend on the compiler.

Compilation
	(gcc)
	$ g++ -shared -o unmanaged.dll -Wl,--out-implib,libunmanaged.a DllClass.cpp

	(msvc)
	$ cl /Feunmanaged.dll /LD DllClass.cpp
*/

// Make sure we are exporting the class to DLL
#define __EXPORT_CLASS_

#include <windows.h>
#include <string.h>
#include "DllClass.hpp"

BOOL WINAPI _DllMainCRTStartup()
{
	return 1;
}

DllClass::DllClass()
{
	m_size = 64;
	memset(m_internal, 0, sizeof(m_internal));
	strcpy(m_internal, "No Function call yet");
}

void DllClass::set(const char* message)
{
	int len = strlen(message);
	if (len >= m_size)
		len = m_size - 1;
	strncpy(m_internal, message, len);
	m_internal[len] = 0;
}

char* DllClass::get()
{
	return m_internal;
}
