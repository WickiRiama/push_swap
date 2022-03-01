/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriant <mriant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 10:59:33 by mriant            #+#    #+#             */
/*   Updated: 2022/03/01 11:33:55 by mriant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

int	ft_checkb(t_list *list, long int shift)
{
	int	n;

	while (list)
	{
		n = list->index >> shift & 1;
		if (n == 1)
			return (0);
		list = list->next;
	}
	return (1);
}

void	ft_radix_a(t_list **a_list, t_list **b_list, unsigned int shift)
{
	int	nb;
	int	len;

	len = ft_lstsize(*a_list);
	while (len > 0)
	{
		if (ft_checksorted(*a_list, -1) == 1)
			break ;
		nb = (*a_list)->index >> shift & 1;
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
		len--;
	}
}

void	ft_radix_b(t_list **a_list, t_list **b_list, unsigned int shift)
{
	int	nb;
	int	len;

	if (!(*b_list))
		return ;
	len = ft_lstsize(*b_list);
	if (ft_checkb(*b_list, shift) == 1 && shift < sizeof(int) * 8 - 1)
		return ;
	while (len > 0)
	{
		nb = (*b_list)->index >> shift & 1;
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
		len--;
	}
}

void	ft_radix(t_list **a_list, t_list **b_list)
{
	int	i;

	i = 0;
	while (ft_checksorted(*a_list, -1) == 0 || *b_list)
	{
		ft_radix_a(a_list, b_list, i);
		ft_radix_b(a_list, b_list, i + 1);
		i++;
	}
}
