#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct ocenka
{
    char predm[10];
    int ocenka1;
    int ocenka2;
    int ocenka3;
    int ocenka4;
};

struct zapis 
{
  char surname[10];
  char name[10];
  char secondname[10];
  struct ocenka dannie_uspevaemosti[4];
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

void SetStructOcenka(struct ocenka *st, char *string1, int integer1, int integer2, int integer3, int integer4)
{
    strcpy(st->predm, string1);
    st->ocenka1 = integer1;
     st->ocenka2 = integer2;
     st->ocenka3 = integer3;
     st->ocenka4 = integer4;
}

void PrintStructZapis(struct zapis *st)
{
    int i;

    printf("Фамилия: %s, Имя: %s, Отчество: %s\n", 
    st->surname, st->name, st->secondname);
    for (i = 0; i < 4; i++)
    {
        PrintStruktOcenka(&st->dannie_uspevaemosti[i]);
    }
}

void PrintStruktOcenka(struct ocenka *st)
{
    printf("\tПредмет: %s, Оценки: %d %d %d %d\n", st->predm, st->ocenka1, st->ocenka2, st->ocenka3, st->ocenka4);
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
    char tmp3_predm[10];
    int tmp3_ocenka1;
    int tmp3_ocenka2;
    int tmp3_ocenka3;
    int tmp3_ocenka4;
    int i;
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

    for (i=0; i<4; i++)
    {
    printf("\nПредмет: "); fflush(stdout); scanf("%s", &tmp3_predm);
    printf("\nОценка: "); fflush(stdout); scanf("%i", &tmp3_ocenka1);
    printf("\nОценка: "); fflush(stdout); scanf("%i", &tmp3_ocenka2);
    printf("\nОценка: "); fflush(stdout); scanf("%i", &tmp3_ocenka3);
    printf("\nОценка: "); fflush(stdout); scanf("%i", &tmp3_ocenka4);
    SetStructOcenka(&tmp_new->data.dannie_uspevaemosti[i], tmp3_predm, tmp3_ocenka1, tmp3_ocenka2, tmp3_ocenka3, tmp3_ocenka4);
    }

    AddElementInEnd(tmp_new);

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
    char tmp_predm[10];
    int tmp_ocenka1;
    int tmp_ocenka2;
    int tmp_ocenka3;
    int tmp_ocenka4;
    int i;
    char ch3 = 'n';
    system("clear");
    do
    {
    printf("\nФамилия: "); fflush(stdout); scanf("%s", &surnameT1);
    printf("Имя: "); fflush(stdout); scanf("%s", &nameT1);
    printf("Отчество: "); fflush(stdout); scanf("%s", &secondnameT1);

    tmp_new2 = calloc(1, sizeof(struct spisok));
    SetStructZapis(&tmp_new2->data, surnameT1, nameT1, secondnameT1);
    

    for (i=0; i<4; i++)
    {
    printf("\nПредмет: "); fflush(stdout); scanf("%s", &tmp_predm);
    printf("\nОценка: "); fflush(stdout); scanf("%i", &tmp_ocenka1);
    printf("\nОценка: "); fflush(stdout); scanf("%i", &tmp_ocenka2);
    printf("\nОценка: "); fflush(stdout); scanf("%i", &tmp_ocenka3);
     printf("\nОценка: "); fflush(stdout); scanf("%i", &tmp_ocenka4);
    SetStructOcenka(&tmp_new2->data.dannie_uspevaemosti[i], tmp_predm, tmp_ocenka1, tmp_ocenka2, tmp_ocenka3, tmp_ocenka4);
    }
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
    int count, i;
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
        printf("\n Корректировка имени. Введите новое имя");
        fflush(stdout);
        scanf("%s", &ch5);
        strcpy(p->data.name, ch5);
        printf("\n Корректировка отчества. Введите новое отчество");
        fflush(stdout);
        scanf("%s", &ch5);
        strcpy(p->data.secondname, ch5);

         for (i=0; i<4; i++)
        {
            printf("\nКорректировка предмета. Введите новый предмет "); fflush(stdout); scanf("%s", &ch5);
            strcpy(p->data.dannie_uspevaemosti[i].predm, ch5);
            printf("\nКорректировка оценки. Введите новую оценку "); fflush(stdout); scanf("%i", &count);
            p->data.dannie_uspevaemosti[i].ocenka1 = count;
            printf("\nКорректировка оценки. Введите новую оценку "); fflush(stdout); scanf("%i", &count);
            p->data.dannie_uspevaemosti[i].ocenka2 = count;
            printf("\nКорректировка оценки. Введите новую оценку "); fflush(stdout); scanf("%i", &count);
            p->data.dannie_uspevaemosti[i].ocenka3 = count;
            printf("\nКорректировка оценки. Введите новую оценку "); fflush(stdout); scanf("%i", &count);
            p->data.dannie_uspevaemosti[i].ocenka4 = count;
         }
         
         
         
        }
        p = p->next;
    }
    printf("\n Введите любой символ");
    fflush(stdout);

    scanf("%s", &ch4);
    fflush(stdout);
}

void DeleteElem(struct spisok *del_element)
{
    struct spisok *g=head;
    if (head == NULL)
    {
        printf("В списке нет элементов");

    } else if (head == del_element)
    {
        head = del_element->next;
        del_element->next = NULL;
        del_element->prev = NULL;
        free(del_element);
    }else if ((head != del_element) && (del_element->next != NULL))
    {
        del_element->prev->next = del_element->next;
        free(del_element);
       
    }else if (del_element->next == NULL)
    {
        del_element->prev->next = NULL;
        del_element->prev = NULL;
        free(del_element);
    }
}

void delete()
{
    char ch4 = 'n';
    char ch5[10];
    int findocenka;
    int i=0;
    int posledovatelnost_ocenok;
    struct spisok *p = head;
    struct spisok *tmp_korr;
    printf("Укажите оценку 1: "); fflush(stdout); scanf("%i", &findocenka);

   while (p!=NULL)
   {
        for (i=0; i<4; i++)

        {
            if (p->data.dannie_uspevaemosti[i].ocenka1 == findocenka)
            {
                posledovatelnost_ocenok++;
            }
            if (p->data.dannie_uspevaemosti[i].ocenka2 == findocenka)
            {
                posledovatelnost_ocenok++;
            }
            if (p->data.dannie_uspevaemosti[i].ocenka3 == findocenka)
            {
                posledovatelnost_ocenok++;
            }
            if (p->data.dannie_uspevaemosti[i].ocenka4 == findocenka)
            {
                posledovatelnost_ocenok++;
            }
            if (posledovatelnost_ocenok >= 3)
            {
                        printf("\tФамилия: %s, Предмет: %s, Оценки: %d %d %d %d\n", p->data.surname, p->data.dannie_uspevaemosti[i].predm, p->data.dannie_uspevaemosti[i].ocenka1, p->data.dannie_uspevaemosti[i].ocenka2, p->data.dannie_uspevaemosti[i].ocenka3, p->data.dannie_uspevaemosti[i].ocenka4);
                            printf("\n Удалить запись?");
                            fflush(stdout);
                            scanf("%s", &ch4);
                            fflush(stdout);
                            tmp_korr=p->next;
                            if (ch4 == 'y')
                                {   
                                    DeleteElem(p);
                                    break;
                                }

            }
            posledovatelnost_ocenok=0;
        }
        p=tmp_korr;
   }
    
}

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