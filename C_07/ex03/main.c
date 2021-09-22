#include <stdio.h>

char	*ft_strjoin(int size, char **strs, char *sep);

int main(){
	
	char *strs[3] = {"Hello!", "World!", "Nice"};
	char *sep = "--:--";
	char *result;

	result = ft_strjoin(3, strs, sep);

	printf("%s", result);
}
