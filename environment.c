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
	printf("gap = [%d]\n", (*fdf)->gap);
	printf("mid x = %d\nmid y = %d\n",(*fdf)->mid_x, (*fdf)->mid_y );
	while (i < m->h)
	{
		j = 0;
		cart[i] = (coord *)malloc(sizeof(coord) * (m->w + 1));
		while (j < m->w)
		{
			cart[i][j].x = ((j - (*fdf)->mid_x) * (*fdf)->gap) + (*fdf)->win_w / 2;
			cart[i][j].y = ((i - (*fdf)->mid_y) * (*fdf)->gap) + (*fdf)->win_h / 2;
			cart[i][j].z = m->map_ptr[i][j] * 5;
			cart[i][j].raw_z = m->map_ptr[i][j];
			printf("[%3f][%3f][%3f]\n", cart[i][j].y, cart[i][j].x, cart[i][j].z);
			j++;
		}
		printf("\n\n");
		i++;
	}
	printf("[%3f][%3f][%3f]\n", cart[5][9].y, cart[5][9].x, cart[5][9].z);
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
	fdf->gap = m->w >= m->h ? 700 / (m->w) : 700 / (m->h);
	fdf->big = m->w >= m->h ? m->w : m->h;
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
