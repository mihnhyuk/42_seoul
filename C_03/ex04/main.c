#include <stdio.h>
#include <string.h>

char	*ft_strstr(char *str, char *to_find);

int main(){
	
	char *a = "abcdefg";
	char *b = "zz";
	
	printf("%s\n%s", strstr(a, b), ft_strstr(a, b));
	

}
