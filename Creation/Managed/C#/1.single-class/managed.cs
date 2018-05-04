/*
Create a managed DLL with C#.

There will be only a single class in the DLL.

The managed DLL cannot be run from rundll32
so we need another program that load the DLL and call the function

Compile:
    $ csc /t:library /out:managed.dll managed.cs
*/

using System;
using System.Windows.Forms;

/*
Questions:
    - What do the DLL export?
    - When reconstruct in .NET-aware decompiler, how much the similarity
      of the soure code and decompiled code?
    - What's the difference of static and non-static method?
*/

namespace CodeLibrary
{
    public class DllCode
    {
        // setter and getter for id
        public string id { get; set; }

        // A static method
        public static void world()
        {
            MessageBox.Show("Hello world! Message box from (Managed) DLL");
        }

        // Instance method
        public int calculate(int n)
        {
            return n + 135;
        }
    }
}