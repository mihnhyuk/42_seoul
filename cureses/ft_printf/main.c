#include<stdarg.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>




int	ft_printf(const char * str, ...)
{
	va_list ap;
	va_start(ap, str);

	char *token;
	token = NULL;
	var_to_token(&token, 'X', ap);

	printf("%s\n", token);

	free(token);

	return(1);
}

int main(){
	int a = 12;

	ft_printf("123", a);

}
