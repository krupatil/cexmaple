#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int find_right_most_bit_pos(int x)
{
	int bit_pos = 0;

	for(int i = 0; i < sizeof(x) * 8; i++)
	{
		if(x & (1 << i))
			bit_pos = i;
	}
	printf("Bit Pos: %d\n", bit_pos);
	return bit_pos;
}

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

int create_mask(int s, int e)
{
	int mask = 0;
	for(int i = s; i <= e; i++)
		mask = mask | (1 << i);
	printf("Mask:   ");
	print_binary(mask);
	return mask;
}

int get_bits(int a, int s, int e)
{
	int mask = create_mask(s, e);
	return a & mask;
}

int main()
{
	int input  = 0x91;
	int res = 0;
	int start = 2, end = 5;
	printf("Range: Start: %d End: %d\n", start, end);
	(void)find_right_most_bit_pos(input);
	printf("Input:  ");
	print_binary(input);
	res = get_bits(input, start, end);
	printf("Output: ");
	print_binary(res);
}
