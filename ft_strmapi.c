/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaratti <vcaratti@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 13:20:23 by vcaratti          #+#    #+#             */
/*   Updated: 2023/10/24 13:57:31 by vcaratti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		counter;
	char	*ret;

	counter = 0;
	while (s[counter])
		counter++;
	ret = (char *)malloc((counter + 1) * sizeof(char));
	if (ret == NULL)
		return (NULL);
	counter = 0;
	while (s[counter])
	{
		ret[counter] = f(counter, s[counter]);
		counter++;
	}
	ret[counter] = '\0';
	return (ret);
}
