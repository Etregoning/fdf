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
	parse_map(av[1]);
	if (!(m = (map *)ft_memalloc(sizeof(map))))
		ft_error("Error: Failed to allocate memory.")
	store_map(av[1], m);
	fdf->mlx = mlx_init();
	fdf->win = mlx_new_window(fdf->mlx, 1400, 1000, "Elliot's Window");
	fdf->img = mlx_new_image(fdf->mlx, 1000, 600);
	x_axis(&fdf, x1, x2, y1, y2);
	//y_axis(&fdf);
	mlx_loop(fdf->mlx);
	return (0);
}
