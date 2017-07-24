/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etregoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/23 10:27:23 by etregoni          #+#    #+#             */
/*   Updated: 2017/06/26 19:25:00 by etregoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int *split_atoi(char **s, int w)
{
  int *map;
  int i;

  i = 0;
  map = (int *)malloc(sizeof(int) * (w + 1));
  while (j < w)
  {
    map[j] = ft_atoi(&s[j][0]);
    j++;
  }
  return (map);
}

int   z_value(int fd, map *m)
{
  int   x;
  int   i;
  char  *points;
  char  **line;

  x = 0;
  m->hmin = 0;
  m->hmax = 0;
  m->map_ptr = (int **)malloc(sizeof(int *) * (m->h + 1));
  while (get_next_line(fd, &line))
  {
    points = ft_strsplit(line, ' ');
    m->map[x] = split_atoi(points, m->w);
    free(points);
    free(line);
    i = 0;
    while (i < m->w)
    {
      m->hmax = m->map[x][i] > m->hmax ? m->map[x][i] : m->hmax;
      m->hmin = m->map[x][i] < m->hmin ? m->map[x][i] : m->hmin;
      i++;
    }
    x++;
  }
  close(fd);
}

void  get_dimensions(int fd, map *list)
{
  char *line;
  char **points;
  int y;

  y = 0;
  if (get_next_line(fd, &line))
  {
    y++;
    points = ft_strsplit(line, ' ');
    list->w = find_width(points);
  }
  while (get_next_line(fd, &line))
    y++;
  list->h = y;
  close(fd);
}

void  store_map(char *av, map *list)
{
  int fd;

  fd = open(av, O_RDONLY);
  get_dimensions(fd, list);
  fd == open(av, O_RDONLY);
  z_value(fd, &list);
}
