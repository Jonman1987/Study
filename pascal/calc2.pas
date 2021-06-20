program four_function_calc;
const
  MAX = 10;
var
  stack:array [1..100] of real;
  tos:integer; 
  a, b:integer;
  err_code:integer;
  s :string[80];
  sss: string[20];
  nameparam: array[0..$FF] of string;
  number_str:string[30];
  i:integer;
  pos:integer;
  number, vozvrat:real;
  f1: text;

procedure Push(i:real);
begin
  if tos >= MAX then Writeln('Stack full') else
  begin
    stack[tos] :=i;
    tos := tos+1;
  end;
end;{Push}

//Данная функция проверяет символ и присваивает ему код
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
                        IsDigit := 11;
end;

// =================================================================

procedure SaveDigit(digit:char);
begin
  number_str := number_str + digit;
  pos := pos + 1;
  Writeln('Add symbol ', s[i], ' to number_str ', '(', number_str, ')');
end;

// =================================================================

function ConvertNumberString:real;
var 
  number:real;
begin
  Val(number_str, number, err_code);
  number_str := '';
  pos := 1;
  Writeln('Converted number: ', number:8:2);
  ConvertNumberString := number;
end;

begin

  Writeln('Parameters count: ', ParamCount);

  for i:= 1 to ParamCount do
  begin
    Writeln('Param ', i, ': ', ParamStr(i));
  end;

  assign(f1, ParamStr(1));
  reset(f1);
    while not eof(f1) do
  read(f1,sss);
  writeln(sss);
  //s := '1 sin 2 cos +';
  s:=sss;
  Writeln('string: ', '"', s, '" ', '(length: ', Length(s), ')');

  for pos := 1 to Length(s) do
  begin
    if IsDigit(s[pos]) = 1
    then
      Writeln(s[pos], ' - is digit ', 'code: ', IsDigit(s[pos]))
    else
      if IsDigit(s[pos]) = 2 then
        Writeln(s[pos], ' - is "+" ', 'code: ', IsDigit(s[pos]))
        else
          if IsDigit(s[pos]) = 3 then
          Writeln(s[pos], ' - is "-" ', 'code: ', IsDigit(s[pos]))
          else
            if IsDigit(s[pos]) = 4 then
            Writeln(s[pos], ' - is "*" ', 'code: ', IsDigit(s[pos]))
            else
              if IsDigit(s[pos]) = 5 then
              Writeln(s[pos], ' - is "/" ', 'code: ', IsDigit(s[pos]))
              else
                if IsDigit(s[pos]) = 0 then
                Writeln(s[pos], ' - is " " ', 'code: ', IsDigit(s[pos]))
  end;

  Writeln();
  Writeln('---------------------------------------------------------------------');
  Writeln();

  number_str := '';
  pos := 1;
  tos :=1;
