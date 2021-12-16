#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
	srand(time(NULL));
	int i, j, pr, n = 10;
	int a[n];

	for (i=0; i<n; i++)
		{
	a[i] = rand() % 105;
	
}
	for (i=0; i<n; i++)
	{
		printf("%d ", a[i]);
	}
pr=0;
for (j=1; j<n; j++)
	for (i=0; i<n; i++)
	{
		if (a[i]>a[i+1])
		{

			pr = a[i];
			a[i] = a[i+1];
			a[i+1] = pr;

		}
		
	}
	printf("\n");
for (i=0; i<n; i++)
	printf("%i ", a[i]);

	return 0;
}