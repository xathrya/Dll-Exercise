' Create a managed DLL with Visual Basic.

' There will be only a single class in the DLL.

' The managed DLL cannot be run from rundll32
' so we need another program that load the DLL and call the function

' Compile:
'     $ vbc /t:library /out:managed.dll managed.vb

imports System
imports System.Windows.Forms

' Questions:
'     - What do the DLL export?
'     - When reconstruct in .NET-aware decompiler, how much the similarity
'       of the soure code and decompiled code?
'     - What's the difference of static and non-static method?

namespace CodeLibrary
    public class DllCode
        ' setter and getter for id
        public property id as string

        ' A static method
        public shared sub world()
            MessageBox.Show("Hello world! Message box from (Managed) DLL")
        end sub

        ' Instance method
        public function calculate(n as integer) as integer
            return n + 135
        end function
    end class
end namespace