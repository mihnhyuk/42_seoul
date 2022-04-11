/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhjang <minhjang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 17:27:26 by minhjang          #+#    #+#             */
/*   Updated: 2022/04/11 15:02:16 by minhjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>
# define OPEN_MAX 1024

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
#  endif

typedef struct s_readword
{
	struct s_readword		*next;
	struct s_readword		*start;
	int						fd;
	int						length;
	char					buf[BUFFER_SIZE];
}t_readword;
char		*get_next_line(int fd);
t_readword	*add_lst(int fd, t_readword *start);
int			write_lst(int fd, t_readword **iter,
				char token[BUFFER_SIZE], int idx);
char		*lst_to_str(t_readword *lst);
int			get_strlen(t_readword *lst, int counter);
int			copy_lst(t_readword *lst, char **str, int idx);
void		*free_lst(t_readword *lst);
int			clear(char remain[BUFFER_SIZE], int idx);
#endif
