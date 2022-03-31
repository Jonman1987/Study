#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include "sym_matrix.h"
#include <stdlib.h>

#define DISPLAY_HEIGHT 8
#define DISPLAY_WIDTH 8

uint8_t display[DISPLAY_HEIGHT][DISPLAY_WIDTH];
char *running_str_start = NULL;
char *running_str_current = NULL;

void *ImplementSym(char sym) // Функция возвращающая массив в зависимости от введенного символа
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

void DisplayReset() // Скидывает значения показания дисплея на 0
{
	int i, j;

	for (i = 0; i < DISPLAY_HEIGHT; i++)
	{
		for (j = 0; j < DISPLAY_WIDTH; j++)
		{
			display[i][j] = 0;
		}
	}
}

void DisplayShow() // Пробразует 0 и 1 в значениях дисплея на . и * и выводит на экран
{
	int i, j;

	for (i = 0; i < DISPLAY_HEIGHT; i++)
	{
		for (j = 0; j < DISPLAY_WIDTH; j++)
		{
			if (display[i][j] == 0)
			{
				printf(". ");

			} else
			{
				printf("* ");
			}
		}
		printf("\n");
	}
	fflush(stdout); 
}

void RunningStringSet(char *str)
{
	running_str_start = malloc(strlen(str) + 1);
	strcpy(running_str_start, str);
	running_str_current = running_str_start;
}

void *RunningStringProc()
{
	char *tmp_ptr;

	if(running_str_start == NULL)
	{
		return NULL;
	}

	if(*running_str_current == '\0')
	{
		free(running_str_start);
		running_str_start = NULL;
		return NULL;
	}

	tmp_ptr = running_str_current;
	running_str_current++;
	return tmp_ptr;
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
	char symbol;
	char *ptr;

	printf("Введите символ: ");
	fflush(stdout);
	scanf("%c", &symbol);
	fflush(stdin);

	ptr = ImplementSym(symbol);
	RunningStringSet(ptr);
	

	// uint8_t string[8] = {9, 9, 9, 9, 9, 9, 9, 9};
	// char symbol;
	// void *tmp;
	// printf("Введите символ: ");
	// fflush(stdout);
	// scanf("%c", &symbol);
	// fflush(stdin);

	// tmp = ImplementSym(symbol);

	// if (tmp != NULL)
	// {
	// 	PrintSym(tmp);
	// } else
	// {
	// 	printf("Ошибка\n");
	// }
	// fflush(stdout);

	// memcpy(&string[1], a[1], MATRIX_WIDTH);

	// printf("\n");
	// for (int i = 0; i < 8; i++)
	// {
	// 	printf("%u", string[i]);
	// }
	// printf("\n");



	/*memset(display, 1, DISPLAY_WIDTH * DISPLAY_HEIGHT);

	printf("11111\n");
	DisplayShow();
	printf("22222\n");
	DisplayReset();
	DisplayShow();*/

	//RunningStringSet("a12345");

	/*char *ptr = RunningStringProc();

	while(ptr != NULL)
	{
		printf("%c ", *ptr);
		ptr = RunningStringProc();
	}

	fflush(stdout); */

	return 0;
}
