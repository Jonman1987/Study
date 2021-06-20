uses crt;
var  m: array [1..3,1..3] of integer;
    p: array [1..3] of integer;
     i, j, min: integer;
     kr: text;
begin
    assign(kr, 'kr.txt');
    rewrite(kr);
    randomize;
    write('Random massive m[3x3]:');
    writeln;
  for i:=1 to 3 do
   begin
    for j:=1 to 3 do
     begin
        m[i,j]:=random(100);
        write(m[i,j]:4);
        write(kr, m[i,j]);
        write(kr, ' ');
     end;
     writeln(kr);
    writeln;
  end;
  close(kr);
  for j:=1 to 3 do
Begin
    min:=m[1,j];
    for i:=1 to 3 do
    begin
        if m[i,j] < min then min:=m[i,j];
    end;
p[j]:=min;
end;
writeln;
writeln;
assign(kr, 'kr.txt');
append(kr);
writeln(kr);
write('Massive p[3] of m[min]:');

for j:=1 to 3 do
begin
  write(p[j]:4);
  write(kr, p[j]);
        write(kr, ' ');
end;  
readln;
close(kr);
end.
