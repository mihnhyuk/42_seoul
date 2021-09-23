#include <stdio.h>

int	*ft_range(int min, int max);

int	main()
{
	int *ary = ft_range(5, 10);

	for (int i = 0 ; i < 5 ; i++)
	{
		printf("%d",ary[i]);
	}
}
