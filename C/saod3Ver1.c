#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct dlist 
{
    int data;

    struct dlist *next;
    struct dlist *prev;
};

struct dlist *DListCreateElement(int data)
{
    struct dlist *el = calloc(1, sizeof(struct dlist));

    if (el)
    {
        /* If memory was allocated successfully - copy data to new element */
        el->data = data;
    }

    return el;
}

int DListPushBack(struct dlist *el, struct dlist **list)
{
    struct dlist *p = (*list);

    if (el == NULL)
    {
        /* We can't push "nothing" to list - error */
        return -1;
    }

    if (p == NULL)
    {
        /* If list is empty - make el to be the first element */
        el->next = NULL;
        el->prev = NULL;
        /* Set head of list to el */
        (*list) = el;
    } else {
        /* If list is not empty - get last element of list and add el as last element */
        while (p->next)
        {
            p = p->next;
        }

        p->next = el;
        el->prev = p;
        el->next = NULL;
    }

    return 0;
}



void DListPrint(const char *pfx_str, struct dlist **list)
{
    struct dlist *p = (*list);
    int size = 0;
    int summ=0, seria=1;

    printf("%s", pfx_str);

    while (p->next != NULL)
    {
        if((p->data)>(p->next->data))
        {
        seria=seria+1;
        }
        p=p->next;
    }

    struct dlist *g = (*list);

    while (g)
    {
        printf("%d ", g->data);
        size++;
        summ=summ + g->data;
        g = g->next;
    }

    
    
    printf("\n(size: %d)\n", size);
    fflush(stdout);
    printf("(summ: %d)\n", summ);
    fflush(stdout);
    printf("(seria: %d)\n", seria);
    fflush(stdout);

}

int DListRemove(struct dlist *el, struct dlist **list)
{
    if (el == NULL)
    {
        /* We can't remove "nothing" from list - error */
        return -1;
    }

    if ((*list) == NULL)
    {
        /* We can't remove from empty list - error */
        return -2;
    }

    if (el == (*list))
    {
        /* We're removing the head of list - change head to next element */
        (*list) = el->next;
        el->next = NULL;
    } else {
        /* Connect prev and next elements of el with each other */
        el->prev->next = el->next;

        if (el->next)
        {
            /* if next element after el exists - connect it to element before el */
            el->next->prev = el->prev;
        }

        el->next = NULL;
        el->prev = NULL;
    }

    return 0;
}

/*void SeparateList(struct dlist **list, struct dlist **list1, struct dlist **list2, int count)
{
    struct dlist *el;



}*/

int main()
{
    int i, n=10;
    struct dlist *l1 = NULL;
    struct dlist *l2 = NULL;
    struct dlist *l3 = NULL;
    struct dlist *p, *p1;

    srand(time(0));

    for (i = 0; i < n; i++)
    {
        p = DListCreateElement(rand() % 100);
        DListPushBack(p, &l3);
    }

    DListPrint("L3: ", &l3);

    return 0;
}