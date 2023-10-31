/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaratti <vcaratti@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 15:09:43 by vcaratti          #+#    #+#             */
/*   Updated: 2023/10/26 13:55:56 by vcaratti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int	i;
	int	j;

	if ((int)len == -1)
		len = (unsigned int)ft_strlen((char *)haystack);
	if (ft_strlen(needle) == 0)
		return ((char *)haystack);
	i = 0;
	while (i < (int)len && (haystack[i] != '\0'))
	{
		if (haystack[i] == needle[0])
		{
			j = 0;
			while (needle[j] == haystack[i + j] && needle[j] 
				&& (i + j) < (int)len)
				j++;
			if (needle[j] == 0 && j != 0)
				return ((char *)&haystack[i]);
		}
		i++;
	}
	return (0);
}
