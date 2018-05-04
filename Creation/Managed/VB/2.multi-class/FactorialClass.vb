' Create a managed DLL with Visual Basic.

' There will be three classes inside the DLL.
'     - AddClass
'     - MultiClass
'     - FactorialClass (this class)

' Compile:
'     $ vbc /t:library /out:managed.dll AddClass.vb MultiClass.vb FactorialClass.vb

imports System

' Questions:
'     - What do the DLL export?
'     - When reconstruct in .NET-aware decompiler, how much the decompiled code
'       resemblence the source code?
'     - When only this code compiled, what's the content of the DLL?

namespace CodeLibrary
    public class FactorialClass
        public shared function Factorial(i as integer) as integer
            return if((i <= 1), 1, (i * FactorialClass.Factorial(i-1)))
        end function
    end class
end namespace