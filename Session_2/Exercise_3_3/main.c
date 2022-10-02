#include <stdio.h>

int power(int x, int y)
{
	int i;
	int number = 1; 

	for (i = 0; i < y; ++i)
		number *= x;

	return number;
}

void multiswap(int* x, int* y, int* z)
{
	int temp;
	temp = *x;
	*x = *z;
	*z = *y;
	*y = temp;
}

main()
{
	printf("2^3=%d \n", power(2, 3));

	int a = 1;
	int b = 2;
	int c = 3;

	printf("a=%d b=%d c=%d \n", a, b, c);

	multiswap(&a, &b, &c);

	printf("a=%d b=%d c=%d \n", a, b, c);
}