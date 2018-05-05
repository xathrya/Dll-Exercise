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
    // Call all the function
    // AddClass.Add()
    System::Console::WriteLine("The result of 100 + 35 is {0}", AddClass::Add(100, 35));
    
    // MultiClass.Multiply()
    System::Console::WriteLine("The result of 27 * 5 is {0}", MultiClass::Multiply(27, 5));
    
    // FactorialClass.Factorial()
    System::Console::WriteLine("The result of 5! is {0}", FactorialClass::Factorial(5));
}