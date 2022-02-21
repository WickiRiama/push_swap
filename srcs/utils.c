/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriant <mriant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 16:00:22 by mriant            #+#    #+#             */
/*   Updated: 2022/02/21 20:12:24 by mriant           ###   ########.fr       */
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

void	*ft_dec2bin(void	*n)
{
	char	*result;
	int		len;
	int		i;
	int		nb;

	len = 1;
	nb = *(int *)n;
	while (nb / 2 != 0)
	{
		len++;
		nb = nb / 2;
	}
	result = malloc(sizeof(char) * (len + 1));
	if (!result)
		return (NULL);
	i = len - 1;
	nb = *(int *)n;
	while (i >= 0)
	{
		result[i] = nb % 2 + '0';
		nb = nb / 2;
		i --;
	}
	result[len] = '\0';
	return ((void *)result);
}
