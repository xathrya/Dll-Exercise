/*
Create a managed DLL with C++.

There will be three classes inside the DLL.
    - AddClass
    - MultiClass
    - FactorialClass (this class)

Compile:
     $ cl /clr /LD /Femanaged.dll AddClass.cpp MultiClass.cpp FactorialClass.cpp
*/

using namespace System;

/*
Questions:
    - What do the DLL export?
    - When reconstruct in .NET-aware decompiler, how much the decompiled code
      resemblence the source code?
    - When only this code compiled, what's the content of the DLL?
*/

namespace CodeLibrary
{
    public ref class FactorialClass
    {
    public:
        static int Factorial(int i)
        {
            return ((i <= 1) ? 1 : (i * Factorial(i-1)));
        }
    };
};