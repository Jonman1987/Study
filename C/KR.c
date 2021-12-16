#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

struct predmet_ocenka
{
  char predmet[15];
  int ocenka1;
  int ocenka2;
  int ocenka3;
};

struct predmet_ocenka bally[3];

struct zapis 
{
  char surname[15];
  char name[15];
  char secondname[15];
  //struct predmet_ocenka bally[4];
};

struct predmet_ocenka t1;
struct zapis data;

struct spisok
{
  struct zapis data;
  struct spisok *prev;
  struct spisok *next;
};

struct spisok *head, *tail;

int ListAdd(struct spisok *added_element)
{
    if (head == NULL)
    {
        head = added_element;
    } else {
        added_element->next = head;
        added_element->prev = NULL;
        head->prev = added_element;
        head = added_element;
    }
}

void vvod()
{
  int i;
  char ch;
  system("clear");
  printf("\nВвод данных спортсменов\n");
  i=0;
  ch='n';
  do
  {
    system("clear");
    printf("\nФамилия: "); fflush(stdout); scanf("%s", data.surname);

    printf("Имя: "); fflush(stdout); scanf("%s", data.name);

    printf("Отчество: "); fflush(stdout); scanf("%s", data.secondname);

    printf("\nВвод данных оценок\n");

    /*for (i=0; i<4; i++)
    {
    printf("\nПредмет: "); fflush(stdout); scanf("%s", t1.predmet);
    printf("Оценка 1: "); fflush(stdout); scanf("%i", &t1.ocenka1);
    printf("Оценка 2: "); fflush(stdout); scanf("%i", &t1.ocenka2);
    printf("Оценка 3: "); fflush(stdout); scanf("%i", &t1.ocenka3);
    strcpy(bally[i].predmet, t1.predmet);
    bally[i].ocenka1 = t1.ocenka1;
    bally[i].ocenka2 = t1.ocenka2;
    bally[i].ocenka3 = t1.ocenka3;
    }*/

    ListAdd(*data);

    printf("\n Закончить? y/n ");
    fflush(stdout);

    scanf("%s", &ch);
    fflush(stdout);
  }
  while (ch != 'y');
}

void vivod()
{
  int i;
  
  system("clear");
  printf("\nФамилия: %15s | Имя: %15s | Отчество: %15s\n", data.surname, data.name, data.secondname);
  fflush(stdout);
  /*printf("\nДанные оценок\n");
  for (i=0; i<4; i++)
  {
     printf("\nПредмет: %15s | %i | %i | %i", bally[i].predmet, bally[i].ocenka1, bally[i].ocenka2, bally[i].ocenka3);
      fflush(stdout);
  }*/
}

void vihodvmenu()
{
  char ch1;

  printf("\n\nВведите любой символ для выхода в главное меню: ");
  fflush(stdout);
  scanf("%s", &ch1);
}



int main()
{ 
  char c;
  FILE *baza;

  system("clear");

while(1)
{
  	system("clear");

    printf("\n 1 – Новый список\n");
    fflush(stdout);

    printf(" 2 – Просмотр списка\n");
    fflush(stdout);

    printf(" 3 – Добавление в список новой записи\n");
    fflush(stdout);

    printf(" 4 – Поиск и корректировка записи в списке\n");
    fflush(stdout);

    printf(" 5 – Удаление записи из списка\n");
    fflush(stdout);

    printf(" 6 – Сохранить список в файл\n");
    fflush(stdout);

    printf(" 7 – Загрузить список из файла\n");
    fflush(stdout);

    printf(" 0 - Выход\n");
    fflush(stdout);

    printf("\nВведите пункт меню: ");
    fflush(stdout);

    scanf("%c", &c);

    switch (c)

    { 
      case '1': vvod(); fflush(stdout); break;

      case '2': vivod(); vihodvmenu(); fflush(stdout); break;

      case '3': printf("3"); fflush(stdout); break;

      case '4': printf("4"); fflush(stdout); break;

      case '5': printf("5"); fflush(stdout); break;

      case '6': printf("6"); fflush(stdout); break;

      case '7': printf("7"); fflush(stdout); break;

      case '0': return 0;

      default : printf(" неверный режим");
      fflush(stdout); 
    }
}
}