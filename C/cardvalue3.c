/* card value program */
#include <stdio.h>
#include <stdlib.h>
int main()
{
	char card_name[3];
	int val = 0;
	
	puts("Введите название карты: ");
	fflush(stdout);
	
	scanf("%3s", card_name);
	switch(card_name[0])
	{
	case 'K':
	case 'Q':
	case 'J':
		val = 10;
		break;
	case 'A':
		val = 11;
		break;
	default:
		val = atoi(card_name);
	}
	if ((val>3) && (val<6))
		puts("Счетчик увеличился");
	else if (val == 10)
	{
		puts("Счетчик увеличился");
	}
	return 0;
}
