/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalytvyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 13:05:25 by yalytvyn          #+#    #+#             */
/*   Updated: 2018/11/05 16:54:03 by yalytvyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		**ft_strsplit(char const *s, char c)
{
	size_t	count;
	char	**str;
	size_t	i;
	size_t	k;

	k = 0;
	count = ft_wordcount((char*)s, c);
	str = (char**)malloc(sizeof(char*) * count + 1);
	while (k < count)
	{
		i = 0;
		while (*s == c && *s)
			s++;
		while (s[i] != c && s[i])
			i++;
		str[k] = ft_strndup((char*)s, i);
		k++;
		while (*s != c && *s)
			s++;
	}
	str[k] = NULL;
	return (str);
}
