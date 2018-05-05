{
Simple DLL creation with Pascal.

Compilation:
    (freepascal)
    $ fpc hello.pas

run:
    rundll32 hello.dll,world
}

library unmanaged;

{$mode objfpc}{$H+}

uses
    Classes,
    SysUtils,
    Windows;

function calculate(n : Int64) : Int64; stdcall;
begin 
    result := n + 135;
end;

procedure world; export;
begin
    MessageBox(0,PChar('This is a message'), PChar('Title'), mb_ok)
end;

exports calculate, world;

begin
end.


