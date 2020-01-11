/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wordcount.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalytvyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/04 13:01:37 by yalytvyn          #+#    #+#             */
/*   Updated: 2018/11/04 13:26:04 by yalytvyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_wordcount(char *str, char c)
{
	int		num;

	num = 0;
	while (*str)
	{
		while (*str == c && *str)
			str++;
		if (*str != c && *str)
			num++;
		while (*str != c && *str)
			str++;
	}
	return (num);
}
