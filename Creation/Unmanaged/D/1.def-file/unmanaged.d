/*
Create DLL using definition file.

Def file or definition file is used to define the characteristic
of produced object (executable / library).

Compilation:
    (dmd)
    {x64 target}
    $ dmd -m64 -ofunmanaged.dll -shared unmanaged.d unmanaged.def

    {x86 target}
    $ dmd -m32 -ofunmanaged.dll -shared unmanaged.d unmanaged.def

*/
module unmanaged;

import core.sys.windows.windows;
import core.sys.windows.dll;

// Exporting function world() 
extern(C)
export void world()
{
    import core.stdc.stdio;
    printf("Hello from D\n");
}

// Exporting function calculate()
extern(C)
export int calculate(int n)
{
    return n + 135;
}

version(Windows)
extern(Windows) 
bool DllMain(HINSTANCE hInstance, uint ulReason, LPVOID pvReserved)
{
    switch (ulReason)
    {
        default: assert(0);
        case DLL_PROCESS_ATTACH:
            dll_process_attach( hInstance, true );
            break;

        case DLL_PROCESS_DETACH:
            dll_process_detach( hInstance, true );
            break;

        case DLL_THREAD_ATTACH:
            dll_thread_attach( true, true );
            break;

        case DLL_THREAD_DETACH:
            dll_thread_detach( true, true );
            break;
    }
    return true;
}