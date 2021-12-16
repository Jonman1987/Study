#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
 
int RandElem(int a)
{
    a = 1 + rand() % 100;
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
int elements, summ, serialCount;
 
void setSpisok(struct spisok *a, int count1)
{
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
    printf("%d ", p->value);
    p=p->next;
    }
    printf("\n");
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

void ClearSpisok()
{
    struct spisok *p = head;
    struct spisok *p_tmp;

    while (p)
    {
        p_tmp = p->next;
        free(p);
        p = p_tmp;
    }

    head = NULL;
}

void ControlSumm(struct spisok *st, int a)
{
    a = 0;
    struct spisok *p = head;
    while(p)
    {
        a = a + p->value;
        p=p->next;
    }
    printf("Контрольная сумма: %d\n", a);
}

void Serial(struct spisok *st, int a)
{
    a = 1;
    struct spisok *p = head;
    while (p->next != NULL)
    {
        if((p->value)>(p->next->value))
        {
        a=a+1;
        }
        p=p->next;
    }
    printf("Число серий: %d\n", a);
}

void SepporateSpis(struct spisok *st, struct spisok *a, struct spisok *b, int count_ochered)
{
    int i=0;
    struct spisok *p=head;
    while(p)   
    {
        if (i%2 == 0)
        {
            a = calloc(1, sizeof(struct spisok));
            a->value = p->value;
            AddElementInEnd(a);

        } else
        {
            b = calloc(1, sizeof(struct spisok));
            b->value = p->value;
            AddElementInEnd(b);
        }
    p=p->next;
    i++;
    }
}
 
int main()
{
  struct spisok *sort;
  struct spisok *ochered1, *ochered2;
  char v;
  int i,g;
  g=0;
  head = NULL;
  srand(time(0));
  system("clear");
  while(1)
  {
  printf("Введите количество элементов списка: ");
  fflush(stdout);
  scanf("%d", &elements);
  fflush(stdin);
  printf("\n1 - список со случайными значениями\n");
  printf("1 - список с убывающей последовательностью\n");
  printf("1 - список с возрастающей последовательностью");
  printf("\n4 - выход\n");
  fflush(stdout);
  printf("Введите пункт меню: ");
  fflush(stdout);
  scanf("%c", &v);
  fflush(stdin);
  fflush(stdout);
  
  switch (v)
    { 
      case '1': 
      system("clear");
      ClearSpisok();
      CreateSpisok(sort, elements, spisCount, g);
      spisPrint(sort);
      ControlSumm(sort, summ);
      Serial(sort, spisCount);
      printf("log1");
      fflush(stdout);
      SepporateSpis(sort, ochered1, ochered2, elements);
      printf("log2");
      fflush(stdout);
      spisPrint(ochered1);
/*      spisPrint(ochered2);
*//*      spisPrint(sort);
*/      break;
 
      case '2': break;
 
      case '3': break;
 
      case '4': return 0;
 
      default : printf("Неверный режим");
      fflush(stdout);
    }
  }
  return 0;
}