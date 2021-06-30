#include <stdio.h>

void go_south_east (int *lat, int *lon)
{
	(*lat)--; // *lat--; Почему не работает?
	*(lon)++; // *lon++; Почему не работает?
}

int main()
{
	int latitude = 32;
	int longitude = -64;
	go_south_east(&latitude, &longitude);
	printf("Стоп! Теперь наши координаты: [%i, %i]\n", latitude, longitude);
	return 0;
}