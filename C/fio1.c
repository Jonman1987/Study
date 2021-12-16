#include <stdio.h>

char first_name[2];
	char last_name[20];
int main()
{
	
	printf("Введите имя и фамилию: ");
	fflush(stdout);
	fgets(first_name, sizeof(first_name), stdin);
	fgets(last_name, sizeof(last_name), stdin);
	printf("Имя: %sФамилия: %s\n", first_name, last_name);
	fflush(stdout);
	return 0;
}