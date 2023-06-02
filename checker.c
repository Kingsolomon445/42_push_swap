/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofadahun <ofadahun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 08:05:48 by ofadahun          #+#    #+#             */
/*   Updated: 2023/06/02 15:07:02 by ofadahun         ###   ########.fr       */
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

int	checker(char *moves, t_slist **top_a, t_slist **top_b)
{
	char	**moves_split;
	int		i;

	if (moves)
	{
		moves_split = ft_split(moves, '\n');
		free_str(moves);
		if (!moves_split)
			return (0);
		if (!are_moves_valid(moves_split))
			return (free_arg_split(moves_split), write(2, "Error\n", 6), 0);
		i = 0;
		while (*(moves_split + i))
		{
			eval_moves(*(moves_split + i), top_a, top_b);
			i++;
		}
		free_arg_split(moves_split);
	}
	if (is_in_order(top_a) && is_empty(top_b))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	return (1);
}

// int main(int argc, char *argv[])
// {
// 	t_slist *top_a;
// 	t_slist *top_b;
// 	int		i;
// 	int		fd;
// 	char	*move;
// 	char	*moves;

// 	top_b = NULL;
// 	moves = NULL;
// 	fd = 0;
// 	if (argc < 2)
// 		return (0);

// 	i = 1;
// 	while (argv[i])
// 	{
// 		if (!eval_args(&top_a, argv[i]))
// 			return (free_all(&top_a), write(2, "Error\n", 6), 1);
// 		i++;
// 	}
// 	if (check_for_duplicates(&top_a))
// 		return (free_all(&top_a), write(2, "Error\n", 6), 1);
// 	map_lst(&top_a);
// 	move = get_next_line(fd);
// 	while (move)
// 	{
// 		moves = ft_modstrjoin(moves, move);
// 		if (!moves)
// 			return (free_all(&top_a), 1);
// 		free(move);
// 		move = get_next_line(fd);
// 	}
// 	if (!checker(moves, &top_a, &top_b))
// 		return (free_all(&top_a), free_all(&top_b), 1);
// 	free_all(&top_a);
// 	free_all(&top_b);
// 	return (0);
// }