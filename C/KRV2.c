#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct zapis 
{
  char surname[10];
  char name[10];
  char secondname[10];
};

struct spisok
{
  struct zapis data;
  struct spisok *prev;
  struct spisok *next;
};

struct spisok *head = NULL;

void SetStructZapis(struct zapis *st, char *string1, char *string2, char *string3)
{
    strcpy(st->surname, string1);
    strcpy(st->name, string2);
    strcpy(st->secondname, string3);
}

void PrintStructZapis(struct zapis *st)
{
    printf("Фамилия: %s, Имя: %s, Отчество: %s\n", 
    st->surname, st->name, st->secondname);
}

int AddElementInBeginning(struct spisok *add_element)
{
    if (head == NULL)
    {
        head = add_element;
    } else {
        add_element->next = head;
        add_element->prev = NULL;
        head->prev = add_element;
        head = add_element;
    }
}

void vivod()
{
    struct spisok *p = head;

    while (p)
    {
        PrintStructZapis(&p->data);
        p = p->next;
    }
}

void vvod()
{
    char surnameT[10];
    char nameT[10];
    char secondnameT[10];
    struct spisok tmp[10];
    struct spisok *tmp_new;
    memset(tmp, 0, sizeof(tmp));
    char ch2 = 'n';

    system("clear");

    do
    {
    printf("\nФамилия: "); fflush(stdout); scanf("%s", surnameT);
    printf("Имя: "); fflush(stdout); scanf("%s", nameT);
    printf("Отчество: "); fflush(stdout); scanf("%s", secondnameT);

    tmp_new = calloc(1, sizeof(struct spisok));
    SetStructZapis(&tmp_new->data, surnameT, nameT, secondnameT);
    AddElementInBeginning(tmp_new);

    printf("\n Закончить? y/n ");
    fflush(stdout);

    scanf("%s", &ch);
    fflush(stdout);
    }
    while (ch2 != 'y');
}

int main()
{
    
	

    printf("\nФамилия: "); fflush(stdout); scanf("%s", &surnameT);
    printf("Имя: "); fflush(stdout); scanf("%s", &nameT);
    printf("Отчество: "); fflush(stdout); scanf("%s", &secondnameT);

    tmp_new = calloc(1, sizeof(struct spisok));
    SetStructZapis(&tmp_new->data, surnameT, nameT, secondnameT);
    AddElementInBeginning(tmp_new);

    printf("\nФамилия: "); fflush(stdout); scanf("%s", &surnameT);
    printf("Имя: "); fflush(stdout); scanf("%s", &nameT);
    printf("Отчество: "); fflush(stdout); scanf("%s", &secondnameT);

    tmp_new = calloc(1, sizeof(struct spisok));
    SetStructZapis(&tmp_new->data, surnameT, nameT, secondnameT);
    AddElementInBeginning(tmp_new);

    vivod();

    return 0;
}