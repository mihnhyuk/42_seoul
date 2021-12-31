/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhjang  <minhjang@student.42seoul.k      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 17:45:30 by minhjang          #+#    #+#             */
/*   Updated: 2021/09/22 17:45:30 by minhjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

struct s_stock_str *ft_strs_to_tab(int ac, char **av);
void ft_show_tab(struct s_stock_str *par);

int	main(int argc, char *argv[]){
	struct s_stock_str *a;
	a = ft_strs_to_tab(argc, argv);
	ft_show_tab(a);
}
