' Simple client to use unmanaged.dll
'
' Using P/Invoke to load DLL function.
' See more on `CodeInterop-Exercise`
'
' Compile:
'     $ vbc client.cs
'
' Run: 
'     $ client.exe

imports System
imports System.Runtime.InteropServices

' P/Invoke
' Call the native code from managed code.
' The prototype of native function should be declared before use.

' Reverse P/Invoke
' Call the managed code from native code.
' Usually as a callback
' A delegate function should be declared before use.
' Delegate function will then forward the call to specific function.

namespace DllClient
    public class Client 

        '===== Native declaration ====================================
        ' Both of this type of declarations are valid
        <DllImport("unmanaged.dll")>
        private shared  sub world()
        end sub

        public  declare function calculate lib "unmanaged.dll" (n as integer) as integer

        '===== Main functions ========================================
        public shared sub Main(args as String())
            dim result as integer

            ' Call world()
            world()

            ' Call calculate
            result = calculate(0)
            System.Console.WriteLine("The result of calculation(0) is {0}", result)
        end sub 'Main
    end class   'Invoke
end namespace   'DllClient