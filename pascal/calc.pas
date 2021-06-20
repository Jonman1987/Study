program four_function_calc;
const
  MAX = 10;
var
  stack:array [1..100] of integer;
  tos:integer; 
  a, b:integer;
  s:string[80];

procedure Push(i:integer);
begin
  if tos >= MAX then Writeln('Stack full') else
  begin
    stack[tos] :=i;
    tos := tos+1;
  end;
end;{Push}

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
end;{ Pop }

begin
  tos := 1;
  Writeln('For Function Calculator');
  repeat
    Write(': '); 
    Readln(s);
    Val(s, a, b); 
    if (b=0) and ((Length(s)>1) or (s[1]<>'-')) 
      then
        Push(a) 
      else
        case s[1] of
      '+' : begin
              a := Pop;
              b := Pop;
              Writeln(a+b);
              Push(a+b);
            end;
      '-' : begin
              a := Pop;
              b := Pop;
              Writeln(b-a);
              Push(b-a);
            end;
      '*' : begin
              a := Pop;
              b := Pop;
              Writeln(a*b);
              Push(a*b);
            end;
      '/' : begin
              a := Pop;
              b := Pop;
              if a=0 then Writeln('divide by zero')
              else
              begin
                Writeln(b div a);
                Push(b div a);
              end;
            end;
      '.' : begin
              a := Pop;
              Writeln(a);
              Push(a);
            end;
      end;
  until UpCase(s[1])='G'
end.