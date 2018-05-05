/*
Simple client to use unmanaged.dll

Using P/Invoke to load DLL function.
See more on `CodeInterop-Exercise`

Compile:
    $ csc client.cs

Run: 
    $ client.exe
*/
using System;
using System.Runtime.InteropServices;

namespace DllClient
{
    public class Client 
    {
        [DllImport("unmanaged.dll")]
        private static extern void world();

        [DllImport("unmanaged.dll")]
        private static extern int  calculate(int n);

        // main function
        public static void Main(String[] args)
        {
            int result;

            // Call world()
            world();

            // Call calculate()
            result = calculate(0);
            System.Console.WriteLine("The result of calculation(0) is {0}", result);
        }
    }
}