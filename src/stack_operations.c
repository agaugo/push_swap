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
#include <stdio.h>

/*
swap(stack, id)

sa (swap a): Swap the first 2 elements at the top of stack a. 
	Do nothing if there is only one or no elements.
sb (swap b): Swap the first 2 elements at the top of stack b. 
	Do nothing if there is only one or no elements.
ss : sa and sb at the same time.
*/

void	swap(t_stack **stack, char id)
{
	t_stack	*second;

	second = (*stack)->next;
	(*stack)->next = second->next;
	second->next = (*stack);
	(*stack) = second;
	if (id != 'x')
	{
		ft_putchar_fd('s', 1);
		ft_putchar_fd(id, 1);
		ft_putchar_fd('\n', 1);
	}
}

/*
push (stack a, stack b, id)

pa (push a): Take the first element at the top of b and put it at the top of a. 
	Do nothing if b is empty.
pb (push b): Take the first element at the top of a and put it at the top of b. 
	Do nothing if a is empty.
*/

void	push(t_stack **source, t_stack **target, char id)
{
	t_stack	*new_node;

	new_node = ft_lstnew((*source)->content, (*source)->index);
	ft_lstadd_front(target, new_node);
	ft_delfirst(source);
	ft_putchar_fd('p', 1);
	ft_putchar_fd(id, 1);
	ft_putchar_fd('\n', 1);
}

//rotate(stack, id)
void	rotate(t_stack **stack, char id)
{
	t_stack	*last_node;
	t_stack	*first_node;

	if (ft_lstsize(*stack) > 1)
	{
		first_node = *stack;
		last_node = *stack;
		*stack = (*stack)->next;
		while (last_node->next != NULL)
			last_node = last_node->next;
		last_node->next = first_node;
		first_node->next = NULL;
	}
	ft_putchar_fd('r', 1);
	ft_putchar_fd(id, 1);
	ft_putchar_fd('\n', 1);
}

//rev_rotate(stack, id)

void	rev_rotate(t_stack **stack, char id)
{
	t_stack	*first_node;
	t_stack	*new_last;
	t_stack	*last_node;

	first_node = *stack;
	last_node = first_node;
	new_last = first_node;
	while (last_node->next != NULL)
		last_node = last_node->next;
	last_node->next = first_node;
	while (new_last->next != last_node)
		new_last = new_last->next;
	new_last->next = NULL;
	*stack = last_node;
	ft_putstr_fd("rr", 1);
	ft_putchar_fd(id, 1);
	ft_putchar_fd('\n', 1);
}

int	in_order(t_stack **stack)
{
	t_stack	*node;
	t_stack	*next;

	node = *stack;
	next = node->next;
	while (next != NULL)
	{
		if ((ft_atoi(node->content) > ft_atoi(next->content)))
			return (0);
		node = node->next;
		next = next->next;
	}
	return (1);
}
