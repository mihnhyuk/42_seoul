#include<stdio.h>
unsigned int	ft_strlcat(char *str1, char *str2, unsigned int size);

int main(){
	char a[20] = "abadef";
	char b[10] = "de";
	
	printf("%i",ft_strlcat(a, b, 7));
}
