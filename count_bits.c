#include <stdio.h>

int main()
{
	int val = 0x00, count = 0;

	scanf("%d", &val);
	
	while(val != 0)
	{
		if((val & 1) == 1)
			count++;
		val = val >> 1;
	}
	printf("Count: %d\n", count);
}
