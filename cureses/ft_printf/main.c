#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include"./includes/ft_printf.h"
#include<string.h>

int	main(void)
{
	ft_printf("%p\n", (void *)0);
	printf("%p\n", (void *)0);
}
