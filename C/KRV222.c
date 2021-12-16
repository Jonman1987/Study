#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct ocenka
{
    char predm[10];
    int ocenka1;
    int ocenka2;
    int ocenka3;
};

struct zapis 
{
  char surname[10];
  char name[10];
  char secondname[10];
  struct ocenka dannie_uspevaemosti[3];
};

struct spisok
{
  struct zapis data;
  struct spisok *prev;
  struct spisok *next;
};

struct spisok *head = NULL;

void ClearSpisok(void);
void PrintStruktOcenka(struct ocenka *st); 


void SetStructZapis(struct zapis *st, char *string1, char *string2, char *string3)
{
    strcpy(st->surname, string1);
    strcpy(st->name, string2);
    strcpy(st->secondname, string3);
}

void SetStructOcenka(struct ocenka *st, char *predmet, int integer1, int integer2, int integer3)
{
    strcpy(st->predm, predmet);
    strcpy(st->ocenka1, integer1);
    strcpy(st->ocenka2, integer2);
    strcpy(st->ocenka3, integer3);
}

void PrintStructZapis(struct zapis *st)
{
    int i;

    printf("Фамилия: %s, Имя: %s, Отчество: %s\n", 
    st->surname, st->name, st->secondname);
    for (i = 0; i < 3; i++)
    {
        PrintStruktOcenka(&st->dannie_uspevaemosti[i]);
    }
}

void PrintStruktOcenka(struct ocenka *st)
{
    printf("\tПредмет: %s, Оценки: %d %d %d\n", st->predm, st->ocenka1, st->ocenka2, st->ocenka3);
}

/*void VvodOcenka(struct zapis *st)
{
    int i;
    char tmp_predm[10];
    int tmp_ocenka1;
    int tmp_ocenka2;
    int tmp_ocenka3;

    for (i=0; i<3; i++)
    {
        printf("\n Предмет: "); fflush(stdout); scanf("%s", &st->dannie_uspevaemosti.tmp_predm);
        printf("\n Оценка 1: "); fflush(stdout); scanf("%s", &tmp_ocenka1);
        printf("\n Оценка 2: "); fflush(stdout); scanf("%s", &tmp_ocenka2);
        printf("\n Оценка 2: "); fflush(stdout); scanf("%s", &tmp_ocenka3);
    }
}*/

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
    system("clear");
    struct spisok *p = head;
    char ch2 = 'n';

    while (p)
    {
        PrintStructZapis(&p->data);
        p = p->next;
    }
    printf("\n Введите любой символ");
    fflush(stdout);

    scanf("%s", &ch2);
    fflush(stdout);
}

void vvod()
{   
    char surnameT1[10];
    char nameT1[10];
    char secondnameT1[10];
    struct spisok *tmp_new;
    head = NULL;
    char ch2 = 'n';
    system("clear");
    do
    {
    printf("\nФамилия: "); fflush(stdout); scanf("%s", &surnameT1);
    printf("Имя: "); fflush(stdout); scanf("%s", &nameT1);
    printf("Отчество: "); fflush(stdout); scanf("%s", &secondnameT1);

    tmp_new = calloc(1, sizeof(struct spisok));
    SetStructZapis(&tmp_new->data, surnameT1, nameT1, secondnameT1);
    AddElementInEnd(tmp_new);

    SetStructOcenka(&tmp_new->data.dannie_uspevaemosti, da, 3, 3, 3);

    printf("\n Закончить? y/n ");
    fflush(stdout);

    scanf("%s", &ch2);
    fflush(stdout);
    }
    while (ch2 != 'y');
}

