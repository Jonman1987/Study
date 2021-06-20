uses crt;
const razmer_massiva=20;
type mas=array [1..razmer_massiva] of integer;
var t:mas;
procedure Preobrazovanie(var a:mas);
var i,three:integer;
begin
three:=3;
for i:=1 to razmer_massiva do
begin
a[i]:=a[i] div three;
if a[i]<0 then
a[i]:=0;   
end;     
end;
function Sum(b:mas):integer;
var i,s:integer;
begin
    s:=0;
    for i:=1 to razmer_massiva do
    if b[i] mod 2=0 then
    s:=s+b[i];
    sum:=s;
end;
var i:integer;
begin
clrscr;
Randomize;
for i:=1 to razmer_massiva do
t[i]:=Random(51)-25;
for i:=1 to razmer_massiva do
write(t[i]:4);
readln;
writeln;
Preobrazovanie(t);
writeln;
writeln;
for i:=1 to razmer_massiva do
write(t[i]:4);
readln;
writeln;
write('Summa elementov = ',Sum(T)); 
readln;
end.