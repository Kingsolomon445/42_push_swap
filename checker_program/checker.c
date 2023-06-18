/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofadahun <ofadahun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 08:05:48 by ofadahun          #+#    #+#             */
/*   Updated: 2023/06/03 12:58:13 by ofadahun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	eval_moves(char	*move, t_slist **top_a, t_slist **top_b)
{
	if (ft_strcmp(move, "ra") == 0)
		rotate(top_a);
	else if (ft_strcmp(move, "rb") == 0)
		rotate(top_b);
	else if (ft_strcmp(move, "rr") == 0)
		rotate_both(top_a, top_b);
	else if (ft_strcmp(move, "rra") == 0)
		reverse_rotate(top_a);
	else if (ft_strcmp(move, "rrb") == 0)
		reverse_rotate(top_b);
	else if (ft_strcmp(move, "rrr") == 0)
		reverse_rotate_both(top_a, top_b);
	else if (ft_strcmp(move, "sa") == 0)
		swap(top_a);
	else if (ft_strcmp(move, "sb") == 0)
		swap(top_b);
	else if (ft_strcmp(move, "pa") == 0)
		push(top_a, top_b);
	else if (ft_strcmp(move, "pb") == 0)
		push(top_b, top_a);
}

int	checker(char *moves, t_slist **top_a)
{
	t_slist	*top_b;
	char	**moves_split;
	int		i;

	top_b = NULL;
	if (moves)
	{
		moves_split = ft_split(moves, '\n');
		moves = free_str(moves);
		if (!moves_split)
			return (free_all(top_a), 0);
		if (!are_moves_valid(moves_split))
			return (free_all(top_a), free_arg_split(moves_split), \
			write(2, "Error\n", 6), 0);
		i = -1;
		while (*(moves_split + (++i)))
			eval_moves(*(moves_split + i), top_a, &top_b);
		free_arg_split(moves_split);
	}
	if (is_in_order(top_a) && is_empty(&top_b))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	return (free_all(top_a), free_all(&top_b), 1);
}

char	*read_instructions(t_slist **top_a, int fd)
{
	char	*move;
	char	*moves;

	moves = NULL;
	move = get_next_line(fd);
	while (move)
	{
		moves = ft_modstrjoin(moves, move);
		if (!moves)
		{
			free(move);
			free_all(top_a);
			exit(EXIT_FAILURE);
		}
		free(move);
		move = get_next_line(fd);
	}
	move = free_str(move);
	return (moves);
}

int	main(int argc, char *argv[])
{
	t_slist	*top_a;
	int		i;
	int		fd;
	char	*moves;

	fd = 0;
	top_a = NULL;
	if (argc < 2)
		return (0);
	i = 0;
	while (argv[++i])
	{
		if (!eval_args(&top_a, argv[i]))
			return (free_all(&top_a), write(2, "Error\n", 6), 1);
	}
	if (is_empty(&top_a) || check_for_duplicates(&top_a))
		return (free_all(&top_a), write(2, "Error\n", 6), 1);
	map_lst(&top_a);
	moves = read_instructions(&top_a, fd);
	if (!moves && is_in_order(&top_a))
		return (ft_printf("OK\n"), free_all(&top_a), 0);
	else if (!moves && !is_in_order(&top_a))
		return (ft_printf("KO\n"), free_all(&top_a), 0);
	checker(moves, &top_a);
	return (0);
}
