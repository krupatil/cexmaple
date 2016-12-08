#include <stdio.h>

void swap(char *x, char *y)
{
	*x = *x + *y;
	*y = *x - *y;
	*x = *x - *y;
}

void swap_xor(char *x, char *y)
{
        *x = *x ^ *y;
        *y = *x ^ *y;
        *x = *x ^ *y;
}

void new_swap(char x, char y)
{
	x = (unsigned int)x + (unsigned int)y;	
	y = (unsigned int)x - (unsigned int)y;	
	x = (unsigned int)x - (unsigned int)y;	
	printf("Output (new_swap) -> X=%d, Y=%d\n", x, y);
}

int main()
{
	char x = 0, y = 128;
	
	new_swap(x, y);
	printf("Input  -> X=%d, Y=%d\n", x, y);
	swap(&x, &y);
	printf("Output -> X=%d, Y=%d\n", x, y);

	swap_xor(&x, &y);
	printf("Output -> X=%d, Y=%d\n", x, y);
}
