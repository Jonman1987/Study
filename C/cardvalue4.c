/* card value program */
#include <stdio.h>
#include <stdlib.h>
int main()
{
	char card_name[3];
	int count = 0;
	int val = 0;
	while (card_name[0] != 'X') //в примере было !='X'
	{
	puts("Введите значение карты: ");
	fflush(stdout);
	scanf("%2s", card_name);
	
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
	case 'X':
		return 0; //В примере было continue. Break сказано, что нельзя, но при этом прога работает
	default:
		{
		val = atoi(card_name);
		if ((val<1) || (val>10))
		{
			puts("Ошибка");
			continue;
		}
		}
	
	}
	if ((val>2) && (val<7))
		count++;
	else if (val == 10)
	count--;
printf("Текщий счет: %i\n", &count);
}
	return 0;
}
