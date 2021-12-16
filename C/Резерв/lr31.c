#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>


struct university {char surname[10]; char sex[2]; int year; int height;} t1;
struct university1 {char surname[10]; char sex[2]; int year; int height;} t2;

//-----------------------------------------------------

void input(FILE *tf) // функция ввода в новый файл

{ 
  char ch;
  ch = 'n';

  tf=fopen("file1.dat","wb"); // открытие бинарного файла для записи
  system("clear");

  printf("\n Ввод данных спортсменов\n");

  do

  { 
    system("clear");
    printf("\n Фамилия: "); fflush(stdout); scanf("%s",t1.surname);

    printf(" Пол (m/f): "); fflush(stdout); scanf("%s",&t1.sex);

    printf(" Год рождения: "); fflush(stdout); scanf("%i",&t1.year);

    printf(" Рост: "); fflush(stdout); scanf("%i",&t1.height);

    fwrite(&t1,sizeof(t1),1,tf); // запись в файл одной структуры t1

    printf("\n Закончить? y/n ");
    fflush(stdout);

    scanf("%s", &ch);
    fflush(stdout);
  }

  while (ch != 'y');

  fclose(tf);

}

//-----------------------------------------------------

void look(FILE *tf)

{ 
  int i;
  char h;
  system("clear");

  tf=fopen("file1.dat","r"); // открытие бинарного файла для чтения

  i=1;

  fread(&t1,sizeof(t1),1,tf); // чтение из файла одной структуры t1

  while (!feof(tf))

  {  
    printf("\n Номер: %3d | Фамилия: %10s | Пол: %2s | Год рождения: %5d | Рост: %4d", i, t1.surname, t1.sex, t1.year, t1.height);
    fflush(stdout);

     fread(&t1,sizeof(t1),1,tf);

     i++;
     }
     printf("\n\n\n Введите любой символ для выхода:");
     fflush(stdout);
     scanf("%s", &h);
}

//-----------------------------------------------------

void addition(FILE *tf)

{ 
  char ch1;

  tf=fopen("file1.dat","a"); // открытие бинарного файла для добавления

  system("clear");

  printf("\n Ввод данных о спортсменах \n");
  fflush(stdout);

  do

  { 
    system("clear");
    printf("\n Фамилия: "); fflush(stdout); scanf("%s", t1.surname);

    printf(" Пол (m/f): "); fflush(stdout); scanf("%s",&t1.sex);

    printf(" Год рождения: "); fflush(stdout); scanf("%i",&t1.year);

    printf(" Рост: "); fflush(stdout); scanf("%i",&t1.height);


    fwrite(&t1,sizeof(t1),1,tf);

    printf(" Закончить? y/n ");
    fflush(stdout);

    scanf("%s", &ch1);
    fflush(stdout);

   }

  while (ch1 != 'y');

  fclose(tf);

}

//----------------------------------------------------- нужно доделать поиск

void find(FILE *tf)

{ 
char h2;
system("clear");
  tf=fopen("file1.dat","r"); // открытие бинарного файла для чтения

  fread(&t1,sizeof(t1),1,tf); // чтение из файла одной структуры t1
strcpy(t2.surname, t1.surname);
    strcpy(t2.sex, t1.sex);
    t2.year = t1.year;
   t2.height = t1.height;
  while (!feof(tf))

  { 
    
    fread(&t1,sizeof(t1),1,tf);
if (t1.height > t2.height)
{
  strcpy(t2.surname, t1.surname);
    strcpy(t2.sex, t1.sex);
    t2.year = t1.year;
    t2.height = t1.height;
}
     
     }
 printf("\n Самый высокий спортсмен в базе данных: \n\n");
     fflush(stdout);
     printf("\n Фамилия: %10s | Пол: %2s | Год рождения: %5d | Рост: %4d", t2.surname, t2.sex, t2.year, t2.height);
    fflush(stdout);
    printf("\n\n\n Введите любой символ для выхода:");
     fflush(stdout);
     
     scanf("%s", &h2);
}

//-----------------------------------------------------

int main()
{ 
  char c, d;
  FILE *tf;
system("clear");

while(1)

{
  system("clear");
    printf("\n 1 – новый файл\n");
    fflush(stdout);

    printf(" 2 – просмотр файла\n");
    fflush(stdout);

    printf(" 3 – добавление в файл\n");
    fflush(stdout);

    printf(" 4 – поиск\n");
    fflush(stdout);

    printf(" 0 - выход\n");
    fflush(stdout);

    printf("\nВведите пункт меню: ");
    fflush(stdout);

    scanf("%c", &c);

    
    switch (c)

    { 
      case '1': input(tf); break;

      case '2': look(tf); break;

      case '3': addition(tf); break;

      case '4': find(tf); break;

      case '0': return 0;

      default : printf(" неверный режим");
      fflush(stdout); 

    }
  }
}