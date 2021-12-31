/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhjang  <minhjang@student.42seoul.k      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 00:13:56 by minhjang          #+#    #+#             */
/*   Updated: 2021/09/24 00:13:56 by minhjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_print_memory(void *str, int size);

int	main(){

	char *a ="Bonjour les aminches\t\t\tc est fou\ttout\tce qu onpeut ";
	ft_print_memory( a, 53);
}
