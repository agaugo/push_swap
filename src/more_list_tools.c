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

t_stack	*ft_lstnew(void *content, int index)
{
	t_stack	*node;

	node = (t_stack *)malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->content = content;
	if (index == -1)
		node->index = -1;
	else
		node->index = index;
	node->next = NULL;
	return (node);
}

int	ft_lstsize(t_stack *lst)
{
	int		cnt;
	t_stack	*temp;

	temp = lst;
	cnt = 0;
	while (temp != NULL)
	{
		temp = temp->next;
		cnt++;
	}
	return (cnt);
}

void	ft_lstadd_back(t_stack **lst, t_stack *new)
{
	t_stack	*tail;

	if (!new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	tail = ft_lstlast(*lst);
	tail->next = new;
}

void	ft_lstadd_front(t_stack **lst, t_stack *new)
{
	new->next = *lst;
	*lst = new;
}

void	push_all(t_stack **source, t_stack **target, char id)
{
	while (*source)
		push(source, target, id);
}
