/* card value program */
#include <stdio.h>
#include <stdlib.h>
int main()
{
	char card_name[3];
	int val = 10;
	
	puts("Введите название карты: ");
	fflush(stdout);
	
	scanf("%2s", card_name);
	
	if (card_name[0] == 'K')
		{
			val = 10;
		}
		else if (card_name[0] == 'Q')
			{
				val = 10;
			}
			else if (card_name[0] == 'J')
				{
					val = 10;
				}
				else if (card_name[0] == 'A')
					{		
						val = 11;
					}
					else
						{
							val = atoi(card_name);
						}
	printf("Ценность карты: %i\n", val);
	return 0;
}
