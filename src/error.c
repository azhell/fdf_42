/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalytvyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 14:50:29 by yalytvyn          #+#    #+#             */
/*   Updated: 2018/11/27 14:50:31 by yalytvyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_error(int i)
{
	if (i == 0)
	{
		ft_putstr("usage: ./fdf \"map_name\"\n");
		exit(0);
	}
	else if (i == 1)
	{
		ft_putstr("Error file!\n");
		exit(1);
	}
	else if (i == 2)
	{
		ft_putstr("Error color!\n");
		exit(2);
	}
	else if (i == 3)
	{
		ft_putstr("Not valid map\n");
		exit(3);
	}
	else if (i == 4)
	{
		ft_putstr("Error memory!\n");
		exit(3);
	}
}