stack[1]:=0;
  for i := 1 to Length(s) do
  begin
    if IsDigit(s[i]) = 1 then
      begin
      SaveDigit(s[i]);
      writeln(tos);
      end
    else
      if (Length(number_str) > 0) and (IsDigit(s[i]) = 0) then
        begin
        push(ConvertNumberString);
        
        end
        else
          if (IsDigit(s[i]) = 2) and (tos > 2) then
            begin
            writeln('Tos is: ', tos);
            writeln(stack[tos-1]:7:3);
            writeln(stack[tos-2]:7:3);
            writeln((stack[tos-2])+(stack[tos-1]):7:3);
            stack[tos-2]:=stack[tos-2]+stack[tos-1];
            stack[tos-1]:=0;
            writeln(stack[tos-2]:7:3);
            tos:=tos-1;
            end
          else
            if (IsDigit(s[i]) = 3) and (tos > 2) then
              begin
                writeln('Tos is: ', tos);
                writeln(stack[tos-1]:7:3);
                writeln(stack[tos-2]:7:3);
                writeln((stack[tos-2])-(stack[tos-1]):7:3);
                stack[tos-2]:=stack[tos-2]-stack[tos-1];
                stack[tos-1]:=0;
                writeln(stack[tos-2]:7:3);
                tos:=tos-1;
              end
              else
                if (IsDigit(s[i]) = 4) and (tos > 2) then
                  begin
                    writeln('Tos is: ', tos);
                    writeln(stack[tos-1]:7:3);
                    writeln(stack[tos-2]:7:3);
                    writeln((stack[tos-2])*(stack[tos-1]):7:3);
                    stack[tos-2]:=stack[tos-2]*stack[tos-1];
                    stack[tos-1]:=0;
                    writeln(stack[tos-2]:7:3);
                    tos:=tos-1;
                  end
                else
                  if (IsDigit(s[i]) = 5) and (tos > 2) then
                  begin
                    if stack[tos-1]<>0 then
                      begin
                        writeln('Tos is: ', tos);
                        writeln(stack[tos-1]:7:3);
                        writeln(stack[tos-2]:7:3);
                        writeln((stack[tos-2])/(stack[tos-1]):7:3);
                        stack[tos-2]:=stack[tos-2]/stack[tos-1];
                        stack[tos-1]:=0;
                        writeln(stack[tos-2]:7:3);
                        tos:=tos-1;
                      end
                    else writeln('Division by zero');
                  end
                  else
                    if (IsDigit(s[i]) = 6) and (tos > 1) then
                      begin
                        if (IsDigit(s[i+1]) = 7) then
                          if (IsDigit(s[i+2]) = 8) then
                            begin
                              writeln('Tos is: ', tos);
                              writeln(stack[tos-1]:7:3);
                              writeln(stack[tos-2]:7:3);
                              writeln((sin(stack[tos-1])):7:3);
                              stack[tos-1]:=sin(stack[tos-1]);
                              writeln(stack[tos-1]:7:3);
                            end;
                      end
                    else
                      if (IsDigit(s[i]) = 9) and (tos > 1) then
                        begin
                        if (IsDigit(s[i+1]) = 10) then
                          if (IsDigit(s[i+2]) = 6) then
                            begin
                              writeln('Tos is: ', tos);
                              writeln(stack[tos-1]:7:3);
                              writeln(stack[tos-2]:7:3);
                              writeln((cos(stack[tos-1])):7:3);
                              stack[tos-1]:=cos(stack[tos-1]);
                              writeln(stack[tos-1]:7:3);
                            end;
                        end
                        else writeln('Its not math simbol');
  end;
  tos:=1;
  writeln();
  for i:=1 to tos do
    writeln(i,' ',stack[i]:7:3);









  // tos := 1;
  // Writeln('For Function Calculator');
  // repeat
  //   Write(': '); 
  //   Readln(s);
  //   Val(s, a, b); 
  //   if (b=0) and ((Length(s)>1) or (s[1]<>'-')) 
  //     then
  //       Push(a) 
  //     else
  //       case s[1] of
  //     '+' : begin
  //             a := Pop;
  //             b := Pop;
  //             Writeln(a+b);
  //             Push(a+b);
  //           end;
  //     '-' : begin
  //             a := Pop;
  //             b := Pop;
  //             Writeln(b-a);
  //             Push(b-a);
  //           end;
  //     '*' : begin
  //             a := Pop;
  //             b := Pop;
  //             Writeln(a*b);
  //             Push(a*b);
  //           end;
  //     '/' : begin
  //             a := Pop;
  //             b := Pop;
  //             if a=0 then Writeln('divide by zero')
  //             else
  //             begin
  //               Writeln(b div a);
  //               Push(b div a);
  //             end;
  //           end;
  //     '.' : begin
  //             a := Pop;
  //             Writeln(a);
  //             Push(a);
  //           end;
  //     end;
  // until UpCase(s[1])='G'
end.