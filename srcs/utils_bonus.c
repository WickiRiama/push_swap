/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriant <mriant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 16:00:22 by mriant            #+#    #+#             */
/*   Updated: 2022/03/16 13:59:33 by mriant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap_bonus.h"

int	ft_tablen(char **tab)
{
	int	i;

	i = 0;
	while (tab && tab[i])
		i++;
	return (i);
}

void	ft_clean_ps(t_list **a_pile, char ***tab, t_list **ops)
{
	int	i;

	ft_lstclear(a_pile, free);
	ft_lstclear(ops, free);
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

	while (list && list->next)
	{
		if (shift != -1)
		{
			n1 = ((t_content *)list->content)->index >> shift & 1;
			n2 = ((t_content *)list->content)->index >> shift & 1;
		}
		else
		{
			n1 = ((t_content *)list->content)->index;
			n2 = ((t_content *)list->next->content)->index;
		}
		if (n1 > n2 && shift < (long int)(sizeof(int) * 8 - 1))
			return (0);
		else if (n1 < n2 && shift == (long int)(sizeof(int) * 8 - 1))
			return (0);
		list = list->next;
	}
	return (1);
}

void	ft_initindex(t_list *list)
{
	t_list	*temp;

	temp = list;
	while (temp)
	{
		((t_content *)temp->content)->index = -1;
		temp = temp->next;
	}
}
