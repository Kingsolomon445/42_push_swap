/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofadahun <ofadahun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 13:03:58 by ofadahun          #+#    #+#             */
/*   Updated: 2023/06/03 12:43:56 by ofadahun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif //BUFFER_SIZE

# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
# include "../ft_printf/ft_printf.h"

typedef struct ls_list
{
	int				data;
	int				map;
	struct ls_list	*next;
}	t_slist;

t_slist	*lstnew(int data);
int     lstsize(t_slist *lst);
void	lstadd_back(t_slist **lst, t_slist *new);

int		ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
void	*ft_memset(void *s, int c, size_t len);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
char	*get_next_line(int fd);

int		ft_strcmp(const char *s1, const char *s2);
char	*free_str(char *str);
char	*ft_modstrjoin(char *old_str, char *move);
int		are_moves_valid(char **moves);

void	swap(t_slist **top);
void	push(t_slist **top_first, t_slist **top_second);
void	rotate(t_slist **top);
void	reverse_rotate(t_slist **top);
void	swap_both(t_slist **top_a, t_slist **top_b);
void	rotate_both(t_slist **top_a, t_slist **top_b);
void	reverse_rotate_both(t_slist **top_a, t_slist **top_b);

void	free_all(t_slist **top);
void	free_arg_split(char **arg_split);
int		eval_args(t_slist **top, char *arg);
int		check_for_duplicates(t_slist **top);
long	ft_atol(const char *str);
void	map_lst(t_slist **top_a);
void	free_arg_split(char **arg_split);
int     is_empty(t_slist **top);
int     is_in_order(t_slist **top_a);
void	do_if_alloc_fails(t_slist **top_a, t_slist **top_b);

#endif //CHECKER_H