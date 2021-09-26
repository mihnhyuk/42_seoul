#include <stdio.h>

char	*ft_convert_base(char *nbr, char *base_from, char *base_to);

int	main(){
	char *a = "-+2147483648";
	char *base_from = "0123456789";
	char *base_to = "01";
	char *result;

	result = ft_convert_base(a, base_from, base_to);
	printf("%s", result);
	

}
