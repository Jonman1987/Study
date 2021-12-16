#include <stdio.h>

int main()
{
	int a;
	char c = '4';
	a = 4;
	printf("a= %d, c = %c\n", a, c);
	a = c;
	printf("a= %d, c = %c\n", a, c);
	return 0;
}