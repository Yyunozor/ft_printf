#include "ft_printf.h"
#include <stdio.h>

int main(void)
{
	printf("%02.7x", 3267);
	printf("\n");
	ft_printf("%02.7x", 3267);
	printf("\n");

	return 0;
}