{
Simple client to use unmanaged.dll

Compile:
    $ fpc client.pas

Run: 
    $ client.exe
}

program client;

{$mode objfpc}{$H+}

uses SysUtils;

{
We need to match the calling conventions used by the DLL.

In this case, we assume that the calling convention is stdcall
}

function  calculate(n : Int64) : Int64; stdcall; external 'unmanaged.dll' name 'calculate';

procedure world; external 'unmanaged.dll' name 'world';

var 
    result : integer;

begin 
    { Call the world() }
    world();

    { Call the calculate() }
    result := calculate(0);
    writeln('The result of calculate(0) is ' + IntToStr(result));
end.