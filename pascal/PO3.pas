uses crt;

Label M1;

const Max = 10;

var str1, m: string;
    i: integer;
    stack: array [1..10] of integer;
    a, b: integer;
    tos: integer;
    f1: file;
    x: char;

procedure Push(i:integer);
    begin
        if tos >= MAX then Writeln('Stack full') else
            begin
                stack[tos] :=i;
                tos := tos+1;
            end;
    end;

function Pop:integer;
    begin
        tos := tos-1;
        if tos < 1 then 
            begin
                Writeln('Stack underflow');
                tos := tos+1;
                Pop := 0;
            end
        else Pop := stack[tos];
    end;

begin
M1: Write('Select name of the file wich have type of *.txt: ');
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
                        writeln('Name of file is not selected');
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
                                                    readln(f1,x);
                                                    val(x, a, b);
                                                    write(a);
                                                    
                                                    
                                                        stack[tos]:=a;
                                                        tos:=tos+1;
                                                        
                                                end;
                                        writeln;
                                            for i:=1 to (tos-1) do
                                                write(stack[i]);
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
readln;
end.