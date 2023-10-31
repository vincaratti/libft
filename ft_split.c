/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaratti <vcaratti@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 11:55:03 by vcaratti          #+#    #+#             */
/*   Updated: 2023/10/27 11:08:07 by vcaratti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static char	*get_word(char *str, int start, int stop)
{
	char	*ret;
	int		i;

	i = 0;
	ret = (char *)malloc((stop - start + 1) * sizeof(char));
	if (ret == NULL)
		return (NULL);
	while (start < stop)
		ret[i++] = str[start++];
	ret[i] = '\0';
	return (ret);
}

static int	get_array_len(char *str, char c)
{
	int	i;
	int	w_counter;
	int	w_len;

	i = 0;
	w_counter = 0;
	w_len = 0;
	while (str[i])
	{
		if (str[i] == c && w_len)
		{
			w_counter++;
			w_len = 0;
		}
		if (str[i] != c)
			w_len++;
		i++;
	}
	if (w_len)
		w_counter++;
	return (w_counter);
}

static int	fill_array(char *str, char c, char **arr)
{
	int	i;
	int	w_counter;
	int	w_len;

	i = 0;
	w_counter = 0;
	w_len = 0;
	while (str[i])
	{
		if (str[i] == c && w_len)
		{
			arr[w_counter] = get_word(str, i - w_len, i);
			if (arr[w_counter++] == NULL)
				return (-1);
			w_len = 0;
		}
		if (str[i++] != c)
			w_len++;
	}
	if (w_len)
		arr[w_counter++] = get_word(str, i - w_len, i);
	if (arr[w_counter - 1] == NULL)
		return (-1);
	arr[w_counter] = 0;
	return (w_counter);
}

static int	check_array(char **arr, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if (arr[i] == NULL)
		{
			i = 0;
			while (i < len)
				free(arr[i++]);
			return (1);
		}
		i++;
	}
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char	**ret;

	if (s == NULL)
		return (NULL);
	ret = malloc((get_array_len((char *)s, c) + 1) * sizeof(char *));
	if (ret == NULL)
		return (NULL);
	if (fill_array((char *)s, c, ret) == -1)
	{
		check_array(ret, get_array_len((char *)s, c));
		return (NULL);
	}
	return (ret);
}
