/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: hflohil- <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/14 19:37:46 by hflohil-      #+#    #+#                 */
/*   Updated: 2022/10/14 19:37:46 by hflohil-      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sort_three(t_stack **stack_a)
{
	int	a;
	int	b;
	int	c;

	a = (*stack_a)->index;
	b = (*stack_a)->next->index;
	c = (*stack_a)->next->next->index;
	if (a > b && b < c && a < c)
		swap(stack_a, 'a');
	else if (a > b && b > c && a > c)
	{
		swap(stack_a, 'a');
		rev_rotate(stack_a, 'a');
	}
	else if (a > b && b < c && a > c)
		rotate(stack_a, 'a');
	else if (a < b && b > c && a < c)
	{
		swap(stack_a, 'a');
		rotate(stack_a, 'a');
	}
	else if (a < b && b > c && a > c)
		rev_rotate(stack_a, 'a');
}

void	exactly_five(t_stack **stack_a, t_stack **stack_b, int efficiency)
{
	int	x;
	int	target;

	target = 0;
	x = 2;
	while (x--)
	{
		if (efficiency == 0)
		{
			while ((*stack_a)->index != target)
				rev_rotate(stack_a, 'a');
		}
		else
		{
			while ((*stack_a)->index != target)
				rotate(stack_a, 'a');
		}
		push(stack_a, stack_b, 'b');
		target++;
	}
}

void	sort_five(t_stack **stack_a, t_stack **stack_b)
{
	int	iter_x;
	int	efficiency;

	efficiency = 0;
	if ((*stack_a) == find_highest_index(stack_a))
		efficiency = 1;
	iter_x = ft_lstsize(*stack_a) - 3;
	if (iter_x == 2)
		exactly_five(stack_a, stack_b, efficiency);
	else
	{
		while ((*stack_a)->index != 0)
			rev_rotate(stack_a, 'a');
		push(stack_a, stack_b, 'b');
	}
	sort_three(stack_a);
	while (iter_x--)
		push(stack_b, stack_a, 'a');
}
