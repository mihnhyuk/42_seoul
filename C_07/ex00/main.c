#include <stdio.h>
char	*ft_strdup(char *src);

int	main(){
	char *str = "abc";
	char *str2;

	str2 = ft_strdup(str);
	printf("%s", str2);
}
