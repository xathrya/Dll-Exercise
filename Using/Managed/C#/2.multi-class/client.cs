/*
Simple client to use managed.dll

Compile:
    $ csc client.cs /r:managed.dll

Run: 
    $ client.exe
*/
using System;

// Using the DLL
using CodeLibrary;

namespace DllClient
{
    public class Client 
    {
        // main function
        public static void Main(String[] args)
        {
            // Call all the function
            // AddClass.Add()
            System.Console.WriteLine("The result of 100 + 35 is {0}", AddClass.Add(100, 35));
            
            // MultiClass.Multiply()
            System.Console.WriteLine("The result of 27 * 5 is {0}", MultiClass.Multiply(27, 5));
            
            // FactorialClass.Factorial()
            System.Console.WriteLine("The result of 5! is {0}", FactorialClass.Factorial(5));
            
        }
    }
}