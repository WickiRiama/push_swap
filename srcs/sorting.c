/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriant <mriant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 14:22:26 by mriant            #+#    #+#             */
/*   Updated: 2022/03/04 10:01:56 by mriant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	ft_sort2(t_list *list)
{
	if (((t_content *)list->content)->index
		> ((t_content *)list->next->content)->index)
		ft_printf("sa\n");
}

void	ft_sort3(t_list **list, int n0, int n1, int n2)
{
	if (n0 < n1)
	{
		if (n1 > n2)
		{
			ft_do_op(list, NULL, "rra");
			if (n0 < n2)
				ft_do_op(list, NULL, "sa");
		}
	}
	else
	{
		if (n1 < n2)
		{
			if (n0 < n2)
				ft_do_op(list, NULL, "sa");
			else
				ft_do_op(list, NULL, "ra");
		}
		else
		{
			ft_do_op(list, NULL, "sa");
			ft_do_op(list, NULL, "rra");
		}
	}
}

int	ft_sortbig(t_list **a_list, t_list **b_list)
{
	int	radix;

	radix = 0;
	if (radix == 1)
		ft_radix(a_list, b_list);
	else
	{
		ft_insert_a(a_list, b_list);
		ft_sort3(a_list, ((t_content *)(*a_list)->content)->index,
			((t_content *)(*a_list)->next->content)->index,
			((t_content *)(*a_list)->next->next->content)->index);
		if (ft_insert_b(a_list, b_list) == 1)
			return (1);
	}
	return (0);
}

int	ft_sort(t_list **a_list, t_list **b_list)
{
	int	len;

	if (ft_checksorted(*a_list, -1) == 1)
		return (0);
	len = ft_lstsize(*a_list);
	if (len == 2)
		ft_sort2(*a_list);
	if (len == 3)
		ft_sort3(a_list, ((t_content *)(*a_list)->content)->index,
			((t_content *)(*a_list)->next->content)->index,
			((t_content *)(*a_list)->next->next->content)->index);
	if (len > 3)
	{
		if (ft_sortbig(a_list, b_list) == 1)
			return (1);
	}
	return (0);
}
