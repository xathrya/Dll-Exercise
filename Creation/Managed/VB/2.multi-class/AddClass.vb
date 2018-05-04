' Create a managed DLL with Visual Basic.

' There will be three classes inside the DLL.
'     - AddClass (this class)
'     - MultiClass
'     - FactorialClass

' Compile:
'     $ vbc /t:library /out:managed.dll AddClass.vb MultiClass.vb FactorialClass.vb

imports System

' Questions:
'     - What do the DLL export?
'     - When reconstruct in .NET-aware decompiler, how much the decompiled code
'       resemblence the source code?
'     - When only this code compiled, what's the content of the DLL?

namespace CodeLibrary
    public class AddClass
        public shared function Add(a as integer, b as integer) as integer
            return a + b
        end function
    end class
end namespace