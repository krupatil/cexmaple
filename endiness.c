#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int main()
{
	unsigned int i = 1;
	char *p = (char *) &i;
	
	if(*p & 1)
		printf("Little endine\n");
	else
		printf("Big endine.\n");
}
