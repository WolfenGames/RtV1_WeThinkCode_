/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolf <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 15:11:54 by jwolf             #+#    #+#             */
/*   Updated: 2018/06/04 11:01:13 by jwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_lstiter(t_list *lst, void (*f)(t_list *elem))
{
	t_list	*n_lst;

	MALLCHECK(lst);
	MALLCHECK((n_lst = (t_list *)ft_memalloc(sizeof(n_lst))));
	n_lst = lst;
	while (n_lst)
	{
		(*f)(n_lst);
		n_lst = n_lst->next;
	}
}
