{
Simple DLL creation with Pascal.

Compilation:
    (freepascal)
    $ fpc hello.pas

run:
    rundll32 hello.dll,world
}

library hello;

{$mode objfpc}{$H+}

uses
    Classes,
    SysUtils,
    Windows;

function magic : Int64; stdcall;
begin 
    result := 135;
end;

procedure world; export;
begin
    MessageBox(0,PChar('This is a message'), PChar('Title'), mb_ok)
end;

exports magic, world;

begin
end.


