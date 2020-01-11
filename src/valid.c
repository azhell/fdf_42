/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalytvyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 16:47:52 by yalytvyn          #+#    #+#             */
/*   Updated: 2018/12/03 16:47:55 by yalytvyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_valit_content(t_line *list)
{
	int	i;
	int flag;

	i = 0;
	flag = 0;
	while (list->content[i] != '\0' && flag == 0)
	{
		if (ft_isdigit(list->content[i]))
			flag++;
		i++;
	}
	if (flag == 0)
		ft_error(3);
}

void		ft_valid_len(t_line *list, t_mat *mat, int count)
{
	t_line	*tmp;

	tmp = list;
	if (count <= 1)
		ft_error(3);
	ft_valit_content(list);
	while (tmp)
	{
		if (mat->len != (int)ft_wordcount(tmp->content, 32))
			ft_error(3);
		tmp = tmp->next;
	}
}

void		ft_valid_color(char *map)
{
	int i;
	int	count;

	i = 0;
	while (map[i] && map[i] != ',')
		i++;
	if (map[i] == '.')
		if (map[i + 1] != '0' || map[i + 2] != 'x')
			ft_error(2);
	if (map[i] == ',')
	{
		count = ft_strlen(map + i + 1);
		if (count <= 2 && count >= 8 && (count % 2 == 0))
			ft_error(2);
	}
}
