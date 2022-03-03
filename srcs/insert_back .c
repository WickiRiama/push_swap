/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_back .c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriant <mriant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 11:59:46 by mriant            #+#    #+#             */
/*   Updated: 2022/03/03 12:00:26 by mriant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

t_moves	*ft_chosepush(t_list **a_list, t_list **b_list)
{
	t_moves	*moves;
	t_moves	*tp_mvs;
	t_list	*temp;
	int		i;

	(void)a_list;
	i = 0;
	temp = *b_list;
	moves = NULL;
	while (temp)
	{
		tp_mvs = ft_setmove(((t_content *)(*b_list)->content)->index,
				*b_list, i);
		if (!tp_mvs)
			return (NULL);
		if (moves->score > tp_mvs->score)
		{
			free(move);
			move = tp_mvs;
		}
		free(tp_mvs);
		i++;
		temp = temp->next;
	}
	return (move);
}
