/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaratti <vcaratti@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 14:22:21 by vcaratti          #+#    #+#             */
/*   Updated: 2023/10/30 11:36:28 by vcaratti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	one_more(t_list *current, t_list *current_n, void*(f)(void *))
{
	t_list	*temp;

	temp = (t_list *)malloc(sizeof(t_list));
	if (temp == NULL)
		return (0);
	temp->content = f(current->content);
	temp->next = NULL;
	current_n->next = temp;
	return(1);
}

static void	*clean_and_null(t_list **lst, void (*del)(void *))
{
	t_list	*current;
	t_list	*next;

	current = *lst;
	while (current->next != NULL)
	{
		next = current->next;
		del((void *)current->content);
		free(current);
		current = next;
	}
	del((void *)current->content);
	free(current);
	*lst = NULL;
	return (NULL);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*current;
	t_list	*current_n;
	t_list	*first_n;
	
	first_n = (t_list *)malloc(sizeof(t_list));
	if (first_n == NULL)
		return (NULL);
	current_n = first_n;
	current = lst;
	while (current->next != NULL)
	{
		current_n->content = f(current->content);
		current_n->next = (t_list *)malloc(sizeof(t_list));
		if (current_n->next == NULL)
			return (clean_and_null(&first_n, del));
		current_n = current_n->next;
	}
	if (!one_more(current, current_n, f))
		return (clean_and_null(&first_n, del));
	return (first_n);
}
