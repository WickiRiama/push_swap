/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriant <mriant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 11:01:26 by mriant            #+#    #+#             */
/*   Updated: 2022/03/01 17:38:57 by mriant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

int	ft_setfirst(t_list *list)
{
	int		first;
	int		med;
	
	first = 0;
	med = ft_lstsize(*a_list) / 2;
	while (list && list->content->index > med)
	{
		first++;
		list = list->next;
	}
	if (first >= ft_lstsize(list)
		return (-1);
	return (first);
}

int	ft_setlast(t_list *list)
{
	int	last;
	int	med;

	last = 1;
	med = ft_lstsize(*a_list) / 2;
	while (list)
	{
		if (list->content->index <= med)
			last = 0;
		last++;
		list = list->next;
		return (last);
	}
}

void	ft_smartrotate(t_list **list, int first, int last)
{
	if (first < last)
	{
		while (first)
		{
			ft_printf("ra\n");
			ft_rotate(a_list);
			first--;
		}
	}
	else
	{
		while (last)
		{
			ft_printf("rra\n");
			ft_rrotate(a_list);
			last--;
		}
	}
}


void	ft_insert_a(t_list **a_list, t_list **b_list)
{
	t_list	*temp;
	int		first;
	int		last;

	first = ft_setfirst(*a_list);
	while (first > -1)
	{
		last = ft_setlast(*a_list);
		ft_smartrotate(a_list, first, last);
		ft_printf("pb\n");
		ft_push(a_list, b_list);
		first = ft_setfirst(*a_list);
	}
	while (*a_list)
	{
		ft_printf("pb\n");
		ft_push(a_list, b_list);
	}
}
