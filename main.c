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

void	x_axis(env **fdf, int x1, int x2, int y1, int y2)
{
	int dx;
	int dy;
	int p;

	dx = x2 - x1;
	dy = y2 - y1;
	p = 2 * (dy - dx);
	while (x1 < x2)
	{
		if (p >= 0)
		{
			mlx_pixel_put((*fdf)->mlx, (*fdf)->win, x1, y1, 0x00FF0000);
			y1--;
			p = p + 2 * dy - 2 * dx;
		}
		else
		{
			mlx_pixel_put((*fdf)->mlx, (*fdf)->win, x1, y1, 0x00FF0000);
			p = p + 2 * dy;
		}
		x1++;
	}
}


int	main(void)
{
	env *fdf;
	map *m;

	if (ac != 2)
		ft_error("Error: Invalid argument(s).")
	if (!(m = (map *)ft_memalloc(sizeof(map))))
		ft_error("Error: Failed to allocate memory.")
	parse_map(av[1]);
	store_map(av[1], m);
	fdf = make_env(m);
	mlx_loop(fdf->mlx);
	return (0);
}
