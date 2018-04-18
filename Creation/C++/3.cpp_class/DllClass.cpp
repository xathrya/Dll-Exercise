/*
DLL with exporting C++ class

Compilation
	using gcc
	$ g++ -shared -o dllclass.dll -Wl,--out-implib,libdllclass.a dllclass.cpp

	using MSVC
	$ cl /nologo /LD /Ox /GS /sdl dllclass.cpp
*/

// Make sure we are exporting the class to DLL
#define __EXPORT_CLASS_

#include <windows.h>
#include <string.h>
#include "DllClass.hpp"

extern "C"
{
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

	int DllClass::set(const char* message)
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
}