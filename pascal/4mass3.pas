var   a: array [1..5,1..5] of integer;
      sum,i,j: integer;
begin
  for i:=1 to 5 do
  begin
    for j:=1 to 5 do
    begin
       a[i,j]:=0-(i*j);
       write(a[i,j]:4);
    end;
    writeln;
  end;
  writeln;
  for j:=1 to 5 do
  begin
      sum:=0;
      for i:=1 to 5 do
          sum:=sum+ a[i,j];
      writeln('summa ',j,'-go stolbtsa = ',sum);
  end;
readln;
end.
