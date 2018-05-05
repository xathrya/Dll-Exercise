{
Load library on runtime.
Use Win32 API to load the library and then get function address.

Explicit linking.

Compile:
    $ fpc client.pas

Run: 
    $ client.exe
}

program client;

{$mode objfpc}{$H+}

uses dynlibs, SysUtils, Windows;

{
Every function has type signature which gives several information
such as:
	- type of return value
	- number of arguments
	- type of each arguments.

The GetProcAddress() API only return the address of function.
The address would be a function pointer.
It is the responsible of user to cast it for correct type signature. 
}

type
    TWorld     = procedure;
    TCalculate = function(n : Int64) : Int64;
    
var 
    result    : integer;
    world     : TWorld;
    calculate : TCalculate;
    handle    : TLibHandle;

begin 
    handle := LoadLibrary('unmanaged.dll');
    if handle = NILHandle then 
    begin 
        MessageBox(0,PChar('Cannot locate the DLL file'), PChar('Error'), mb_ok);
        exit;
    end;

    Pointer(world)     := GetProcAddress(handle, 'world');
    Pointer(calculate) := GetProcAddress(handle, 'calculate');

    if (@world = nil) or (@calculate = nil) then 
    begin 
		MessageBox(NULL, PChar('Could not locate the function'), PChar('Error'), mb_ok);
		exit;
    end;

    { Call the function }
    { Call the world() }
    world();

    { Call the calculate(0) }
    result := calculate(0);
    writeln('The result of calculate(0) is ' + IntToStr(result));

    UnLoadLibrary(handle);
end.