var  op: char;
      x,y,r: real;
      err: boolean;

begin
   err:=false;
   write('Введите х, у'); readln(x,y);
   write('Определите операцию'); readln(ор);
   case op of
     '+': r:=x+y;
     '-': r:=x-y;
     '*': r:=x*y;
     '/': r:=x/y;
    else err:=true;
   end;
  if err then 
     writeln('Неверно заданная операция')
  else writeln(х, ор, у, '=', r);
end.
