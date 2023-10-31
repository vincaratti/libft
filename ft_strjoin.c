/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaratti <vcaratti@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 15:03:51 by vcaratti          #+#    #+#             */
/*   Updated: 2023/10/24 14:09:20 by vcaratti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		counter;
	int		len;
	char	*ret;

	counter = 0;
	len = 0;
	while (s1[counter++])
		len++;
	counter = 0;
	while (s2[counter++])
		len++;
	ret = (char *)malloc((len + 1) * sizeof(char));
	if (ret == NULL)
		return (NULL);
	counter = 0;
	len = 0;
	while (s1[counter])
		ret[len++] = s1[counter++];
	counter = 0;
	while (s2[counter])
		ret[len++] = s2[counter++];
	ret[len] = '\0';
	return (ret);
}
