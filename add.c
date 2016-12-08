#include <stdio.h>

void increment(int *a)
{
	int x = *a, y = 1;
	int carry = 0;
	
	while(y)
	{
		carry = x & y;
		x = x ^ y;
		y = carry << 1;
	}
	
	*a = x;
}

int main()
{
	int x = 1;
	increment(&x);
	printf("%d\n", x);
}
