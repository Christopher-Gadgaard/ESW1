#include <stdio.h>
#include "calculator.h"

int n1 = 7;
int n2 = 3;

int main(void)
{
	printf("7/3=%d\n", div(7, 3));
	printf("7%%3=%d\n", mod(7, 3));

	printf("%d\n", n1 / n2);
	printf("%d\n", n1 % n2);

}