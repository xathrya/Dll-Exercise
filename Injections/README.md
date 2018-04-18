# DLL Injection exercise

DLL Injection works by tricking / forcing the target process into loading a DLL of our choice.
It will then execute code in DLL as part of target process and will be able to do anything the process itself can.

The entrypoint of the DLL will be executed by the OS once it is loaded.
What if we performs an in-memory patching of all the location within the original binary and redirect into DLL?

# Techniques
- AppInit_DLLs key
    The OS loader queries the AppInit_DLL registry key and loads the DLLs specified there when a process is created.
    Basically same with LD_PRELOAD
    The key: HKLM\Software\Microsoft\Windows NT\CurrentVersion\Windows
    Note: may deprecated or disabled in recent version of Windows.
    
    Windows 7 - required DLL to be code-signed.

- SetWindowsHookEx()
    The SetWindowsHookEx API installs an application-defined hook procedure into a given hook chain.
    There are various supported hook chains (CBT, Journal, Window messages, keyboard, mouse, etc)
    Instructing OS to inject custom hook DLL into other process where it is relevant.
    Works when remote process import / use functionality from user32.dll

- Image File Execution Options (IFEO) key
    A registry key. Instruct OS to invoke a debugger when a given process is create, launch a given AppVerifier plugin, change process heap options, etc.

- Remote Threads
    Relies on creating remote threads into desired target process.
    The remote thread code would simply call LoadLibrary in target process' context.
    Variant:
        - CreateRemoteThread()
        - NTCreateThread()
        - QueueUserAPC()

- Implicitly tracking all process
    Relies on hook the process creation APIs such as kernel32.CreateProcess or lower APIs.
    By tracking the creation of other process, we have a chance to inject DLL into the new process.
    The idea:
        - enum all existing process
        - inject DLL hook into all of running process. Important so that injector gets up to speed with process that executed before injector was executed.
        - Hook k32!CreateProcessInternalW in each process. Or in deeper ntdll!NtCreateProcess
        - Injected DLL has to explicitly hook the process create API and do following:
            - Create child process suspended
            - Inject hook
            - Resume process.

- AppCompat shimming layer
    AppPatch.dll will reads shimming database (SDB), a custome format that describe various application compatibility shimming / patching capability.
        - memory search / replace -> patch code inside a given module when the module gets loaded
        - load/inject a DLL when a process is loaded. Can use wildcards too
        - fake API returns.
    
- Kernel drivers

