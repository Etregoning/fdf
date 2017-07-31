/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etregoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/23 10:27:23 by etregoni          #+#    #+#             */
/*   Updated: 2017/06/26 19:25:00 by etregoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

coord	**plot_cart(env **fdf, map *m)
{
	int   i;
	int   j;
	coord **cart;

	(*fdf)->mid_x = m->w / 2;
	(*fdf)->mid_y = m->h / 2;
	cart = (coord **)malloc(sizeof(coord *) * (m->h + 1));
	i = 0;
	while (i < m->h)
	{
		j = 0;
		cart[i] = (coord *)malloc(sizeof(coord) * (m->w + 1));
		while (j < m->w)
		{
			cart[i][j].x = (j - (*fdf)->mid_x) * (*fdf)->gap;
			cart[i][j].y = (i - (*fdf)->mid_y) * (*fdf)->gap;
			cart[i][j].z = m->map_ptr[i][j] * 5;
			cart[i][j].raw_z = m->map_ptr[i][j];
			j++;
		}
		i++;
	}
	cart[i] = NULL;
	return (cart);
}


env		*make_env(map *m)
{
	env *fdf;

	if(!(fdf = (env *)malloc(sizeof(env))))
		ft_error("Error: Failed to allocate memory.");
	fdf->x1 = 0;
	fdf->x2 = 0;
	fdf->y1 = 0;
	fdf->y2 = 0;
	fdf->gap = m->w > m->h ? m->win_x / (m->w) : m->win_y / (m->h);
	fdf->big = m->w > m->h ? m->w : m->h;
	fdf->rise = 0;
	fdf->run = 0;
	fdf->m = 0;
	fdf->win_w = 800 + (fdf->gap) * (fdf->big);
	fdf->win_h = (fdf->win_w) - 300;
	fdf->cart = plot_cart(&fdf, m);
	fdf->mlx = mlx_init();
	fdf->win = mlx_new_window(fdf->mlx, fdf->win_w, fdf->win_h, "FdF");
	return (fdf);
}
