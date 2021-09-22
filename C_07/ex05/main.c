#include <stdio.h>

char	**ft_split(char *str, char *charset);

int	main(){
	char *a = "hexllox2hellox3helxlo";
	char *b = "x";
	char **result;
	result = ft_split(a, b);
	for(int i = 0 ; result[i] != 0 ; i++)
	{
		printf("%s\n", result[i]);
	}
}
