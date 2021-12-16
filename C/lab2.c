#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

void RandElem(int a)
{
	srand(time(0));
	a = rand() % 100;
}

struct spisok
{
  int value;
  struct spisok *prev;
  struct spisok *next;
};

struct spisok *head = NULL;
struct spisok *tail = NULL;

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

void SetStructZapis(struct zapis *st, int count)
{
    st->value = count;
}

void vvod()
{   
	int count;
    struct spisok *tmp_new;
    for (i=1; i<5; i++)
    {
    tmp_new = calloc(1, sizeof(struct spisok));
    RandElem(count);
    SetStructZapis(&tmp_new->value, count);
    AddElementInEnd(tmp_new);
    }
}

void PrintStructZapis(struct spisok *st)
{
    int i;

    
    for (i = 0; i < 3; i++)
    {
        printf(" ", st->value);
    }
}

int main()
{

	vvod();
	PrintStructZapis()

	return 0;
}