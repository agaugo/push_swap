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

void	ft_lstclear(t_stack **stack)
{
	t_stack	*next_temp;
	t_stack	*node;

	if (!*stack)
		return ;
	node = *stack;
	while (node != NULL)
	{
		next_temp = node->next;
		free(node);
		node = next_temp;
	}
}
