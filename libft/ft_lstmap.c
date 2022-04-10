/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalphit <mmalphit@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 15:12:39 by mmalphit          #+#    #+#             */
/*   Updated: 2022/04/10 15:12:40 by mmalphit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*result;
	void	*new_content;
	t_list	*new;

	result = NULL;
	while (lst)
	{
		new_content = (*f)(lst->content);
		if (new_content)
		{
			new = ft_lstnew(new_content);
			if (!new)
			{
				ft_lstclear(&result, del);
				return (NULL);
			}
			ft_lstadd_back(&result, new);
		}
		lst = lst->next;
	}
	return (result);
}
