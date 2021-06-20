uses crt;
var s, x: real;
begin
  s:=0; x:=0.2;
  repeat
    s:=s+x;
    x:= (abs(x)+0.3)*(abs(x)/(-x));
  until (x>2.0) or (x<-2.0);
  writeln('S = ', s:8:3);
  Delay(5000);
end.