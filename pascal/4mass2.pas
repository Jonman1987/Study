const  n=10;
 var    a: array [1..n] of integer;
        i: integer;
        yes: boolean;
begin
  writeln('Vvedite elementi massiva');
  for i:=1 to n do
   begin
     write('a[',i,']=');
     readln(a[i]);
  end;
  yes:=false;
  for i:=1 to n do 
   begin
    if a[i]>=0 then continue; { continue – возврат на заголовок цикла}
    writeln('pervoe otritsatlnoe chislo = ', a[i]);
    yes:=true;
    break; { break – окончание выполнения цикла и переход к следующему оператору
             программы, в данном примере – к условному оператору if } 
  end;
  if not yes then writeln('Otritsatelnikh chisel net');
readln;
end.
