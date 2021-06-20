var  a: array [0..9] of real;
     s:real;
     i:integer;
begin
  writeln ('vvved');
  for i:=0 to 9 do readln (a[i]);
  s:=0;
  for i:=0 to 9 do s:=s+a[i];
  writeln ('summ', s);
  readln;
end.