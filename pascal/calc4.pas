program polsk_calc;
Label m1, m2, m3, m4, m5, m6, m7;
const
  MAX = 10;
var
  stack:array [1..100] of real;
  tos:integer; 
  a, b, c, d, e, f, g, h, code0, code1, code_more, code_trig:integer;
  s :string[80];
  err_code:integer;
  number_str:string[30];
  i:integer;
  pos:integer;
  f1: text;

procedure Push(i:real);
begin
  if tos >= MAX then Writeln('Stack full') else
  begin
    stack[tos] :=i;
    tos := tos+1;
  end;
end;

function IsDigit(c:char):integer;
begin
  if (Ord(c) >= Ord('0')) and (Ord(c) <= Ord('9'))
  then
    IsDigit := 1
  else
    if Ord(c) = Ord('+') 
    then
      IsDigit := 2
    else
      if Ord(c) = Ord('-') 
      then
        IsDigit := 3
      else
        if Ord(c) = Ord('*') 
        then
          IsDigit := 4
        else
          if Ord(c) = Ord('/') 
          then
            IsDigit := 5
          else
            if Ord(c) = Ord(' ') 
            then
              IsDigit := 0
            else
              if Ord(c) = Ord('s') 
              then
                IsDigit := 6
              else
                if Ord(c) = Ord('i') 
                then
                  IsDigit := 7
                else
                  if Ord(c) = Ord('n') 
                  then
                    IsDigit := 8
                  else
                    if Ord(c) = Ord('c') 
                    then
                      IsDigit := 9
                    else
                      if Ord(c) = Ord('o') 
                      then
                        IsDigit := 10
                      else
                        if Ord(c) = Ord('.') 
                      then
                        IsDigit := 1
                        else
                        IsDigit := 11;
end;

procedure SaveDigit(digit:char);
begin
  number_str := number_str + digit;
  pos := pos + 1;
end;

function ConvertNumberString:real;
var 
  number:real;
begin
  Val(number_str, number, err_code);
  number_str := '';
  pos := 1;
  ConvertNumberString := number;
end;

begin
if ParamCount=0 then 
    begin
        d:=2;
        goto m3;
    end
else

  assign(f1, ParamStr(1));
    h:=1;
    
    {$I-}
        reset(f1);
    {$I+}
  if IOResult <> 0 then 
  Begin
  goto m7;
  e:=2;
  end;
    
  writeln('String from file: ');
    while not eof(f1) do
    read(f1,s);
    writeln(s);
    number_str := '';
    pos := 1;
    b:=1;
    c:=1;
    d:=1;
    f:=1;
    tos :=1;
    stack[1]:=0;
code0:=0;
code1:=0;
code_more:=0;
code_trig:=0;

for pos := 1 to Length(s) do
  begin
    if IsDigit(s[pos]) = 1 then
        begin
            if IsDigit(s[pos+1]) = 0 then
                code1:=code1+1;
        end
    else
      if (IsDigit(s[pos]) = 2) or (IsDigit(s[pos]) = 3) or (IsDigit(s[pos]) = 4) or (IsDigit(s[pos]) = 5) then
            code_more:=code_more+1
        else
                if IsDigit(s[pos]) = 0 then
                    code0:=code0+1
                else
                    if (IsDigit(s[pos]) = 6) or (IsDigit(s[pos]) = 9) then
                        code_trig:=code_trig+1;
  end;

if (code_more = 0) and (code_trig = 0) then
    begin
        goto m5;
        f:=2;
    end
else if (code1 - code_more <> 1) and (code_trig = 0) then
    begin
        goto m6;
        g:=2;
    end;
    number_str := '';
    pos := 1;
    tos :=1;
    stack[1]:=0;
  for i := 1 to Length(s) do
  begin
    if IsDigit(s[i]) = 1 
    then
      SaveDigit(s[i])
    else
      if (Length(number_str) > 0) and (IsDigit(s[i]) = 0) 
      then
        push(ConvertNumberString)
        else
          if (IsDigit(s[i]) = 2) and (tos > 2) then
            begin
            stack[tos-2]:=stack[tos-2]+stack[tos-1];
            stack[tos-1]:=0;
            tos:=tos-1;
            end
          else
            if (IsDigit(s[i]) = 3) and (tos > 2) then
              begin
                stack[tos-2]:=stack[tos-2]-stack[tos-1];
                stack[tos-1]:=0;
                tos:=tos-1;
              end
              else
                if (IsDigit(s[i]) = 4) and (tos > 2) then
                  begin
                    stack[tos-2]:=stack[tos-2]*stack[tos-1];
                    stack[tos-1]:=0;
                    tos:=tos-1;
                  end
                else
                  if (IsDigit(s[i]) = 5) and (tos > 2) then
                  begin
                    if stack[tos-1]<>0 then
                      begin
                        stack[tos-2]:=stack[tos-2]/stack[tos-1];
                        stack[tos-1]:=0;
                        tos:=tos-1;
                      end
                    else 
                        begin
                            b:=2;
                            goto m1;
                        end;
                  end
                  else
                    if (IsDigit(s[i]) = 6) and (tos > 1) then
                      begin
                        if (IsDigit(s[i+1]) = 7) then
                          if (IsDigit(s[i+2]) = 8) then
                            begin
                              stack[tos-1]:=sin(stack[tos-1]);
                            end;
                      end
                    else
                      if (IsDigit(s[i]) = 9) and (tos > 1) then
                        begin
                        if (IsDigit(s[i+1]) = 10) then
                          if (IsDigit(s[i+2]) = 6) then
                            begin
                              stack[tos-1]:=cos(stack[tos-1]);
                            end;
                        end
                        else 
                            if (IsDigit(s[i]) = 9) and (tos = 1) then
                                begin
                                    e:=2;
                                    goto m4;
                                end
                            else
                            if IsDigit(s[i]) = 11 
                            then 
                                begin
                                    goto m2;
                                    c:=2
                                end;
  end;
  tos:=1;
  writeln();
  if (b=1) and (c=1) then
  for i:=1 to tos do
    writeln('Result is: ',stack[i]:7:2);
if b=2 then
m1: writeln('Division by zero');
if c=2 then
m2: writeln('Its not math symbol');
if d=2 then
m3: writeln('Parameters not found');
if e=2 then
m4: writeln('Have not symbol for operation with Cos\Sin');
if f=2 then
m5: writeln('Have not operation');
if g=2 then
m6: writeln('Addition more numbers');
if h=2 then
m7: writeln('File not found');
writeln('Press "Enter" for exit');
readln();
end.