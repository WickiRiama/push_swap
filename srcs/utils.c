/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriant <mriant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 16:00:22 by mriant            #+#    #+#             */
/*   Updated: 2022/03/04 11:53:00 by mriant           ###   ########.fr       */
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

void	ft_clean_moves(t_moves **moves, int i)
{
	if (i == 1 || i == 3)
		(*moves)->rra = 0;
	if (i == 1 || i == 4)
		(*moves)->rrb = 0;
	if (i == 1)
		(*moves)->rrr = 0;
	if (i == 2 || i == 4)
		(*moves)->ra = 0;
	if (i == 2 || i == 3)
		(*moves)->rb = 0;
	if (i == 2)
		(*moves)->rr = 0;
}
