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
                m+=3;
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
    	c=c+1;
      if (h[i] > h[i + 1])
      {    
        int t = h[i];
        h[i] = h[i + 1];
        h[i + 1] = t;
        flagSort = 1;
        m+=3;
      }
    }
    right--;
    for (int i = right; i>left; i--)
    {
    	c=c+1;
      if (h[i - 1]>h[i])
      {
        int t = h[i];
        h[i] = h[i - 1];
        h[i - 1] = t;
        flagSort = 1;
        m+=3;
      }
    }
    left++;
  }
}

void ShellSort(int *k, int count6)
{
    int i, j, step;
    int tmp;
    for (step = count6 / 2; step > 0; step /= 2)
        for (i = step; i < count6; i++)
        {
            tmp = k[i];
            for (j = i; j >= step; j -= step)
            {
                if (tmp < k[j - step])
                    k[j] = k[j - step];
                else
                    break;
            }
            k[j] = tmp;
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

void VivodStraightSort(int n)
{
	system("clear");
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
}

void VivodBubleSort(int n)
{
	system("clear");
	//bublesort
	int mass[n];
	MassRand(mass, n);

	printf("Случайный массив из %i элементов: \n", n);
	PrintMass(mass, n);
	FuncControlSumm(mass, n);
	FuncControlSeries(mass, n);

	printf("\nОтсортированный случайный массив из %i элементов: \n", n);
	ShellSort(mass, n);
	PrintMass(mass, n);
	FuncControlSumm(mass, n);
	FuncControlSeries(mass, n);
	PrintCM();

	printf("\nУпорядоченный массив из %i элементов: \n", n);
	PrintMass(mass, n);
	FuncControlSumm(mass, n);
	FuncControlSeries(mass, n);

	printf("\nОтсортированный упорядоченный массив из %i элементов: \n", n);
	ShellSort(mass, n);
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
	ShellSort(mass, n);
	PrintMass(mass, n);
	FuncControlSumm(mass, n);
	FuncControlSeries(mass, n);
	PrintCM();
	printf("----------------------------------------------------------\n");
}

void VivodShakerSort(int n)
{
	//Shakersort
	system("clear");
	int mass[n];
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
}

int main()
{
	int n;
	char p;
	system("clear");
	while(1)
	{
	printf("Введите размерность массива: ");
	fflush(stdout);
	scanf("%i", &n);
	fflush(stdin);
	printf("\nМеню");
	printf("\n1 - Сортировка методом прямого выбора");
	printf("\n2 - Сортировка методом Шелла");
	printf("\n3 - Шейкерная сортировка");
	printf("\n4 - Выход");
	printf("\nВведите тип сортировки: ");
    fflush(stdout);
    scanf("%c", &p);
    switch (p)
    { 
      case '1': VivodStraightSort(n); break;

      case '2': VivodBubleSort(n); break;

      case '3': VivodShakerSort(n); break;

      case '4': return 0;

      default : printf("Неверный режим");
      fflush(stdout);
    }
  }
	return 0;
}