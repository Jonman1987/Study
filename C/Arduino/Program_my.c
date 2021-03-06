#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include "sym_matrix.h"
#include <stdlib.h>
#include <unistd.h>

#define DISPLAY_HEIGHT 8
#define DISPLAY_WIDTH 8
#define DISPLAY_PADDING 1
#define DISPLAY_PADDING_WT 1
#define MATRIX_WIDTH 5

uint8_t display[DISPLAY_HEIGHT];
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
	} else if ((sym == 'C') || (sym == 'c'))
	{
		return c;
	} else if ((sym == 'D') || (sym == 'd'))
	{
		return d;
	} else if ((sym == 'E') || (sym == 'e'))
	{
		return e;
	} else if ((sym == 'F') || (sym == 'f'))
	{
		return f;
	} else if ((sym == 'G') || (sym == 'g'))
	{
		return g;
	} else if ((sym == 'H') || (sym == 'h'))
	{
		return h;
	} else if ((sym == 'I') || (sym == 'i'))
	{
		return i;
	} else if ((sym == 'J') || (sym == 'j'))
	{
		return j;
	} else if ((sym == 'K') || (sym == 'k'))
	{
		return k;
	} else if ((sym == 'L') || (sym == 'l'))
	{
		return l;
	} else if ((sym == 'M') || (sym == 'm'))
	{
		return m;
	} else if ((sym == 'N') || (sym == 'n'))
	{
		return n;
	} else if ((sym == 'O') || (sym == 'o'))
	{
		return o;
	} else if ((sym == 'P') || (sym == 'p'))
	{
		return p;
	} else if ((sym == 'Q') || (sym == 'q'))
	{
		return q;
	} else if ((sym == 'R') || (sym == 'r'))
	{
		return r;
	} else if ((sym == 'S') || (sym == 's'))
	{
		return s;
	} else if ((sym == 'T') || (sym == 't'))
	{
		return t;
	} else if ((sym == 'U') || (sym == 'u'))
	{
		return u;
	} else if ((sym == 'V') || (sym == 'v'))
	{
		return v;
	} else if ((sym == 'W') || (sym == 'w'))
	{
		return w;
	} else if ((sym == 'X') || (sym == 'x'))
	{
		return x;
	} else if ((sym == 'Y') || (sym == 'y'))
	{
		return y;
	} else if ((sym == 'Z') || (sym == 'z'))
	{
		return z;
	} else
	{
		return NULL;
	}
	
}

void DisplayReset() // Скидывает значения показания дисплея на 0
{
	int i;

	for (i = 0; i < DISPLAY_HEIGHT; i++)
	{
			display[i] = 0;
	}
}

void DisplayShow() // Пробразует 0 и 1 в значениях дисплея на . и * и выводит на экран
{
	int i, j;

	for (i = 0; i < DISPLAY_HEIGHT; i++)
	{
		for (j = 1; j <= DISPLAY_WIDTH; j++)
		{
			if ((display[i] >> (DISPLAY_WIDTH - j)) & 1)
			{
				printf("* ");
			} else
			{
				printf(". ");
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

/*void PrintSym (uint8_t a[MATRIX_HEIGHT])
{
	int i, j;

	for (i = 0; i < MATRIX_HEIGHT; i++)
	{
		for (j = 1; j <= MATRIX_WIDTH; j++)
		{
			if ((a[i] >> (MATRIX_WIDTH - j)) & 1)
			{
				printf("* ");
			} else
			{
				printf("  ");
			}
		}
		printf("\n");
	}
	fflush(stdout); 
}*/

void MakeDisplay(uint8_t symmatrix[MATRIX_HEIGHT])
{
	int i;

	DisplayReset();

	for (i = 0; i < MATRIX_HEIGHT; i++)
	{		
		display[i + DISPLAY_PADDING_WT] = (symmatrix[i] << DISPLAY_PADDING);

		/*if ((i >= DISPLAY_PADDING) && (j < MATRIX_HEIGHT))
		{
			memcpy(&display[i][2], symmatrix[j], MATRIX_WIDTH);
			j++;
		}*/
	}
}

void MoveDisplay(uint8_t symmatrix[MATRIX_HEIGHT])
{
	int i, j;

	DisplayReset();
	system("clear");
for (j = 1; j <= MATRIX_WIDTH; j++)
{
	for (i = 0; i < MATRIX_HEIGHT; i++)
	{		
			display[i + DISPLAY_PADDING_WT] = (symmatrix[i] >> (MATRIX_WIDTH - j));

	}
	DisplayShow();
			printf("\n");
			sleep(1);
			system("clear");
}
for (j = 1; j <= DISPLAY_HEIGHT; j++)
{
	for (i = 0; i < MATRIX_HEIGHT; i++)
	{		
			display[i + DISPLAY_PADDING_WT] = (symmatrix[i] << j);

	}
	DisplayShow();
			printf("\n");
			sleep(1);
			system("clear");
}
}

int main()
{
	memset(display, 0, DISPLAY_HEIGHT);
	//uint8_t string[8] = {9, 9, 9, 9, 9, 9, 9, 9};
	//int i;
	char symbol[10];
	void *tmp;
	printf("Введите символ: ");
	fflush(stdout);
	gets(symbol);
	fflush(stdin);

	RunningStringSet(symbol);


	char *ptr = RunningStringProc();

	while(ptr != NULL)
	{
		printf("%c \n", *ptr);
		tmp = ImplementSym(*ptr);
		printf("%p \n", tmp);
		

		MakeDisplay(tmp);
		MoveDisplay(tmp);
		//DisplayShow();
		DisplayReset();
		ptr = RunningStringProc();
	}

	fflush(stdout);



	/*tmp = ImplementSym(symbol);

	if (tmp != NULL)
	{
	PrintSym(tmp);
	} else
	{
	printf("Ошибка\n");
	}
	fflush(stdout);

	for (i = 0; i < DISPLAY_HEIGHT; i++)
	{
		for (j = 0; j < DISPLAY_WIDTH; j++)
		{
			if ((i > 0) && (i < 7))
			memcpy(&display[i][2], b[i-1], MATRIX_WIDTH);
		}
	}
	

	printf("\n");
	for (i = 0; i < 8; i++)
	{
		for (j = 0; j < 8; j++)
			{
				printf("%d ", display[i][j]);
			}
	printf("\n");
	}
	DisplayShow();
	DisplayReset();*/
	

	return 0;
}