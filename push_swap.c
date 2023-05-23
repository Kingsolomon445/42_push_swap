/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofadahun <ofadahun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 14:46:01 by ofadahun          #+#    #+#             */
/*   Updated: 2023/05/23 14:17:26 by ofadahun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
Splits to chunk then moves all to b chunk after chunk
Moves the largest elem to top of b and pushes to a until b is empty*/
void	sort(t_slist **top_a)
{
	int		start_chunk;
	int		end_chunk;
	int		chunks;
	int		one_fifth;
	t_slist	*top_b;

	top_b = NULL;
	chunks = get_chunks_size(top_a);
	start_chunk = find_smallest(top_a);
	end_chunk = (find_largest(top_a) - find_smallest(top_a)) / chunks;
	one_fifth = end_chunk - start_chunk;
	while (chunks)
	{
		chunks--;
		move_chunk_from_a_to_b(top_a, &top_b, start_chunk, end_chunk);
		start_chunk += one_fifth + 1;
		end_chunk += one_fifth + 1;
	}
	push_from_b_to_a(top_a, &top_b);
}

/*
This works better for less than 25 elements*/
void	sort_less_than_twenty_five(t_slist **top_a)
{
	int		smallest_position;
	int		to_rotate;
	int		to_reverse_rotate;
	t_slist	*top_b;

	top_b = NULL;
	while (!is_empty(top_a))
	{
		smallest_position = get_position(top_a, find_smallest(top_a));
		to_rotate = smallest_position - 0;
		to_reverse_rotate = lstsize(*top_a) - smallest_position + 2;
		r_or_rr_action(to_rotate, to_reverse_rotate, top_a, 'a');
		push(&top_b, top_a, 'b');
	}
	push_from_b_to_a(top_a, &top_b);
}

/*
Sort three elemens using the minimum operations required
Operation to be used depend on the position of the largest element
*/
void	sort_three(t_slist **top_a)
{
	int	largest;
	int	position;

	largest = find_largest(top_a);
	position = get_position(top_a, largest);
	if (position == 3)
		swap(top_a, 'a');
	else if (position == 2)
		reverse_rotate(top_a, 'a');
	else
		rotate(top_a, 'a');
	if (!(is_in_order(top_a)))
		sort_three(top_a);
}

/*
Pushed the two smallest to stack b
Sorts the reamining three in stack a
Push the two smallest back to stack a
*/
void	sort_five(t_slist **top_a)
{
	int		smallest_position;
	int		to_rotate;
	int		to_reverse_rotate;
	t_slist	*top_b;

	top_b = NULL;
	smallest_position = get_position(top_a, find_smallest(top_a));
	to_rotate = smallest_position - 0;
	to_reverse_rotate = lstsize(*top_a) - smallest_position + 2;
	r_or_rr_action(to_rotate, to_reverse_rotate, top_a, 'a');
	if (is_in_order(top_a))
		return ;
	push(&top_b, top_a, 'b');
	smallest_position = get_position(top_a, find_smallest(top_a));
	to_rotate = smallest_position - 0;
	to_reverse_rotate = lstsize(*top_a) - smallest_position + 2;
	r_or_rr_action(to_rotate, to_reverse_rotate, top_a, 'a');
	push(&top_b, top_a, 'b');
	sort_three(top_a);
	push(top_a, &top_b, 'a');
	push(top_a, &top_b, 'a');
}

int	main(int argc, char *argv[])
{
	t_slist	*head_a;
	int		i;

	if (argc < 2)
		return (1);
	i = 0;
	head_a = NULL;
	while (argv[++i])
	{
		if (!eval_args(&head_a, argv[i]))
			return (write(2, "Error\n", 6), 1);
	}
	if (check_for_duplicates(&head_a))
		return (write(2, "Error\n", 6), 1);
	if (is_in_order(&head_a))
		return (free_all(&head_a), 0);
	if (lstsize(head_a) == 3)
		sort_three(&head_a);
	else if (lstsize(head_a) == 5)
		sort_five(&head_a);
	else if (lstsize(head_a) <= 25)
		sort_less_than_twenty_five(&head_a);
	else
		sort(&head_a);
	return (free_all(&head_a), 0);
}
