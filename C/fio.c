#include <stdio.h>

char first_name[20];
	char last_name[20];
int main()
{
	
	printf("Введите имя и фамилию: ");
	fflush(stdout);
	scanf("%19s %19s", first_name, last_name);
	printf("Имя: %s Фамилия: %s\n", first_name, last_name);
	fflush(stdout);
	return 0;
}