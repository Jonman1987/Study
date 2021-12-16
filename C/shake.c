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

void shekerSort(int *a, int SIZE)
{
  int left = 0, right = SIZE - 1; // левая и правая границы сортируемой области массива
  int flag = 1;  // флаг наличия перемещений
  // Выполнение цикла пока левая граница не сомкнётся с правой
  // и пока в массиве имеются перемещения
  while ((left < right) && flag > 0)
  {
    flag = 0;
    for (int i = left; i<right; i++)  //двигаемся слева направо
    {
      if (a[i]>a[i + 1]) // если следующий элемент меньше текущего,
      {             // меняем их местами
        double t = a[i];
        a[i] = a[i + 1];
        a[i + 1] = t;
        flag = 1;      // перемещения в этом цикле были
      }
    }
    right--; // сдвигаем правую границу на предыдущий элемент
    for (int i = right; i>left; i--)  //двигаемся справа налево
    {
      if (a[i - 1]>a[i]) // если предыдущий элемент больше текущего,
      {            // меняем их местами
        double t = a[i];
        a[i] = a[i - 1];
        a[i - 1] = t;
        flag = 1;    // перемещения в этом цикле были
      }
    }
    left++; // сдвигаем левую границу на следующий элемент
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

	shekerSort(mass, n);

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
	shekerSort(mass, n);
	PrintMass(mass, n);
	PrintSummAndSeria();
	PrintMandC();
	printf("\n\n");
	PerevorotMassiva(mass, n);
	PrintMass(mass, n);
	M=0; C=0;
	shekerSort(mass, n);
	PrintSummAndSeria();
	PrintMandC();
	printf("\n\n");
	return 0;
}


