/*
Simple client to use managed.dll

Compile:
    $ cl /clr client.cpp

Run: 
    $ client.exe
*/

// Import the DLL 
#using <managed.dll>

using namespace System;

// Use the DLL
using namespace CodeLibrary;

int main(int argc, char* argv[])
{
    int result;
    DllCode^ code = gcnew DllCode();

    // Call static function world()
    DllCode::world();

    // Call calculate()
    result = code->calculate(0);
    System::Console::WriteLine("The result of calculation(0) is {0}", result);
}