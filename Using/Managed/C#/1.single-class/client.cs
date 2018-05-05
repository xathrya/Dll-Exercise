/*
Simple client to use managed.dll

Compile:
    $ csc client.cs /r:managed.dll

Run: 
    $ client.exe
*/
using System;

// Use the DLL
using CodeLibrary;

namespace DllClient
{
    public class Client 
    {
        // main function
        public static void Main(String[] args)
        {
            int result;
            DllCode code = new DllCode();

            // Call static function world()
            DllCode.world();

            // Call calculate()
            result = code.calculate(0);
            System.Console.WriteLine("The result of calculation(0) is {0}", result);
        }
    }
}