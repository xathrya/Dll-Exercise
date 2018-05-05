' Simple client to use managed.dll
'
' Compile:
'     $ vbc client.cs /r:managed.dll
'
' Run: 
'     $ client.exe

imports System

' Using the DLL
imports CodeLibrary

namespace DllClient
    public class Client 
        ' main function
        public shared sub Main(args as String())
            ' Call all the function
            ' AddClass.Add()
            System.Console.WriteLine("The result of 100 + 35 is {0}", AddClass.Add(100, 35))

            ' MultiClass.Multiply()
            System.Console.WriteLine("The result of 27 * 5 is {0}", MultiClass.Multiply(27, 5))

            ' FactorialClass.Factorial()
            System.Console.WriteLine("The result of 5! is {0}", FactorialClass.Factorial(5))
        end sub 'Main
    end class   'Client
end namespace   'DllClient