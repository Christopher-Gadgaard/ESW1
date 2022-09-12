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
	*x = *y;
	*y = *z;
	*z = temp;
}

main()
{
	printf("2^3=%d \n", power(2, 3));

	int a = 1;
	int b = 2;
	int c = 3;

	printf("%d %d %d \n", a, b, c);

	multiswap(&a, &b, &c);

	printf("%d %d %d \n", a, b, c);
}