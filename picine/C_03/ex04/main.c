/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhjang  <minhjang@student.42seoul.k      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 07:53:13 by minhjang          #+#    #+#             */
/*   Updated: 2021/09/21 07:53:13 by minhjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
