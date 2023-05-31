/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofadahun <ofadahun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 14:46:01 by ofadahun          #+#    #+#             */
/*   Updated: 2023/05/31 17:59:16 by ofadahun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	customized_small_elem_sort(t_slist **top_a, t_slist **top_b)
{
	int		smallest_position;
	int		to_rotate;
	int		to_reverse_rotate;

	while (!is_in_order(top_a) && lstsize(*top_a) > 3)
	{
		smallest_position = get_position(top_a, find_smallest(top_a));
		to_rotate = smallest_position - 0;
		to_reverse_rotate = lstsize(*top_a) - smallest_position + 2;
		r_or_rr_action(to_rotate, to_reverse_rotate, top_a, 'a');
		if (is_in_order(top_a))
			return ;
		push(top_b, top_a, 'b');
	}
	if (!is_in_order(top_a))
		sort_three(top_a);
}
/*
Splits to chunk then moves all to b chunk after chunk
Moves the largest elem to top of b and pushes to a until b is empty*/
void	sort(t_slist **top_a)
{
	int		start_chunk;
	int		end_chunk;
	int		chunks;
	int		one_fifth;
	int		size;
	t_slist	*top_b;

	top_b = NULL;
	chunks = get_chunks_size(top_a);
	start_chunk = 1;
	size = lstsize(*top_a);
	end_chunk = lstsize(*top_a) / chunks;
	one_fifth = lstsize(*top_a) / chunks;
	while (lstsize(*top_a) > 10 && !is_in_order(top_a))
	{
		move_chunk_from_a_to_b(top_a, &top_b, start_chunk, end_chunk);
		start_chunk = end_chunk + 1;
		end_chunk += one_fifth;
		if (end_chunk >= size - 9)
			end_chunk = size - 10;
	}
	customized_small_elem_sort(top_a, &top_b);
	push_from_b_to_a(top_a, &top_b);
}

//Insertion Sort algorithm
//Cant decide precisely what the complexity is but somewhere between 0(n log(n)) and 0(n^2)
int	main(int argc, char *argv[])
{
	t_slist	*head_a;
	int		i;

	if (argc < 2)
		return (0);
	i = 0;
	head_a = NULL;
	while (argv[++i])
	{
		if (!eval_args(&head_a, argv[i]))
			return (free_all(&head_a), write(2, "Error\n", 6), 1);
	}
	if (is_empty(&head_a) || check_for_duplicates(&head_a))
		return (free_all(&head_a), write(2, "Error\n", 6), 1);
	if (is_in_order(&head_a))
		return (free_all(&head_a), 0);
	map_lst(&head_a);
	if (lstsize(head_a) == 3)
		sort_three(&head_a);
	else if (lstsize(head_a) == 5)
		sort_five(&head_a);
	else
		sort(&head_a);
	// print_all(&head_a);
	return (free_all(&head_a), 0);
}
