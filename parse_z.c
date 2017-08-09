/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_z.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etregoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/23 10:27:23 by etregoni          #+#    #+#             */
/*   Updated: 2017/06/26 19:25:00 by etregoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		*split_atoi(char **s, int w)
{
	int *map;
	int i;

	i = 0;
	map = (int *)malloc(sizeof(int) * (w + 1));
	while (i < w)
	{
		map[i] = ft_atoi(&s[i][0]);
		i++;
	}
	return (map);
}

void	parse_z(t_map *m, int fd)
{
	int		x;
	int		i;
	char	**points;
	char	*line;

	x = 0;
	m->hmin = 0;
	m->hmax = 0;
	m->map_ptr = (int **)malloc(sizeof(int *) * (m->h + 1));
	while (get_next_line(fd, &line) > 0)
	{
		points = ft_strsplit(line, ' ');
		m->map_ptr[x] = split_atoi(points, m->w);
		i = 0;
		while (i < m->w)
		{
			m->hmax = m->map_ptr[x][i] > m->hmax ? m->map_ptr[x][i] : m->hmax;
			m->hmin = m->map_ptr[x][i] < m->hmin ? m->map_ptr[x][i] : m->hmin;
			i++;
		}
		x++;
	}
	free(points);
	free(line);
	close(fd);
}
