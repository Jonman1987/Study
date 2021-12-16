#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int pr, i, j, n = 10;

void Sort(int s[])
{
	pr=0;
	for (j=1; j<n; j++)
		for (i=0; i<n; i++)
		{
			if (s[i]>s[i+1])
			{
				pr = s[i];
				s[i] = s[i+1];
				s[i+1] = pr;
			}
		}
}

void Rand(int s[])
{
	for (i=0; i<n; i++)
	{
		s[i] = rand() % 105;
	}
}

void PrintMas(int s[])
{
	for (i=0; i<n; i++)
		{
			printf("%d ", s[i]);
		}
	printf("\n");
}

int main()
{
	srand(time(NULL));
	int a[n], b[n];

	Rand(a);
	Rand(b);
	printf("Random massive a[]:\n");
	PrintMas(a);
	Sort(a);
	printf("Sorted massive a[]:\n");
	PrintMas(a);
	printf("\n");
	printf("Random massive b[]:\n");
	PrintMas(b);
	Sort(b);
	printf("Sorted massive b[]:\n");
	PrintMas(b);
	return 0;
}