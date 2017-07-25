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

int find_width(char **map_coord)
{
  int x;

  x = 0;
  while (map_coord[x])
    x++;
  return (x);
}

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

void  check_width(draw_line *arg, int fd)
{
  int width;

  if (get_next_line(fd, &(arg->line)))
  {
    check_line(arg->line);
    if (!(width = find_width(arg->points)))
      ft_error("Error: Invalid Width");
    free (arg->line);
	}
  else
    ft_error("Error: Empty map");
}

void  parse_map(char *av)
{
  draw_line arg;
  int       fd;

  if ((arg.str = ft_strstr(av, ".fdf")) == 0)
    ft_error("Error: Invalid filename.");
  if ((fd = open(av, O_RDONLY)) < 0)
    ft_error("Error: Opening file failed.");
  check_width(&arg, fd);

}
