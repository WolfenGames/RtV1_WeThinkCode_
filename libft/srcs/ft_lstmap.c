/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolf <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 15:13:25 by jwolf             #+#    #+#             */
/*   Updated: 2018/06/04 11:02:20 by jwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*ret;
	t_list	*ret_new;
	t_list	*temp;
	t_list	*lst_new;

	if (!lst)
		return (NULL);
	lst_new = lst;
	temp = (*f)(lst_new);
	MALLCHECK_N((ret_new = ft_lstnew(temp->content, temp->content_size)));
	ret = ret_new;
	lst_new = lst_new->next;
	while (lst_new)
	{
		temp = (*f)(lst_new);
		ret_new->next = ft_lstnew(temp->content, temp->content_size);
		MALLCHECK_N((ret_new->next));
		ret_new = ret_new->next;
		lst_new = lst_new->next;
	}
	return (ret);
}
