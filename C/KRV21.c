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


void VvodNovogoSpiska()
{
	char surnameT[10];
	char nameT[10];
	char secondnameT[10];

	system("clear");
    printf("\nФамилия: "); fflush(stdout); scanf("%s", &surnameT);
    printf("Имя: "); fflush(stdout); scanf("%s", &nameT);
    printf("Отчество: "); fflush(stdout); scanf("%s", &secondnameT);

    struct spisok tmp[10];
    struct spisok *tmp_new;
    memset(tmp, 0, sizeof(tmp));

    tmp_new = calloc(1, sizeof(struct spisok));
    SetStructZapis(&tmp_new->data, surnameT, nameT, secondnameT);
    AddElementInBeginning(tmp_new);

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
    
    
}

void Print()
{
struct spisok *p = head;
    while (p)
    {
        PrintStructZapis(&p->data);
        p = p->next;
}



int main()
{
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
      case '1': VvodNovogoSpiska(); break;

      case '2': 


    } break;

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
	

    

    return 0;
}