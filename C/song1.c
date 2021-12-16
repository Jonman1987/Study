#include <stdio.h>
#include <string.h>

char tracks[][80] = {
		"I lost my hearth",
		"New York is the city",
		"Dance with man",
		"From to this",
		"Girl from Island"
	};

void find_track(char search_for[])
{
	int i;
	for(i=0; i<5; i++)
	{
		if (strstr(tracks[i], search_for))
			printf("Song # %i: '%s'\n", i+1, tracks[i]);
	}
}

int main()
{
	char search_for[80];
	printf("Search: ");
	fflush(stdout);
	scanf("%79s", search_for);
	find_track(search_for);
	return 0;
}