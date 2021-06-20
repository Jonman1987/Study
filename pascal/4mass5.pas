uses crt;
const m: array [1..8] of integer = (262,294,330,350,392,440,494,523); 
var  i: integer; 
    ch: char; 
begin 
  writeln('Play on keyboard 1-8; 0 - exit'); 
  while true do 
  begin 
    ch:=readkey; 
    case ch of 
     #49: i:=1; 
     #50: i:=2; 
     #51: i:=3;
     #52: i:=4;
     #53: i:=5;
     #54: i:=6;
     #55: i:=7;   
     #56: i:=8; 
     #48: halt; 
    end; 
   sound(m[i]); 
   delay(1000); 
   nosound; 
  end; 
end.