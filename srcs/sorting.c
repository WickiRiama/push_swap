/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriant <mriant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 14:22:26 by mriant            #+#    #+#             */
/*   Updated: 2022/02/23 17:55:16 by mriant           ###   ########.fr       */
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

void	ft_radix(t_list **a_list, t_list **b_list, unsigned int shift)
{
	int	nb;
	int	len;
	int	i;

	len = ft_lstsize(*a_list);
	i = 0;
	while (i < len)
	{
		if (ft_checksorted(*a_list, -1) == 1)
			break ;
		nb = *(int *)(*a_list)->content >> shift & 1;
		if ((nb == 0 && shift < sizeof(int) * 8 - 1)
			|| (nb == 1 && shift == sizeof(int) * 8 - 1))
		{
			ft_printf("pb\n");
			ft_push(a_list, b_list);
		}
		else if ((*a_list)->next)
		{
			ft_printf("ra\n");
			ft_rotate(a_list);
		}
		i++;
	}
	if (*b_list)
	{
		i = 0;
		len = ft_lstsize(*b_list);
		shift ++;
		if (ft_checkb(*b_list, shift) == 1 && shift < sizeof(int) * 8 - 1)
			return ;
		while (i < len)
		{
			nb = *(int *)(*b_list)->content >> shift & 1;
			if ((nb == 1 && shift < sizeof(int) * 8 - 1)
				|| (nb == 0 && shift == sizeof(int) * 8 - 1)
				|| shift > sizeof(int) * 8 - 1)
			{
				ft_printf("pa\n");
				ft_push(b_list, a_list);
			}
			else if ((*b_list)->next)
			{
				ft_printf("rb\n");
				ft_rotate(b_list);
			}
		i++;
		}
	}
}

void	ft_sortbig(t_list **a_list, t_list **b_list)
{
	long int	i;

	i = 0;
	while (ft_checksorted(*a_list, -1) == 0 || *b_list)
	{
		ft_radix(a_list, b_list, i);
		i++;
	}
	return ;
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
