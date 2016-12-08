#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Returns XOR of x and y
int myXOR(int x, int y)
{
	int res = 0; // Initialize result

	// Assuming 32-bit Integer 
	for (int i = 31; i >= 0; i--)                     
	{
		// Find current bits in x and y
		bool b1 = x & (1 << i);
		bool b2 = y & (1 << i);

		// If both are 1 then 0 else xor is same as OR
		bool xoredBit = (b1 & b2) ? 0 : (b1 | b2);          

		// Update result
		res <<= 1;
		res |= xoredBit;
	}
	return res;
}

// Returns XOR of x and y
int new__myXOR(int x, int y)
{
	int res = 0; // Initialize result

	// Assuming 32-bit Integer 
	for (int i = 0; i < 32; i++)
	{
		// Find current bits in x and y
		bool b1 = x & (1 << i);
		bool b2 = y & (1 << i);

		// If both are 1 then 0 else xor is same as OR
		bool xoredBit = (b1 & b2) ? 0 : (b1 | b2);

		// Update result
		res = res | (xoredBit << i);
	}
	return res;
}


// Driver program to test above function
int main()
{
	int x = 3, y = 5;
	printf("XOR is: %d\n", myXOR(x, y));
	printf("New XOR is: %d\n", new__myXOR(x, y));
	return 0; 
}
