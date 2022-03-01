/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriant <mriant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 14:22:26 by mriant            #+#    #+#             */
/*   Updated: 2022/03/01 11:26:13 by mriant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	ft_sort2(t_list *list)
{
	if (*(int *)list->content > *(int *)list->next->content)
		ft_printf("sa\n");
}

void	ft_sort3(t_list *list)
{
	if (*(int *)list->content < *(int *)list->next->content)
	{
		if (*(int *)list->next->content > *(int *)list->next->next->content)
		{
			ft_printf("rra\n");
			if (*(int *)list->content < *(int *)list->next->next->content)
				ft_printf("sa\n");
		}
	}
	else
	{
		if (*(int *)list->next->content < *(int *)list->next->next->content)
		{
			if (*(int *)list->content < *(int *)list->next->next->content)
				ft_printf("sa\n");
			else
				ft_printf("ra\n");
		}
		else
			ft_printf("sa\nrra\n");
	}
}

void	ft_sortbig(t_list **a_list, t_list **b_list)
{
	int	i;
	int	radix;

	radix = 1;
	if (radix == 1)
		ft_radix(a_list, b_list);
	else
	{	
		i = 100;
		ft_insert(a_list, b_list, i);
	}
}

int	ft_sort(t_list **a_list, t_list **b_list)
{
	int	len;

	len = ft_lstsize(*a_list);
	if (len == 2)
		ft_sort2(*a_list);
	if (len == 3)
		ft_sort3(*a_list);
	if (len > 3)
		ft_sortbig(a_list, b_list);
	return (0);
}
