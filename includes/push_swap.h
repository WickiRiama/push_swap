/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriant <mriant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 17:53:52 by mriant            #+#    #+#             */
/*   Updated: 2022/02/21 11:31:45 by mriant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

int 	ft_parse(int ac, char **av, t_list **pile);
void	ft_printpile(t_list *list, char *s);
void	ft_push(t_list **src, t_list **dest);
void	ft_rotate(t_list **lst);
void	ft_rrotate(t_list **lst);
void	ft_swap(t_list **lst);

#endif