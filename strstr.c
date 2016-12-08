#include <stdio.h>
#include <string.h>

char * mystrstr(char *str, char *match)
{
	char *temp = NULL;
	char *pattern = match;

	while(str)
	{
		temp = str;
		pattern = match;
		while(temp && pattern) {
			if(*temp != *pattern)
				break;
			temp++;
			pattern++;
		}
		if(*pattern == '\0')
			break;
		str++;
	}
	return str;
}

int main()
{
	char str[256] = {0};
	char pattern[256] = {0};
	strcpy(str, "Hello World");
	strcpy(pattern, "ll");

	printf("%s\n", mystrstr(str, pattern));
}
