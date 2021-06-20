uses crt;
type book = record
        name: string;
        autor: string;
        year: string;
        str: string;
    end;
var   i, n: integer;
        god: string;
      ch: char;
      b: array [1..1000] of book;
begin
  i:=0;
  repeat
    inc(i);
    with b[i] do begin
      write('nazvanie:'); readln(name);
      write('avtor:'); readln(autor);
      write('god:'); readln(year);
      write('kolichestvo strants:'); readln(str);
    end;
    write('eshe vvodit? Y/N'); readln(ch);
    writeln; n:=i;
  until (upcase(ch)='N');
  repeat{поиск в каталоге}
    write('vvedite god'); readln(god);
    for i:=1 to n do
        if b[i].year=god then writeln(b[i].name, b[i].autor, b[i].year, b[i].str);
    writeln('Prodolgit poisk? Y/N'); readln(ch);
  until (upcase(ch)='N');
end.
