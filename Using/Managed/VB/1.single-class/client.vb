' Simple client to use managed.dll
'
' Compile:
'     $ vbc client.cs /r:managed.dll
'
' Run: 
'     $ client.exe

imports System

' Use the DLL
imports CodeLibrary

namespace DllClient
    public class Client
        ' main function
        public shared sub Main(args as String())
            dim result as integer
            dim code as DllCode = new DllCode()

            ' Call static function world()
            DllCode.world()

            ' Call calculate()
            result = code.calculate(0)
            System.Console.WriteLine("The result of calculation(0) is {0}", result)
        end sub 'Main
    end class   'Client
end namespace   'DllClient