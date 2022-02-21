/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriant <mriant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 17:53:52 by mriant            #+#    #+#             */
/*   Updated: 2022/02/21 16:01:59 by mriant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

int		ft_parse(int ac, char **av, char ***arg, t_list **pile);
void	ft_push(t_list **src, t_list **dest);
void	ft_rotate(t_list **lst);
void	ft_rrotate(t_list **lst);
void	ft_sort3(t_list *list);
void	ft_swap(t_list **lst);
int		ft_tablen(char **tab);

#endif