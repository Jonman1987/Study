Uses crt;
Var  X, Y, a, c, b: Real;
Begin
  Write('Write number X and Y type of real:');
  Read(X,Y);
  a:=(ln(exp(1/(abs(X))*ln(Y)))*(sin(X)+exp(X+Y)));
  WriteLn ('A=', a:8:3); { вывод  результата}
  c:=0;
  b:=X-Y;
  if (b=0)  then c:=sqr(X)+sqr(Y)+sin(X)
    else if (b>0) and (b<=36) then
            c:=sqr(X-Y)+cos(X)
         else
           if (b<0) then c:=sqr(Y-X)+sin(X)/cos(X)
           else c:=0;
WriteLn ('c=', c:8:3);
delay(5000);
End.