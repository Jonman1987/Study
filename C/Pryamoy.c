#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int ContSumm, Serial, summ, C, M;

void SummAndSeria(int *a, int SIZE)
{
	ContSumm=ContSumm + a[SIZE];

		 if(a[SIZE]<a[SIZE-1])
		 {
		 	Serial++;
		 }
}

void PrintMass(int *a, int SIZE)
{
	int i;
	Serial=1; ContSumm=0;
	for (i=0; i<SIZE; i++)
	{
		 printf("%i ", a[i]);
	}
}

void PrintSummAndSeria()
{
	printf("\nКонтрольная сумма: %i", ContSumm);
	printf("\nКоличество серий: %i\n", Serial);
}

void PrintMandC()
{
	printf("\nКоличество операций пересылки: %i", M);
	printf("\nКоличество операций сравнения: %i\n", C);
}

void PerevorotMassiva(int *a, int SIZE)
{
	int i;
	for (i=0; i<SIZE/2; i++)
	{
		int tmp_mass;
		tmp_mass=a[i];
		a[i]=a[SIZE-1-i];
		a[SIZE-1-i]=tmp_mass;
	}
}

void MassRand(int *a, int SIZE)
{
	int i;
	
	srand(time(0));
		for (i=0; i<SIZE; i++)
		{
			 a[i] = rand() % 100;
			 printf("%d ", a[i]);
			 SummAndSeria(a, i);
		}
}

void SortPryamoyVibor(int *a, int SIZE)
{
	int i, j, tmp, minnumb;
	M=0;
	C=0;
	for (int i = 0; i < SIZE-1; i++)
    {
    	minnumb=i;
        for (int j = i + 1; j < SIZE; j++)
        {
        	C++;
            if (a[minnumb] > a[j])
            {
                minnumb = j;
               
            }
            
         }
         		
        		tmp = a[minnumb];
        		a[minnumb] = a[i];
        		a[i] = tmp;
        		M+=3;
    }
}

int main()
{
	
	
	int n=10; //Число элементов в массиве
	int mass[n];
	int i;
	Serial=1; ContSumm=0;

	printf("Случайный массив из %i элементов \n\n", n);
	MassRand(mass, n);
	PrintSummAndSeria();
	SortPryamoyVibor(mass, n);
	printf("\nОтсортированный массив из %i элементов \n\n", n);
	PrintMass(mass, n);
	PrintSummAndSeria();

	PrintMandC();
	printf("\n");
	SortPryamoyVibor(mass, n);
	PrintMass(mass, n);
	PrintSummAndSeria();
	PrintMandC();
	printf("\n\n");
	PerevorotMassiva(mass, n);
	
	PrintMass(mass, n);
	SortPryamoyVibor(mass, n);
	PrintSummAndSeria();
	PrintMandC();
	printf("\n\n");
	return 0;
}


