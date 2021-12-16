#include <stdio.h>

long int n;
long int i,j, tmp;
long int minnumb, summ;

int main()
{
	
	printf("Введите количество элементов в массиве:\n");
	fflush(stdout);
	scanf("%i", &n);
	long int mass[n];
	summ = 0;
	for (int i = 0; i < n; i++)
	{
		printf("Введите число:\n");
		fflush(stdout);
		scanf("%i", &mass[i]);
		summ = summ + mass[i];
	}
	printf("\nСумма элементов: %i", summ);

	printf("\nМассив");

	for (int i = 0; i < n; i++)
		printf("%i", mass[i]);
	summ = 0;
	for (int i = 0; i < n; i++)
    {
        minnumb = i;
        for (int j = i + 1; j < n; j++)
            if (mass[minnumb] > mass[j])
                minnumb = j;
        tmp = mass[minnumb];
        mass[minnumb] = mass[i];
        mass[i] = tmp;
        summ = summ + mass[i];
    }
	printf("\nСумма элементов: %i", summ);
	printf("\nСортировка");

	for (int i = 0; i < n; i++)
		printf("%i", mass[i]);
	return 0;
}