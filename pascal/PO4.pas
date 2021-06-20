uses crt;

Label M1, M2;

const Max = 10;

var str1, m: string;
    i: integer;
    stack: array [1..10] of integer;
    a, b, c: integer;
    tos: integer;
    f1: file of char;
    x: char;

begin
c:=1;
M1: Write('Enter the name of the file wich have type *.txt: ');
Readln(str1);
if ((str1[length(str1)] <> 't') or (str1[length(str1) - 1] <> 'x') or (str1[length(str1) - 2] <> 't') or (str1[length(str1) - 3] <> '.')) then
        begin
            writeln('File have not format TXT');
            writeln;
            GOTO M1;     
        end
        else
            begin
                if (str1[1] = '.') then
                    begin
                        writeln('Name of file is not entered');
                        writeln;
                        GOTO M1;
                    end
                    else 
                        begin
                            assign(f1, str1);
                            {$I-}
                            reset(f1);
                            {$I+}
                            if IOResult = 0 then
                                begin
                                    if length(str1) > 10 then
                                            writeln('stack overflow')
                                    else
                                        begin
                                            tos:=1;
                                            
                                            while not eof(f1) do
                                                begin
                                                    read(f1,x);
                                                    val(x, a, b);
                                                    write(x);
                                                        if x = '-' then
                                                            begin
                                                                stack[tos-2]:=stack[tos-2]-stack[tos-1];
                                                                tos:=tos-1;
                                                            end
                                                        else
                                                            if x = '+' then
                                                            begin
                                                                stack[tos-2]:=stack[tos-2]+stack[tos-1];
                                                                tos:=tos-1;
                                                            end
                                                            else
                                                                if x = '*' then
                                                                    begin
                                                                        stack[tos-2]:=stack[tos-2]*stack[tos-1];
                                                                        tos:=tos-1;
                                                                    end
                                                                else
                                                                    if x = '/' then
                                                                        begin
                                                                            if stack[tos-1]=0 then
                                                                                begin
                                                                                    writeln;
                                                                                    goto M2
                                                                                end
                                                                            else
                                                                                begin
                                                                                    stack[tos-2]:=stack[tos-2] div stack[tos-1];
                                                                                    tos:=tos-1;
                                                                                end;
                                                                        end
                                                                    else
                                                                        begin
                                                                            stack[tos]:=a;
                                                                            tos:=tos+1;
                                                                        end;
                                                end;
                                        writeln;
                                            for i:=1 to (Max) do
                                                write(stack[i]);
                                        writeln;
                                        write('Result: ', stack[1]);
                                        end;    
                                end
                            else
                                begin
                                    writeln('File not found');
                                    writeln;
                                    GOTO M1;
                                end;
                        end;
            end;
writeln; 
writeln;
if c <> 1 then
    M2: writeln('division by zero');
readln;
end.