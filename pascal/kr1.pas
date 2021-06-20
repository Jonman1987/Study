uses crt;
var  m: array [1..3,1..3] of integer;
    p: array [1..3] of integer;
     i, j, min: integer;
     kr: text;
begin
    randomize;
    write('Random massive m[3x3]:');
    writeln;
  for i:=1 to 3 do
   begin
    for j:=1 to 3 do
     begin
        m[i,j]:=random(100);
        write(m[i,j]:4); 
     end;
    writeln;
  end;
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
write('Massive p[3] of m[min]:');
for j:=1 to 3 do
begin
  write(p[j]:4);
end;  
    assign(kr, 'kr.txt');
    rewrite(kr);
    for i:=1 to 3 do
        for j:=1 to 3 do
        begin
            write(kr, m[i,j]);
            write(kr, ' ');
        end;
    writeln(kr);
    for j:=1 to 3 do
    begin
        write(kr, p[j]);
        write(kr, ' ');
    end;
close(kr);
readln;
end.
