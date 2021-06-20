uses crt;
var x,y,i: integer;
    ch: char;
procedure Put(x,y,i,col: integer);
begin
  textbackground(col);
  gotoxy(x+i*3,y);
  write(' ',i,' ');
  gotoxy(x+i*3+1,y);
end;
begin
  textmode(3);
  clrscr;
  y:=13; x:=25;
  for i:=0 to 9 do put(x,y,i,1);
  i:=0; put(x,y,i,2);
  repeat
    ch:=readkey;
    put(x,y,i,1);
    if ch = #75 then dec(i);
    if ch = #77 then inc(i);
    if i<0 then i:=9;
    if i>9 then i:=0;  
    put(x,y,i,2);
  until ch=#27; {esc}
  textmode(3);
end.