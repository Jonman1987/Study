#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

int controlSumm, series, c, m;

void MassRand(int *a, int size)
{
	int i;
	srand(time(0));
		for (i=0; i<size; i++)
		{
			 a[i] = rand() % 100;
		}
}

void FuncControlSumm(int *b, int count)
{
	int i;
	controlSumm=0;
	for (i=0; i<count; i++)
		controlSumm = controlSumm + b[i];

	printf("\nКонтрольная сумма: %i\n", controlSumm);
}

void FuncControlSeries(int *c, int count1)
{
	int i;
	series=1;
	for (i=1; i<count1; i++)
	{
		if (c[i] < c[i-1])
		{
			series=series+1;
		}
	}
	printf("Количество серий: %i\n", series);
}

void PrintMass(int *d, int size)
{
	int i;
	for (i=0; i<size; i++)
	{
		 printf("%i ", d[i]);
	}
}

void Straightsort(int *e, int count2)
{
	int i, j, tmp, minnumb;
	m=0, c=0;
	for (int i = 0; i < count2-1; i++)
    {
    	minnumb=i;
        for (int j = i + 1; j < count2; j++)
        {
        	c++;
            if (e[minnumb] > e[j])
            {
                minnumb = j;
            }
         }
        		tmp = e[minnumb];
        		e[minnumb] = e[i];
        		e[i] = tmp;
        		m+=3;
    }
}

void BubbleSort(int *g, int count4)
{
	int i;
	m=0; c=0;
	for (int i = 1; i < count4; i++)
    {
    	int j, tmp;
        for (int j = 1; j < count4; j++)
        {
        	c++;
            if (g[j] < g[j-1])
            {
                tmp = g[j];
                g[j] = g[j-1];
                g[j-1] = tmp;
                m++;
            }
         }
    }
}

void ShekerSort(int *h, int count5)
{
  int left = 0, right = count5 - 1;
  int flagSort = 1;
  m=0; c=0;

  while ((left < right) && flagSort > 0)
  {
    flagSort = 0;
    for (int i = left; i<right; i++)
    {
      if (h[i] > h[i + 1])
      {    
        double t = h[i];
        h[i] = h[i + 1];
        h[i + 1] = t;
        flagSort = 1;
      }
    }
    right--;
    for (int i = right; i>left; i--)
    {
      if (h[i - 1]>h[i])
      {
        double t = h[i];
        h[i] = h[i - 1];
        h[i - 1] = t;
        flagSort = 1;
      }
    }
    left++;
  }
}

void PrintCM()
{
	printf("Количество операций пересылки: %i\n", m);
	printf("Количество операций сравнения: %i\n", c);
}

void Revers(int *f, int count3)
{
	int i;
	for (i=0; i<count3/2; i++)
	{
		int tmp_mass;
		tmp_mass=f[i];
		f[i]=f[count3-1-i];
		f[count3-1-i]=tmp_mass;
	}
}

int main()
{
	int n=100;
	int mass[n];
	MassRand(mass, n);

	//straight sort

	printf("Случайный массив из %i элементов: \n", n);
	PrintMass(mass, n);
	FuncControlSumm(mass, n);
	FuncControlSeries(mass, n);

	printf("\nОтсортированный случайный массив из %i элементов: \n", n);
	Straightsort(mass, n);
	PrintMass(mass, n);
	FuncControlSumm(mass, n);
	FuncControlSeries(mass, n);
	PrintCM();

	printf("\nУпорядоченный массив из %i элементов: \n", n);
	PrintMass(mass, n);
	FuncControlSumm(mass, n);
	FuncControlSeries(mass, n);

	printf("\nОтсортированный упорядоченный массив из %i элементов: \n", n);
	Straightsort(mass, n);
	PrintMass(mass, n);
	FuncControlSumm(mass, n);
	FuncControlSeries(mass, n);
	PrintCM();

	printf("\nМассив обратного порядка из %i элементов: \n", n);
	Revers(mass, n);
	PrintMass(mass, n);
	FuncControlSumm(mass, n);
	FuncControlSeries(mass, n);

	printf("\nОтсортированный массив обратного порядка из %i элементов: \n", n);
	Straightsort(mass, n);
	PrintMass(mass, n);
	FuncControlSumm(mass, n);
	FuncControlSeries(mass, n);
	PrintCM();
	printf("----------------------------------------------------------\n");

	//bublesort

	MassRand(mass, n);

	printf("Случайный массив из %i элементов: \n", n);
	PrintMass(mass, n);
	FuncControlSumm(mass, n);
	FuncControlSeries(mass, n);

	printf("\nОтсортированный случайный массив из %i элементов: \n", n);
	BubbleSort(mass, n);
	PrintMass(mass, n);
	FuncControlSumm(mass, n);
	FuncControlSeries(mass, n);
	PrintCM();

	printf("\nУпорядоченный массив из %i элементов: \n", n);
	PrintMass(mass, n);
	FuncControlSumm(mass, n);
	FuncControlSeries(mass, n);

	printf("\nОтсортированный упорядоченный массив из %i элементов: \n", n);
	BubbleSort(mass, n);
	PrintMass(mass, n);
	FuncControlSumm(mass, n);
	FuncControlSeries(mass, n);
	PrintCM();

	printf("\nМассив обратного порядка из %i элементов: \n", n);
	Revers(mass, n);
	PrintMass(mass, n);
	FuncControlSumm(mass, n);
	FuncControlSeries(mass, n);

	printf("\nОтсортированный массив обратного порядка из %i элементов: \n", n);
	BubbleSort(mass, n);
	PrintMass(mass, n);
	FuncControlSumm(mass, n);
	FuncControlSeries(mass, n);
	PrintCM();
	printf("----------------------------------------------------------\n");

	//Shakersort

	MassRand(mass, n);

	printf("Случайный массив из %i элементов: \n", n);
	PrintMass(mass, n);
	FuncControlSumm(mass, n);
	FuncControlSeries(mass, n);

	printf("\nОтсортированный случайный массив из %i элементов: \n", n);
	ShekerSort(mass, n);
	PrintMass(mass, n);
	FuncControlSumm(mass, n);
	FuncControlSeries(mass, n);
	PrintCM();

	printf("\nУпорядоченный массив из %i элементов: \n", n);
	PrintMass(mass, n);
	FuncControlSumm(mass, n);
	FuncControlSeries(mass, n);

	printf("\nОтсортированный упорядоченный массив из %i элементов: \n", n);
	ShekerSort(mass, n);
	PrintMass(mass, n);
	FuncControlSumm(mass, n);
	FuncControlSeries(mass, n);
	PrintCM();

	printf("\nМассив обратного порядка из %i элементов: \n", n);
	Revers(mass, n);
	PrintMass(mass, n);
	FuncControlSumm(mass, n);
	FuncControlSeries(mass, n);

	printf("\nОтсортированный массив обратного порядка из %i элементов: \n", n);
	ShekerSort(mass, n);
	PrintMass(mass, n);
	FuncControlSumm(mass, n);
	FuncControlSeries(mass, n);
	PrintCM();
	printf("----------------------------------------------------------");

	return 0;
}