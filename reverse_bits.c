#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void print_binary(int x)
{
	for(int i = ((sizeof(int) * 8) - 1); i >=0; i--)
	{
		if(x & (1 << i))
			printf("1");
		else
			printf("0");
	}
	printf("\n");
}

int reverse_bits(int a)
{
	int res = 0;
	int max = sizeof(int) * 8;
	for(int i = 0; i < max; i++)
	{
		if(a & (1 << i))
			res = res | (1 << ((max - 1) - i));
	}
	return res;
}

int main()
{
	int a   = 0x1001;
	int res = 0;

	res = reverse_bits(a);
	printf("Input : ");
	print_binary(a);
	printf("Output: ");
	print_binary(res);
}
