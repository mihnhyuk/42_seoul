#include "libft.h"
#include <stdio.h>

int	main(void)
{
	char	*a = "1237";
	char	*b = "1233";

	printf("%d", ft_memcmp(a, b, 4));
	return (0);
}
