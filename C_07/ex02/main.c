#include <stdio.h>

int	ft_ultimate_range(int ** ary, int min, int max);

int	main()
{
	int *ary;
	printf("%d", ft_ultimate_range(&ary, 5, 10));

	for (int i = 0 ; i < 5 ; i++)
	{
		printf("%d",ary[i]);
	}
}
