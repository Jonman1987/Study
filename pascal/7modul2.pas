uses crt;
var  x,y,i: integer;
     ch: char;
procedure Put(x,y,i,col: integer);
begin
  gotoxy(x+i*3,y);
  write(' ',i,' ');
  gotoxy(x+i*3+1,y);
end;
begin
  textmode(3);
  clrscr;
  y:=13; x:=25;
  textbackground(1);
  for i:=0 to 9 do
  begin
    gotoxy(x+i*3,y);
    write(' ',i,' ');
  end; 
  i:=0;
  textbackground(2); 
  gotoxy(x+i*3,y);
  write(' ',i,' ');
  gotoxy(x+i*3+1,y);
  repeat
     
     
        ch:=readkey;
        textbackground(1);{}
        gotoxy(x+i*3,y);{стирает подсветку}
        write(' ',i,' ');{}
        if ch = #75 then dec(i);
        if ch = #77 then inc(i);
        if i<0 then i:=9;
        if i>9 then i:=0;
        textbackground(2);
        gotoxy(x+i*3,y); //подсвечивает другую цифру
        write(' ',i,' '); 
        gotoxy(x+i*3+1,y);
      
   until ch=#27; {esc}
   textmode(3);
end.
