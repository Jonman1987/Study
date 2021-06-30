#include <stdio.h>

void skip(char *msg)
{
	puts(msg+3);
}
int main()
{
	char *msg_from_amy = "Не звони мне";
	skip(msg_from_amy);
	return 0;
}