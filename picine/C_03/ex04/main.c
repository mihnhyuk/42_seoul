#include <stdio.h>

char 	*ft_strstr(char *str, char *to_find);

int main(){
	char *a = "abcd";
	char *b = "dbc";

	char *result;

	result = ft_strstr(a,b);
	
	if(result)
		printf("NULL");
	else
		printf("%s", result);
}
