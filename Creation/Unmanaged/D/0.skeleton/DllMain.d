/*
Standard DLL creation with DllMain function.

Compilation
	(dmd)
	$ dmd -ofDllMain.dll -shared DllMain.d

    (llvm ldc)
    $ ldc 
*/
module unmanaged;

import core.sys.windows.windows;
import core.sys.windows.dll;

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