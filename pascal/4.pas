var x,y,z: real;
begin
        x:=-2; y:=3; z:=3.5;
        z:=x-2.5;
        y:=x-y+2*z;
        x:=x+y-2*z;
        x:=y-2*x;
        y:=x+2*y+z;
        z:=(x+y)*2;
        writeln('x=',x:7:3,' y=',y:7:3,' z=',z:7:3);
readln;
end.