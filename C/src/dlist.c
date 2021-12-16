#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct dlist 
{
    int data;

    struct dlist *next;
    struct dlist *prev;
};

struct dlist *DListCreateElement(int data);
void          DListDestroyElement(struct dlist *el);
void          DListDestroy(struct dlist **list);
int           DListPushBack(struct dlist *el, struct dlist **list);
int           DListPushFront(struct dlist *el, struct dlist **list);
int           DListInsert(struct dlist *el, struct dlist *el_before, struct dlist **list);
struct dlist *DListFind(int data, struct dlist **list);
int           DListRemove(struct dlist *el, struct dlist **list);
int           DListSwap(struct dlist *el1, struct dlist *el2, struct dlist **list);
void          DListPrint(const char *pfx_str, struct dlist **list);

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

void DListDestroyElement(struct dlist *el)
{
    free(el);
}

void DListDestroy(struct dlist **list)
{
    struct dlist *p = (*list);
    struct dlist *p_tmp;
    
    while (p)
    {
        p_tmp = p->next;

        DListDestroyElement(p);

        p = p_tmp;
    }

    (*list) = NULL;
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

int DListPushFront(struct dlist *el, struct dlist **list)
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
        /* If list is not empty - change list head to el */
        p->prev = el;
        el->next = p;
        el->prev = NULL;
        /* Change head of list to el */
        (*list) = el;
    }

    return 0;
}

int DListInsert(struct dlist *el, struct dlist *el_before, struct dlist **list)
{
    if (el == NULL)
    {
        /* We can't insert "nothing" to list - error */
        return -1;
    }

    if (el_before == NULL)
    {
        /* We can't insert before "nothing" - error */
        return -2;
    }

    if ((*list) == NULL)
    {
        /* If list is empty - make el to be the first element */
        el->prev = NULL;
        el->next = NULL;
        /* Set head of list to el */
        (*list) = el;
    } else {
        if (el_before == (*list))
        {
            /* If el_before is list head, we just use regular PushFront operation for list */
            DListPushFront(el, list);
        } else {
            /* Insert el before el_before */
            el->next = el_before;
            el->prev = el_before->prev;

            el_before->prev->next = el;
            el_before->prev = el;
        }
    }

    return 0;
}

struct dlist *DListFind(int data, struct dlist **list)
{
    struct dlist *p = (*list);

    while (p)
    {
        if (p->data == data)
            break;

        p = p->next;
    }

    return p;
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

int DListSwap(struct dlist *el1, struct dlist *el2, struct dlist **list)
{
    struct dlist *p;

    if (el1 == NULL || el2 == NULL)
    {
        /* We can't swap "nothing" from list - error */
        return -1;
    }

    if (el1->prev == el2 || el1->next == el2)
    {
        /* swapping neighbors */
        struct dlist *left, *right;

        if (el1->prev == el2)
        {
            left = el2;
            right = el1;
        } else {
            left = el1;
            right = el2;
        }

        if (left->prev)
        {
            left->prev->next = right;
        }

        if (right->next)
        {
            right->next->prev = left;
        }

        p = right->next;

        right->prev = left->prev;
        right->next = left;
        left->prev = right;
        left->next = p;
    } else {
        /* swapping not neighbors */
        if (el1->prev)
            el1->prev->next = el2;
        
        if (el1->next)
            el1->next->prev = el2;

        if (el2->prev)
            el2->prev->next = el1;

        if (el2->next)
            el2->next->prev = el1;

        p = el1->prev;
        el1->prev = el2->prev;
        el2->prev = p;

        p = el1->next;
        el1->next = el2->next;
        el2->next = p;
    }

    /* Check if one of swaped elements is head */
    if (el1 == (*list))
    {
        (*list) = el2;
    } else if (el2 == (*list)) {
        (*list) = el1;
    }

    return 0;
}

void DListPrint(const char *pfx_str, struct dlist **list)
{
    struct dlist *p = (*list);
    int size = 0;

    printf("%s", pfx_str);

    while (p)
    {
        printf("%d ", p->data);
        size++;
        p = p->next;
    }
    
    printf("(size: %d)\n", size);
    fflush(stdout);
}

int main(int argc, char const *argv[])
{
    int i;
    int n = 10;
    struct dlist *l1 = NULL;
    struct dlist *l2 = NULL;
    struct dlist *l3 = NULL;
    struct dlist *p, *p1;

    srand(time(0));

    for (i = 0; i < n; i++)
    {
        p = DListCreateElement(i);
        DListPushBack(p, &l1);
    }

    for (i = 0; i < n; i++)
    {
        p = DListCreateElement(i);
        DListPushFront(p, &l2);
    }

    for (i = 0; i < n; i++)
    {
        p = DListCreateElement(rand() % 100);
        DListPushBack(p, &l3);
    }

    DListPrint("L1: ", &l1);
    DListPrint("L2: ", &l2);
    DListPrint("L3: ", &l3);

    printf("=====================================================\n");
    fflush(stdout);

    p = DListFind(3, &l2);
    DListRemove(p, &l2);
    p1 = DListFind(5, &l1);
    DListInsert(p, p1, &l1);

    DListPrint("L1: ", &l1);
    DListPrint("L2: ", &l2);

    printf("=====================================================\n");
    fflush(stdout);

    while (l2)
    {
        p = l2;
        DListRemove(p, &l2);
        DListPushBack(p, &l1);
    }

    DListPrint("L1: ", &l1);
    DListPrint("L2: ", &l2);

    printf("=====================================================\n");
    fflush(stdout);

    p = l3;
    p1 = l3;

    while (p1->next)
    {
        p1 = p1->next;
    }

    DListPrint("L3:\n ", &l3);
    DListSwap(p, p1, &l3);
    DListPrint("L3 swaped first and last:\n ", &l3);
    DListSwap(p, p1, &l3);
    
    p = p->next;

    DListPrint("L3:\n ", &l3);
    DListSwap(p, p1, &l3);
    DListPrint("L3 swaped second and last:\n ", &l3);
    DListSwap(p, p1, &l3);

    p1 = p1->prev;

    DListPrint("L3:\n ", &l3);
    DListSwap(p, p1, &l3);
    DListPrint("L3 swaped second and pre-last:\n ", &l3);
    DListSwap(p, p1, &l3);

    p1 = p->next;

    DListPrint("L3:\n ", &l3);
    DListSwap(p, p1, &l3);
    DListPrint("L3 swaped second and third:\n ", &l3);
    DListSwap(p, p1, &l3);

    DListDestroy(&l1);
    DListDestroy(&l2);
    DListDestroy(&l3);
    return 0;
}