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
    ft_error("Error: Line not read.")
  while (str[i] != '\0')
  {
    if (ft_isalpha(str[i]) == 1)
      ft_error("Error: Alphabetical characters found.")
    if ((s[i] == '-' && !(ft_isdigit(s[i + 1]))) || s[i] == '\t' )
      ft_error("Error: Forbidden characters found.")
    i++;
  }
}

void  check_width(draw_line *arg, int width1, int width2, int fd)
{
  if (get_next_line(fd, &(arg->line)))
  {
    check_line(arg->line);
    if (!(width1 = find_width(arg->coord)))
      ft_error("Error: Invalid Width");
    free (arg->line);
    free (arg->coord);
	}
  else
    ft_error("Error: Empty map");
  while (get_next_line(fd, &(arg->line)))
  {

  }
}

void  parse_map(char *av)
{
  draw_line *arg;
  int       width1;
  int       width2;
  int       fd

  if ((arg.str = ft_strstr(av, ".fdf")) == 0)
    ft_error("Error: Invalid filename.");
  if ((fd = open(av, O_RDONLY)) < 0)
    ft_error("Error: Opening file failed.")
  check_width(&arg, width1, width2, fd);

}
