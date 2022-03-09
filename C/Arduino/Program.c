#include <stdio.h>
#include <stdint.h>
#include <string.h>


#define MATRIX_HEIGHT 6
#define MATRIX_WIDTH 5

uint8_t a[MATRIX_HEIGHT][MATRIX_WIDTH] = 
{
	{0, 0, 1, 0 , 0},
	{0, 1, 0, 1 , 0},
	{1, 0, 0, 0 , 1},
	{1, 1, 1, 1 , 1},
	{1, 0, 0, 0 , 1},
	{1, 0, 0, 0 , 1},
};

uint8_t b[MATRIX_HEIGHT][MATRIX_WIDTH] = 
{
	{1, 1, 1, 1 , 0},
	{1, 0, 0, 0 , 1},
	{1, 1, 1, 1 , 0},
	{1, 0, 0, 0 , 1},
	{1, 0, 0, 0 , 1},
	{1, 1, 1, 1 , 0},
};

void *ImplementSym(char sym)
{
	if ((sym == 'A') || (sym == 'a'))
	{
		return a;
	} else if ((sym == 'B') || (sym == 'b'))
	{
		return b;
	} else
	{
		return 0;
	}
}

void PrintSym (uint8_t a[MATRIX_HEIGHT][MATRIX_WIDTH])
{
	int i, j;

	for (i = 0; i < MATRIX_HEIGHT; i++)
	{
		for (j = 0; j < MATRIX_WIDTH; j++)
		{
			if (a[i][j] == 0)
			{
				printf("  ");

			} else
			{
				printf("* ");
			}
		}
		printf("\n");
	}
	fflush(stdout); 
}


int main()
{
	uint8_t string[8] = {9, 9, 9, 9, 9, 9, 9, 9};
	char symbol;
	void *tmp;
	printf("Введите символ: ");
	fflush(stdout);
	scanf("%c", &symbol);
	fflush(stdin);

	tmp = ImplementSym(symbol);

	if (tmp != NULL)
	{
		PrintSym(tmp);
	} else
	{
		printf("Ошибка\n");
	}
	fflush(stdout);

	memcpy(&string[1], a[1], MATRIX_WIDTH);

	printf("\n");
	for (int i = 0; i < 8; i++)
	{
		printf("%u", string[i]);
	}
	printf("\n");
	fflush(stdout);

	return 0;
}
