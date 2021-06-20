uses crt;

Label M1, M2, M3;

const Max = 10;

var str1, m: string;
    i: integer;
    stack: array [1..10] of real;
    a, c: real;
    b, d: integer;
    tos: integer;
    f1: file of char;
    x: char;

begin
c:=1;
d:=1;
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
                                    read(f1,x);
                                        if (x = '-') or (x = '+') or (x = '/') or (x = '*') then
                                            writeln('Error: first simbol is: ', x)
                                        else
                                            begin
                                            read(f1,x);
                                            if (x = '-') or (x = '+') or (x = '/') or (x = '*') then
                                            writeln('Error: second simbol is: ', x)
                                            
                                            else
                                        begin
                                            close(f1);
                                            assign(f1, str1);
                                            reset(f1);
                                            tos:=0;
                                            a:=0;
                                            writeln;
                                            writeln('String from file:');
                                            while not eof(f1) do
                                                begin
                                                    tos:=tos+1;
                                                    read(f1,x);
                                                    val(x, a, b);
                                                    write(x);
                                                    write(' ');
                                                        if (x = '-') and (tos>2) then
                                                            begin
                                                                stack[tos-2]:=stack[tos-2]-stack[tos-1];
                                                                stack[tos-1]:=0;
                                                                tos:=tos-2;
                                                            end
                                                        else
                                                            if (x = '+') and (tos>2) then
                                                                begin
                                                                    stack[tos-2]:=stack[tos-2]+stack[tos-1];
                                                                    stack[tos-1]:=0;
                                                                    tos:=tos-2;
                                                                end
                                                            else
                                                                if (x = '*') and (tos>2) then
                                                                    begin
                                                                        stack[tos-2]:=stack[tos-2]*stack[tos-1];
                                                                        stack[tos-1]:=0;
                                                                        tos:=tos-2;
                                                                    end
                                                                else
                                                                    if (x = '/') and (tos>2) then
                                                                        begin
                                                                            if stack[tos-1]=0 then
                                                                                begin
                                                                                    writeln;
                                                                                    goto M2
                                                                                end
                                                                            else
                                                                                begin
                                                                                    stack[tos-2]:=stack[tos-2]/stack[tos-1];
                                                                                    stack[tos-1]:=0;
                                                                                    tos:=tos-2;
                                                                                end;
                                                                        end
                                                                    else
                                                                        
                                                                            if tos<2 then//я остановился тут
                                                                            stack[tos]:=a
                                                                            else goto M3
                                                                        
                                                end;
                                        writeln;
                                            for i:=1 to Max do
                                                write(stack[i]:7:3, ' ');
                                        writeln;
                                        
                                        write('Result: ', stack[1]:7:3);
                                        end; 
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
if d<>1 then
    M3: writeln('Error: need more numbers');
readln;
end.