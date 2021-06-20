uses crt;
var  m: array [1..3,1..3] of integer;
    p: array [1..3] of integer;
     i, j, min: integer;
     kr: text;
 const razmer_massiva=3;    
type mas=array [1..razmer_massiva, 1..razmer_massiva] of integer;
type mas1=array [1..razmer_massiva] of integer;
procedure Minel(var n:mas);
var i, j, min: integer;
    s:mas1;
begin
assign(kr, 'kr.txt'); // реализация дозаписи в старый файл нового массива сформированного из минимальных элементов первоначального
    append(kr);
    write(kr, 'Update massive from min elements:');
    writeln(kr);
    Close(kr);
write('  ');
 for j:=1 to 3 do
    Begin
    min:=n[1,j];
    for i:=1 to 3 do
        if n[i,j] < min then min:=n[i,j];
    s[j]:=min;
    write(s[j]);
    write('  ');
    assign(kr, 'kr.txt'); // реализация дозаписи в старый файл нового массива сформированного из минимальных элементов первоначального
    append(kr);
    write(kr, '  ');
    write(kr, s[j]);
    write(kr, '  ');
    close(kr);
    end; 
end; 
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
   assign(kr, 'kr.txt'); //Реализация записи основного массива
    rewrite(kr);
    write(kr, 'Random massive m[3x3]:');
    writeln(kr);
    for i:=1 to 3 do
    begin
        for j:=1 to 3 do
        begin
            write(kr, ' ');
            write(kr, m[i,j]);
            write(kr, ' ');
        end;
    writeln(kr);
    end;
close(kr);
  write(' ');
  write('Update massive from min elements:');
  writeln;
 Minel(m);
writeln;
readln;
end.
