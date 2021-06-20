program four_function_calc;
const
  MAX = 10;
var
  stack:array [1..100] of integer;
  tos:integer; 
  a, b:integer;
  err_code:integer;
  s:string[80];
  number_str:string[30];
  i:integer;
  pos:integer;
  number:real;

// =================================================================

procedure Push(i:integer);
begin
  if tos >= MAX then Writeln('Stack full') else
  begin
    stack[tos] :=i;
    tos := tos+1;
  end;
end;{Push}

// =================================================================

function Pop:integer;
begin
  tos := tos-1;
  if tos < 1 then 
  begin
    Writeln('Stack underflow');
    tos := tos+1;
    Pop := -9999;
  end
  else Pop := stack[tos];
end;{ Pop }

// =================================================================

function IsDigit(c:char):boolean;
begin
  if (Ord(c) >= Ord('0')) and (Ord(c) <= Ord('9'))
  then
    IsDigit := true
  else
    IsDigit := false;
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
    Writeln('Param ', i, ': ', ParamStr(i));
  
  s := '124 17 37 + *';

  Writeln('string: ', '"', s, '" ', '(length: ', Length(s), ')');

  for pos := 1 to Length(s) do
  begin
    if IsDigit(s[pos]) 
    then
      Writeln(s[pos], ' - is digit')
    else
      Writeln(s[pos], ' - is not digit');
  end;

  Writeln();
  Writeln('---------------------------------------------------------------------');
  Writeln();

  number_str := '';
  pos := 1;

  for i := 1 to Length(s) do
  begin
    if IsDigit(s[i]) then
      SaveDigit(s[i])
    else
      if Length(number_str) > 0 then
        ConvertNumberString; // сделать функцией возращающей число которое будем Push'ать
      

  end;

  








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