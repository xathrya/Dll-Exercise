/*
Create a managed DLL with Managed C++.

There will be only a single class in the DLL.

The managed DLL cannot be run from rundll32
so we need another program that load the DLL and call the function

Compile:
    $ cl /clr /LD /Femanaged.dll managed.cpp
*/

// For marshaling from unmanaged to managed
#include <msclr/marshal_cppstd.h>

// Include the .NET DLL
#using <System.Windows.Forms.dll>

using namespace System;
using namespace System::Windows::Forms;

/*
Questions:
    - What do the DLL export?
    - What's the difference of managed and unmanaged DLL?
    - When reconstruct in .NET-aware decompiler, how much the similarity
      of the soure code and decompiled code?
    - What's the difference of static and non-static method?
*/

namespace CodeLibrary
{
    public ref class DllCode
    {
    public:
        // A static method
        static void world()
        {
            // Unmanaged string will be converted to managed string
            // Although managed code can also convert from char* or wchar_t*
            // We do this for sake of reference
            std::string stdstr = "Hello world! Message box from (Managed) DLL";
            String ^ message = msclr::interop::marshal_as<System::String^>(stdstr);

            // It would be similar to
            //String^ message = "Hello world! Message box from (Managed) DLL";

            MessageBox::Show(message);
        }

        // Instance method
        int calculate(int n)
        {
            return n + 135;
        }
    };
};