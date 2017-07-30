/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etregoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/23 10:27:23 by etregoni          #+#    #+#             */
/*   Updated: 2017/06/26 19:25:00 by etregoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void  check_line(char *str)
{
  int i;

  i = 0;
  if (!*str)
    ft_error("Error: Line not read.");
  while (str[i] != '\0')
  {
    if (ft_isalpha(str[i]) == 1)
      ft_error("Error: Alphabetical characters found.");
    if ((str[i] == '-' && !(ft_isdigit(str[i + 1]))) || str[i] == '\t' )
      ft_error("Error: Forbidden characters found.");
    i++;
  }
}

int count_width(char **map_coord)
{
  int width;

  width = 0;
  while (map_coord[width])
    width++;
  return (width);
}

int  get_width(draw_line *arg, int fd, map *m, int y)
{
  int width;
  char **points;

  if (get_next_line(fd, &(arg->line)))
  {
    check_line(arg->line);
    if (!(width = count_width(arg->points)))
      ft_error("Error: Invalid Width");
    else
    {
      points = ft_strsplit(arg->line, ' ');
      m->w = width;
    }
	}
  else
    ft_error("Error: Empty map");
  return (y);
}

void get_height(draw_line *arg, int fd, map *m, int y)
{
  char **points;
  int width;

  while (get_next_line(fd, &(arg->line)))
  {
    check_line(arg->line);
    if (!(width = count_width(arg->points)))
      ft_error("Error: Invalid Width");
    else
      points = ft_strsplit(arg->line, ' ');
      y++;
  }
  m->h = y;
  free(arg->line);
  close(fd);
}

void  parse_xy(map *m, int fd, draw_line *arg)
{
  int y;

  y = 0;
  get_width(arg, fd, m, y);
  get_height(arg, fd, m, y);
}
