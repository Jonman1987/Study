var     i: integer;
        s: real;
begin
        i:=1; s:=0;
        while  i<=100 do
        begin
                s:=s+1/i;
                i:=i+1;
        end;
        writeln('S', s:7:3);
readln;
end.