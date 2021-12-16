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
	for (i=0; i<SIZE; i++)
	{
		 printf("%i ", a[i]);
	}
}

void PrintSummAndSeria()
{
	printf("\n%i ", ContSumm);
	printf("\n%i\n ", Serial);
}

void PrintMandC()
{
	printf("\n%i ", C);
	printf("\n%i ", M);
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

void BubbleSort(int *a, int SIZE)
{
	int i;
	for (int i = 1; i < SIZE; i++)
    {
    	int j, tmp;
        for (int j = 1; j < SIZE; j++)
        {
        	
            if (a[j] < a[j-1])
            {
            	
                tmp = a[j];
                a[j] = a[j-1];
                a[j-1] = tmp;
            }
         }
         		
        		
        		
    }
}

int main()
{
	int n=100; //Число элементов в массиве
	int mass[n];
	int i;

	Serial=1;

	MassRand(mass, n);

	PrintSummAndSeria();

	M=0; C=0;

	BubbleSort(mass, n);

	Serial=1; ContSumm=0;
	for (i=0; i<n; i++)
		{
			 printf("%d ", mass[i]);
			 SummAndSeria(mass, i);
		}
	PrintSummAndSeria();
	PrintMandC();
	printf("\n");
	M=0; C=0;
	BubbleSort(mass, n);
	PrintMass(mass, n);
	PrintSummAndSeria();
	PrintMandC();
	printf("\n\n");
	PerevorotMassiva(mass, n);
	PrintMass(mass, n);
	M=0; C=0;
	BubbleSort(mass, n);
	PrintSummAndSeria();
	PrintMandC();
	printf("\n\n");
	return 0;
}


