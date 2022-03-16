/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_args_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriant <mriant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 11:39:54 by mriant            #+#    #+#             */
/*   Updated: 2022/03/16 14:00:27 by mriant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap_bonus.h"

int	ft_checkint(char *s)
{
	char	*max;

	max = "2147483647";
	if (!s)
		return (1);
	while (ft_isspace(*s))
		s++;
	if (*s == '+' && *(s + 1) != '\0')
		s++;
	else if (*s == '-' && *(s + 1) != '\0')
	{
		max = "2147483648";
		s++;
	}
	while (*s == '0')
		s ++;
	if (ft_strlen(s) > 10 || (ft_strlen(s) == 10 && ft_strncmp(s, max, 10) > 0))
		return (1);
	while (*s)
	{
		if (ft_isdigit(*s) == 0)
			return (1);
		s++;
	}
	return (0);
}

int	ft_checkdobble(int n, t_list **pile)
{
	t_list	*item;

	item = *pile;
	while (item)
	{
		if (n == ((t_content *)item->content)->value)
			return (1);
		item = item->next;
	}
	return (0);
}

int	ft_checkinput(int ac, char **av, t_list **pile)
{
	int			i;
	t_content	*content;
	t_list		*next;

	i = 0;
	while (i < ac)
	{
		if ((ac > 1 && av[i][0] == '\0') || ft_checkint(av[i]) == 1)
			return (1);
		content = malloc(sizeof(t_content));
		if (!content)
			return (1);
		content->value = ft_atoi(av[i]);
		if (ft_checkdobble(content->value, pile) == 1)
			return (1);
		next = ft_lstnew(content);
		if (!next)
			return (1);
		ft_lstadd_back(pile, next);
		i++;
	}
	return (0);
}

void	ft_setrank(t_list *pile)
{
	int		i;
	int		min;
	t_list	*temp;

	i = 0;
	ft_initindex(pile);
	while (i < ft_lstsize(pile))
	{
		temp = pile;
		min = 2147483647;
		while (temp)
		{
			if (((t_content *)temp->content)->index == -1
				&& ((t_content *)temp->content)->value < min)
				min = ((t_content *)temp->content)->value;
			temp = temp->next;
		}
		temp = pile;
		while (((t_content *)temp->content)->value != min)
			temp = temp->next;
		((t_content *)temp->content)->index = i;
		i++;
	}
}

int	ft_parse_args(int ac, char **av, char ***arg, t_list **pile)
{
	int		i;

	*pile = NULL;
	if (!av)
		return (-1);
	if (ac == 2)
		*arg = ft_split(av[1], ' ');
	else
	{
		*arg = malloc(sizeof(char *) * ac);
		i = 0;
		while (i < ac - 1)
		{
			arg[0][i] = ft_strdup(av[i + 1]);
			if (!arg[0][i])
				return (1);
			i ++;
		}
		arg[0][i] = NULL;
	}
	if (ft_checkinput(ft_tablen(*arg), *arg, pile) == 1)
		return (1);
	ft_setrank(*pile);
	return (0);
}
