/*
Class is mangled, so we need to know the mangled function name.
	dumpbin /exports dllclass.dll

or using Radare2's rabin2
	rabin2 -iE dllclass.dll
	
This sample is using GCC mangle

*/

#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include "DllClass.hpp"

#include <exception>

typedef void  (WINAPI *PCTOR)();
typedef int   (WINAPI *POPS)(int i, int j);
typedef char* (WINAPI *PCHR)();



int main()
{
	int result = 0;
	
	HMODULE hDll = LoadLibrary("dllclass.dll");
	printf("ADDR(hDll) : %p\n", hDll);
	if (NULL == hDll)
	{
		printf("LoadLibrary failed\n");
		return 1;
	}

	DllClass* pDllClass = (DllClass*) malloc(sizeof(DllClass));
	printf("ADDR(pDllClass): %p\n", pDllClass);
	if (NULL == pDllClass)
	{
		printf("Allocation failed\n");
		return 2;
	}
	
	// Construct object ---------------------------------------------------------
	PCTOR pCtor = (PCTOR) GetProcAddress(hDll, "_ZN8DllClassC1Ev");
	printf("ADDR(pCtor): %p\n", pCtor);
	if (NULL == pCtor)
	{
		printf("GetProcAddress(DllClass) failed\n");
		return 3;
	}
#ifdef _MSC_VER
	__asm { MOV ECX, pDllClass }
#else
	asm("MOV %0, %%ecx" : : "r"(pDllClass));
#endif 
	pCtor();
	
	// Get the last function called  --------------------------------------------
	PCHR pLast = (PCHR) GetProcAddress(hDll, "_ZN4DllClass13last_functionEv");
	if (NULL == pLast)
	{
		printf("GetProcAddress(last_function) failed\n");
		return 3;
	}
	
	// For add(int,int)
	POPS pAdd = (POPS) GetProcAddress(hDll, "_ZN4DllClass3addEii");
	if (NULL == pAdd)
	{
		printf("GetProcAddress(add) failed\n");
		return 3;
	}
	result = pAdd(5, 10);
	printf("Result: %d\n", result);

#ifdef _MSC_VER
	__asm { MOV ECX, pDllClass }
#else
	asm("MOV %0, %%ecx" : : "r"(pDllClass));
#endif 
	printf("[*] Operation message: %s\n", pLast());
	
	// For sub(int,int)
	POPS pSub = (POPS) GetProcAddress(hDll, "_ZN4DllClass3subEii");
	if (NULL == pSub)
	{
		printf("GetProcAddress(sub) failed\n");
		return 3;
	}
	result = pSub(15, 10);
	printf("Result: %d\n", result);
	
#ifdef _MSC_VER
	__asm { MOV ECX, pDllClass }
#else
	asm("MOV %0, %%ecx" : : "r"(pDllClass));
#endif 
	printf("[*] Operation message: %s\n", pLast());
	
	free(pDllClass);
	FreeLibrary(hDll);
}