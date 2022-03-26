#include<stdarg.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include"ft_printf.h"

int	main(void)
{
	int		a;
	char	b;

	a = 31;
	b = 'c';
	ft_printf("%i %s %% ft_printf: %d %c\n", 2, "string", a, b);
}
