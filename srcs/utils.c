/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriant <mriant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 16:00:22 by mriant            #+#    #+#             */
/*   Updated: 2022/02/23 16:52:02 by mriant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

int	ft_tablen(char **tab)
{
	int	i;

	i = 0;
	while (tab && tab[i])
		i++;
	return (i);
}

void	ft_clean(t_list **a_pile, t_list **b_pile, char ***tab)
{
	int	i;

	ft_lstclear(a_pile, free);
	ft_lstclear(b_pile, free);
	if (*tab)
	{
		i = 0;
		while (tab[0][i])
		{
			free(tab[0][i]);
			i++;
		}
	free(*tab);
	}
}

int	ft_checksorted(t_list *list, long int shift)
{
	int	n1;
	int	n2;

	while (list->next)
	{
		if (shift != -1)
		{
			n1 = *(int *)list->content >> shift & 1;
			n2 = *(int *)list->next->content >> shift & 1;
		}
		else
		{
			n1 = *(int *)list->content;
			n2 = *(int *)list->next->content;
		}
		if (n1 > n2 && shift < (long int)(sizeof(int) * 8 - 1))
			return (0);
		else if (n1 < n2 && shift == (long int)(sizeof(int) * 8 - 1))
			return (0);
		list = list->next;
	}
	return (1);
}

int	ft_checkb(t_list *list, long int shift)
{
	int	n;

	while (list)
	{
		n = *(int *)list->content >> shift & 1;
		if (n == 1)
			return (0);
		list = list->next;
	}
	return (1);
}
