#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int RandElem(int a)
{
	a = rand() % 100;
  return a;
}

struct spisok
{
  int value;
  struct spisok *prev;
  struct spisok *next;
};

struct spisok *head = NULL;
int spisCount=1;
int elements;

void setSpisok(struct spisok *a, int count1)
{
  int i;
  struct spisok *p = head;
  a->value = RandElem(count1);
}

int AddElementInBegin(struct spisok *added_element)
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

int AddElementInEnd(struct spisok *add_element)
{
    struct spisok *p = head;
    if (head == NULL)
    {
        head = add_element;

    } else {

        while (p->next != NULL)
        {
            p = p->next;
        }

        add_element->next = NULL;
        add_element->prev = p;
        p->next = add_element;
    }
}

void spisPrint(struct spisok *st)
{
    struct spisok *p = head;

    while(p)
    {
    printf("%d ", st->value);
    p=p->next;
    }
}

void CreateSpisok(struct spisok *st, int a, int b, int c)
{
  int i;
  for (i=0; i<a; i++)
  {
  st = calloc(1, sizeof(struct spisok));
  setSpisok(st, b);
  AddElementInEnd(st);
  c++;
  }
}

int main()
{
  struct spisok *sort;
  int v;
  int i,g;
  head = NULL;
  srand(time(0));
  system("clear");
  while(1)
  {
    g=0;
  printf("Введите количество элементов списка: ");
  fflush(stdout);
  scanf("%d", &elements);
  fflush(stdin);
  printf("1 - случайный массив");
  printf("\n4 - выход\n");
  printf("Введите пункт меню: ");
  fflush(stdout);
 /* scanf("%d", &v);*/
 /* switch (v)
    { 
      case 1: */
        printf("log");
        CreateSpisok(sort, elements, spisCount, g);
        spisPrint(sort);
      /*break;

      case 2: break;

      case 3: break;

      case 4: return 0;

      default : printf("Неверный режим");
      fflush(stdout);
    }*/
  }
  return 0;
}

