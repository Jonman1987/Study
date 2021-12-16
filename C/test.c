#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>

struct test {
    char string[30];
    int a;
    uint16_t b;
    char c;
} __attribute__((packed));

void TestSet(struct test *st, char *string, int num1, uint16_t num2, char num3)
{
    strcpy(st->string, string);
    st->a = num1;
    st->b = num2;
    st->c = num3;
}

void TestPrint(struct test *st)
{
    printf("string: \"%s\", a: %d, b: %u, c: '%c' (%d) addr: %p\n", 
        st->string, st->a, st->b, st->c, st->c, st);
}

struct spis {
    struct test data;
    struct spis *prev;
    struct spis *next;
} __attribute__((packed));

struct spis *head = NULL;

int ListAppend(struct spis *added_elemnt)
{
    if (head == NULL)
    {
        head = added_elemnt;
    } else {
        struct spis *p = head;

        while (p->next != NULL)
        {
            p = p->next;
        }

        added_elemnt->next = NULL;
        added_elemnt->prev = p;
        p->next = added_elemnt;
    }
}

int ListAdd(struct spis *added_elemnt)
{
    if (head == NULL)
    {
        head = added_elemnt;
    } else {
        added_elemnt->next = head;
        added_elemnt->prev = NULL;
        head->prev = added_elemnt;

        head = added_elemnt;
    }
}

int main(int argc, char const *argv[])
{
    char input[64];

    struct test *stt;

    struct spis tmp[10];
    struct spis *tmp_new;

    memset(tmp, 0, sizeof(tmp));

    tmp_new = calloc(1, sizeof(struct spis));
    TestSet(&tmp_new->data, "NameOne", 1, 2, '1');
    ListAppend(tmp_new);

    tmp_new = calloc(1, sizeof(struct spis));
    TestSet(&tmp_new->data, "NameNine", 9, 2, '9');
    ListAppend(tmp_new);

    tmp_new = calloc(1, sizeof(struct spis));
    TestSet(&tmp_new->data, "NameFive", 5, 2, '5');
    ListAdd(tmp_new);


    // TestSet(&tmp[0].data, "NameOne", 1, 2, '1');
    // TestSet(&tmp[2].data, "NameNine", 9, 2, '9');
    // TestSet(&tmp[1].data, "NameFive", 5, 2, '5');

    // ListAppend(&tmp[1]);
    // ListAppend(&tmp[0]);
    // ListAdd(&tmp[2]);

    struct spis *p = head;

    while (p)
    {
        TestPrint(&p->data);
        p = p->next;
    }



    // printf("size of struct: %ld, size of all array: %ld\n", sizeof(struct test), sizeof(st));
    
    
    // strcpy()

    // FILE *f = fopen("bin_file.bin", "wb");

    // float digit = 1.1f;

    // fwrite(&st[0], sizeof(struct test), 1, f);

    // fclose(f);

    return 0;
}