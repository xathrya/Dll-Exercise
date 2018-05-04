/*
Create a managed DLL with C#.
The managed DLL cannot be run from rundll32 so we need another program that load the DLL and call the function

Compile:
    $ csc /t:library /out:managed.dll managed.cs
*/

using System;
using System.Collections.Generic;
using System.Windows.Forms;
using System.Text;

namespace CodeLibrary
{
    public class DllCode
    {
        static void world()
        {
            MessageBox.Show("Hello world! Message box from (Managed) DLL");
        }
    }
}