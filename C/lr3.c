#include <stdio.h>

#include <conio.h>

#include <string.h>

#include <stdlib.h>

struct tov {char name[10]; float c; int kol;} t1;

void input(FILE *); // создание нового файла

void print(FILE *); // просмотр файла

void app(FILE *); // добавление в файл

void find(FILE *); // поиск и изменение

int main()

{ char c;

  FILE *tf;

  while (1)

   {
    system("clear");

    puts(" 1 – новый файл");

    puts(" 2 – просмотр файла");

    puts(" 3 – добавление в файл");

    puts(" 4 – поиск и изменение");

    puts(" 0 - выход");

    scanf("%s",c);

    switch(c)

    { case '1':input(tf);break;

      case '2':print(tf);break;

      case '3':app(tf);break;

      case '4':find(tf);break;

      case '0':return 0;

      default : puts(" неверный режим");

    }

  }

}

void input(FILE *tf)

{ char ch;

  tf=fopen("file1.dat","wb"); // открытие бинарного файла для записи

  system("clear");

  printf("\n Ввод товаров\n");
  fflush(stdout);

  do

  { printf("\n название: "); scanf("%s",t1.name);
  fflush(stdout);

    printf(" цена: "); scanf("%f",&t1.c);
    fflush(stdout);

    printf(" количество: "); scanf("%d",&t1.kol);
    fflush(stdout);

    fwrite(&t1,sizeof(t1),1,tf); // запись в файл одной структуры t1

    printf("\n Закончить? y/n ");
    fflush(stdout);

    ch=getch();

  }

  while (ch != 'y');

  fclose(tf);

}

void print(FILE *tf)

{ int i;

  system("clear");

  tf=fopen("file1.dat","rb"); // открытие бинарного файла для чтения

  i=1;

  fread(&t1,sizeof(t1),1,tf); // чтение из файла одной структуры t1

  while (!feof(tf))

  {  printf("\n %3d tovar %10s cena %6.2f kolic %4d", i, t1.name, t1.c, t1.kol);
fflush(stdout);

     fread(&t1,sizeof(t1),1,tf);

     i++;

  }

  getch();

}

void app(FILE *tf)

{ char ch;

  tf=fopen("file1.dat","ab"); // открытие бинарного файла для добавления

  system("clear");

  printf("\n Ввод товаров \n");
  fflush(stdout);

  do

  { printf("\n название: "); scanf("%s", t1.name);
  fflush(stdout);

    printf(" цена: "); scanf("%f",&t1.c);
    fflush(stdout);

    printf(" количество: "); scanf("%d",&t1.kol);
    fflush(stdout);

    fwrite(&t1,sizeof(t1),1,tf);

    printf(" Закончить? y/n ");
    fflush(stdout);

    ch=getch();

   }

  while (ch != 'y');

  fclose(tf);

}

void find(FILE *tf)

{ char c, tov[10];

  long int i;

  tf=fopen("file1.dat","rb+"); // открытие бинарного файла для чтения и записи

  system("clear");

  puts(" Название искомого товара: ");

  gets(tov);

  fread(&t1,sizeof(t1),1,tf);

  while (!feof(tf))

  { if (strcmp(t1.name,tov)==0)

      { printf(" tovar %10s cena %6.2f kolic %d",t1.name,t1.c,t1.kol);
      fflush(stdout);

        printf("\n изменить? y/n ");
        fflush(stdout);

        c=getch();

        if (c=='y')

          { printf("\n количество: "); scanf("%d",&t1.kol);
        fflush(stdout);

            printf("\n цена: "); scanf("%f",&t1.c);
            fflush(stdout);

            i=sizeof(t1);

            fseek(tf, -i, 1); // возврат на sizeof(t1) байт назад

            fwrite(&t1,sizeof(t1),1,tf);//запись изменённой структуры

         }

      }

   fread(&t1,sizeof(t1),1,tf);

  }

 fclose(tf);

}