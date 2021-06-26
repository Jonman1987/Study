#include <stdio.h>
int larger(int a, int b)
{
	if (a>b)
		return a;
	return b;
}
int main()
{
int greatest = larger(100, 1000);
printf("Число %i наибольшее! \n", greatest);
return(0);
}

