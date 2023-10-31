/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaratti <vcaratti@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 15:48:05 by vcaratti          #+#    #+#             */
/*   Updated: 2023/10/26 12:02:44 by vcaratti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
/*
static int	check_max_size(unsigned	long count, unsigned long size)
{
	unsigned long	ft_maxint = 2147483647;

	if (count > ft_maxint || size > ft_maxint || (count * size) > ft_maxint)
		return (1);
	return (0);
}
*/
void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*ret;
	unsigned long	i;

	ret = malloc(size * count);
	if (ret == NULL)
		return (NULL);
	i = 0;
	while (i < count * size)
		ret[i++] = 0;
	return ((void *)ret);
}
