/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriant <mriant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 16:00:22 by mriant            #+#    #+#             */
/*   Updated: 2022/02/21 17:30:38 by mriant           ###   ########.fr       */
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

char*	ft_dec2bin(int	*n)
{
	if (n / 2 != 0)
		ft_dec2bin(n / 2, result, base, fd);
	c = base[(n % len)];
	*result += ft_putchar_int(c, fd);
}