void dobavlenie()
{
    char surnameT1[10];
    char nameT1[10];
    char secondnameT1[10];
    struct spisok *tmp_new2;
    char ch3 = 'n';
    system("clear");
    do
    {
    printf("\nФамилия: "); fflush(stdout); scanf("%s", &surnameT1);
    printf("Имя: "); fflush(stdout); scanf("%s", &nameT1);
    printf("Отчество: "); fflush(stdout); scanf("%s", &secondnameT1);

    tmp_new2 = calloc(1, sizeof(struct spisok));
    SetStructZapis(&tmp_new2->data, surnameT1, nameT1, secondnameT1);
    AddElementInBeginning(tmp_new2);

    printf("\n Закончить? y/n ");
    fflush(stdout);

    scanf("%s", &ch3);
    fflush(stdout);
    }
    while (ch3 != 'y');
}

void FindAndCorr()
{   
    char ch4 = 'n';
    char ch5[10];
    char findsurname[10];
    struct spisok *p = head;
    printf("Поиск по фамилии: "); fflush(stdout); scanf("%s", &findsurname);

    while (p!=NULL)
    {if (strcmp((p->data.surname), findsurname)==0)
        {
        printf("Поиск по фамилии: ");
        PrintStructZapis(&p->data);
        printf("\n Корректировка фамилии. Введите новую фамилию");
        fflush(stdout);
        scanf("%s", &ch5);
        strcpy(p->data.surname, ch5);
        }
        p = p->next;
    }
    printf("\n Введите любой символ");
    fflush(stdout);

    scanf("%s", &ch4);
    fflush(stdout);
}

void delete() //не работает
{
    struct spisok *p=head;
    struct spisok *temp;
    char fam[10];

    system("clear");

    printf("Фамилия: ");
    fflush(stdout);
    scanf("%s", fam[10]);

   while(p!=NULL)
   {

    if (strcmp((p->data.surname), fam)==0) 
        {PrintStructZapis(&p->data);
            p=p->next;

    /*if (p==head) // если найденная запись - первая

        {

            head=p->next;

            head->prev=NULL;


            p=head;
        }*/

    

   /* else // удаление из средины списка

        {
            p->v2->v1=p->v1;

            p->v1->v2=p->v2;

            temp=p;

            p=p->v2;

            free(temp);
        }
    }

    else // если заданная фамилия не найдена – продвигаемся по списку

    p=p->v2;
*/
}}}


void ZapisFaila(FILE *tf)
{
    system("clear");
    struct spisok *p = head;
    char ch6 = 'n';
    tf=fopen("file_kr.dat","wb");

    while (p)
    {       
        fwrite((&p->data),sizeof(struct zapis),1,tf); 
        p = p->next;
    }
    printf("\n Данные записаны в файл. Для выхода введите любой символ: ");
    fflush(stdout);

    scanf("%s", &ch6);
    fflush(stdout);
    fclose(tf);
}

void LoadFile(FILE *tf)
{
    char hr;
    system("clear");
    struct spisok *tmp_new1 = head;

    ClearSpisok();

    tf=fopen("file_kr.dat","rb"); 
    
    while (1)
    {
        tmp_new1 = calloc(1, sizeof(struct spisok));

        if ((fread(&tmp_new1->data,sizeof(struct zapis),1,tf)) < 1) 
        {
            break;
        }

        printf("Чтение структуры с файла: Фамилия: %s | Имя: %s | Отчество: %s\n", tmp_new1->data.surname, tmp_new1->data.name, tmp_new1->data.secondname);
        fflush(stdout);
        AddElementInEnd(tmp_new1);
    }
   
    scanf("%s", &hr);
    fflush(stdout);
    fclose(tf);
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

int main()
{
    struct spisok tmp[10];
    memset(tmp, 0, sizeof(tmp));
    FILE *tf;
    char c;
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
      case '1': vvod(); break;

      case '2': vivod(); break;

      case '3': dobavlenie(); break;

      case '4': FindAndCorr(); break;

      case '5': delete(); break;

      case '6': ZapisFaila(tf); break;

      case '7': LoadFile(tf); break;

      case '0': return 0;

      default : printf(" неверный режим");
      fflush(stdout);
    }
}
    return 0;
}