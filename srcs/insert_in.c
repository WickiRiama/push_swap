/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_in.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriant <mriant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 13:22:45 by mriant            #+#    #+#             */
/*   Updated: 2022/03/02 13:26:43 by mriant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

int	ft_setfirst(t_list *list, int med)
{
	int		first;
	int		len;

	first = 0;
	len = ft_lstsize(list);
	while (list && ((t_content *)list->content)->index > med)
	{
		first++;
		list = list->next;
	}
	if (first >= len)
		first = -1;
	return (first);
}

int	ft_setlast(t_list *list, int med)
{
	int	last;

	last = 1;
	while (list)
	{
		if (((t_content *)list->content)->index <= med)
			last = 0;
		last++;
		list = list->next;
	}
	return (last);
}

void	ft_smartrotate(t_list **list, int first, int last, char c)
{
	if (first <= last)
	{
		while (first > 0)
		{
			ft_printf("r%c\n", c);
			ft_rotate(list);
			first--;
		}
	}
	else
	{
		while (last)
		{
			ft_printf("rr%c\n", c);
			ft_rrotate(list);
			last--;
		}
	}
}

void	ft_insert_a(t_list **a_list, t_list **b_list)
{
	int		first;
	int		last;
	int		med;

	med = ft_lstsize(*a_list) / 2;
	first = ft_setfirst(*a_list, med);
	while (first > -1)
	{
		last = ft_setlast(*a_list, med);
		ft_smartrotate(a_list, first, last, 'a');
		ft_printf("pb\n");
		ft_push(a_list, b_list);
		first = ft_setfirst(*a_list, med);
	}
	while (ft_lstsize(*a_list) > 3)
	{
		ft_printf("pb\n");
		ft_push(a_list, b_list);
	}
}
