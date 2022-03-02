/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_back.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriant <mriant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 13:23:15 by mriant            #+#    #+#             */
/*   Updated: 2022/03/02 17:58:25 by mriant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	ft_minmax(int *min, int *max, t_list *list)
{
	while (list)
	{
		if (*max < ((t_content *)list->content)->index)
			*max = ((t_content *)list->content)->index;
		if (*min > ((t_content *)list->content)->index)
			*min = ((t_content *)list->content)->index;
		list = list->next;
	}
}

int	ft_ispushable(int n, )
{

	if (n > last && n < first)
		return (1);
	return (0);
}

void	ft_setmove(t_moves **moves, int index, t_list *list)
{
	int	max;
	int	min;
	int	len;

	max = 0;
	min = 2147483647;

	ft_minmax(&min, &max, list);
	len = ft_lstsize(list);
	(*moves)->rb = 0;
	if (index < min || index > max)
	{
		while (((t_content *)list->content)->index != min)
		{
			(*moves)->rb ++;
			list = list->next;
		}
	}
	else
	{
		last = ((t_content *)ft_lstlast(list)->content)->index;
		first = ((t_content *)list->content)->index;
		while (index < last || index > first)
		{
			(*moves)->rb ++;
			last = (t_content *)list->content)->index;
			list = list->next;
			first = (t_content *)list->content)->index;
		}
	}
	(*moves)->rrb = len - (*moves)->rb;
}

int	ft_insert_b(t_list **a_list, t_list **b_list)
{
	t_moves	*moves;
	t_moves	*tp_mvs;
	t_list	*temp;
	int		i;

	i = 0;
	temp = *b_list;
	moves = NULL;
	while (temp)
	{
		tp_mvs = malloc(sizeof(t_moves));
		if (!tp_mvs)
			return (NULL);
		tp_mvs->ra = i;
		tp_mvs->rra = ft_lstsize(*b_list) - i;
		ft_setmove(&tp_mvs, ((t_content *)(*b_list)->content)->index), *b_list);
		i++;
	}
}
