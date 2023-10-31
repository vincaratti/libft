/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaratti <vcaratti@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 10:53:11 by vcaratti          #+#    #+#             */
/*   Updated: 2023/10/24 14:09:53 by vcaratti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	int	i;
	int	j;
	int	dst_len;
	int	src_len;

	dst_len = ft_strlen((char *)dst);
	src_len = ft_strlen((char *)src);
	if (((unsigned long)dst_len >= dstsize) || dstsize == 0)
		return ((size_t)src_len + dstsize);
	i = 0;
	j = dst_len;
	while (src[i] != '\0' && (size_t)i < dstsize - dst_len - 1)
		dst[j++] = src[i++];
	dst[j] = '\0';
	return ((size_t)dst_len + (size_t)src_len);
}
