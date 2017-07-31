/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etregoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/23 10:27:23 by etregoni          #+#    #+#             */
/*   Updated: 2017/06/26 19:25:00 by etregoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int ac, char **av)
{
	env			*fdf;
	map			*m;
	draw_line	arg;
	int			fd;

	if (ac != 2)
		ft_error("Error: Invalid argument(s).");
	if (!(m = (map *)ft_memalloc(sizeof(map))))
		ft_error("Error: Failed to allocate memory.");
	if ((arg.str = ft_strstr(av[1], ".fdf")) == 0)
		ft_error("Error: Invalid file extension.");
	if ((fd = open(av[1], O_RDONLY)) < 0)
		ft_error("Error: Opening file failed.");
	parse_xy(m, fd, &arg);
	if ((fd = open(av[1], O_RDONLY)) < 0)
		ft_error("Error: Opening file failed.");
	parse_z(m, fd);
	fdf = make_env(m);
	plot_lines(fdf, m);
	mlx_loop(fdf->mlx);
	return (0);
}
