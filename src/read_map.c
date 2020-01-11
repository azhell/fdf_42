/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalytvyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 15:31:00 by yalytvyn          #+#    #+#             */
/*   Updated: 2018/11/27 15:31:03 by yalytvyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_set_color(t_rgb *rgb, char *s1, char *s2, char *s3)
{
	rgb->b = ft_atoi_hex(s3);
	rgb->g = ft_atoi_hex(s2);
	rgb->r = ft_atoi_hex(s1);
}

void		ft_get_color_def(t_rgb *rgb, t_cord **cord, int k, int l)
{
	if (cord[k][l].oz == 0)
		ft_set_color(rgb, "28", "fc", "59");
	else if (cord[k][l].oz < 0)
		ft_set_color(rgb, "ac", "22", "0c");
	else if (cord[k][l].oz > 10 && cord[k][l].oz <= 30)
		ft_set_color(rgb, "f7", "bb", "08");
	else if (cord[k][l].oz > 30)
		ft_set_color(rgb, "9e", "47", "00");
	else
		ft_set_color(rgb, "fd", "f2", "e7");
}

t_rgb		*ft_get_color(char *str, t_cord **cord, int k, int l)
{
	t_rgb	*rgb;
	int		i;
	char	*s;

	ft_valid_color(str);
	i = ft_strlen(str);
	rgb = (t_rgb*)malloc(sizeof(t_rgb));
	rgb->r = 0;
	rgb->g = 0;
	rgb->b = 0;
	if ((s = ft_strchr(str, ',')))
	{
		i = ft_strlen(s);
		if (i == 5 || i == 7 || i == 9)
			rgb->b = ft_atoi_hex(s + i - 2);
		if (i == 7 || i == 9)
			rgb->g = ft_atoi_hex(s + i - 4);
		if (i == 9)
			rgb->r = ft_atoi_hex(s + i - 6);
		return (rgb);
	}
	ft_get_color_def(rgb, cord, k, l);
	return (rgb);
}

t_cord		**ft_cr_cord(t_line *list, int count)
{
	t_cord	**cord;
	char	**map;
	int		j;
	int		i;

	i = 0;
	MALLCHECKF((cord = (t_cord**)malloc(sizeof(t_cord*) * count)));
	while (list)
	{
		MALLCHECKF((cord[i] = (t_cord*)malloc(sizeof(t_cord) *
		ft_wordcount(list->content, 32))));
		map = ft_strsplit(list->content, 32);
		j = -1;
		while (map[++j])
		{
			cord[i][j].ox = j;
			cord[i][j].oy = i;
			cord[i][j].oz = ft_atoi(map[j]);
			cord[i][j].rgb = ft_get_color(map[j], cord, i, j);
		}
		ft_freemap(map);
		i++;
		list = list->next;
	}
	return (cord);
}

t_cord		**ft_read_file(char *file, t_mat *mat)
{
	int		fd;
	t_cord	**cord;
	char	*line;
	int		count;
	t_line	*list;

	count = 0;
	FDERROR((fd = open(file, O_RDONLY)));
	while (get_next_line(fd, &line) > 0)
	{
		if (count == 0)
		{
			list = ft_lnewline(line);
			mat->len = ft_wordcount(line, 32);
		}
		else
			ft_lddline(&list, line);
		count++;
		free(line);
	}
	mat->wid = count;
	ft_valid_len(list, mat, count);
	cord = ft_cr_cord(list, count);
	ft_ldel(&list);
	return (cord);
}
