/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etregoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/23 10:27:23 by etregoni          #+#    #+#             */
/*   Updated: 2017/08/13 17:30:37 by etregoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_coord	**plot_cart(t_env *fdf, t_map *m)
{
	int		i;
	int		j;
	t_coord	**cart;

	fdf->mid_x = m->w / 2;
	fdf->mid_y = m->h / 2;
	cart = (t_coord **)malloc(sizeof(t_coord *) * (m->h + 1));
	i = 0;
	while (i < m->h)
	{
		cart[i] = (t_coord *)malloc(sizeof(t_coord) * (m->w + 1));
		j = 0;
		while (j < m->w)
		{
			cart[i][j].x = ((j - fdf->mid_x) * fdf->gap);
			cart[i][j].y = ((i - fdf->mid_y) * fdf->gap);
			cart[i][j].z = m->map_ptr[i][j] * 5;
			cart[i][j].raw_z = m->map_ptr[i][j];
			j++;
		}
		i++;
	}
	return (cart);
}

void	translate(t_env *fdf)
{
	float	x;
	float	y;
	int		i;
	int		j;

	i = 0;
	while (i < fdf->h)
	{
		j = 0;
		while (j < fdf->w)
		{
			x = fdf->cart[i][j].x;
			y = fdf->cart[i][j].y;
			fdf->cart[i][j].x = x + (fdf->win_h / 2);
			fdf->cart[i][j].y = y + (fdf->win_w / 2);
			j++;
		}
		i++;
	}
}

void	populate_env(t_env **fdf, t_map *m)
{
	(*fdf)->x1 = 0;
	(*fdf)->x2 = 0;
	(*fdf)->y1 = 0;
	(*fdf)->y2 = 0;
	(*fdf)->hmin = 0;
	(*fdf)->gap = m->w >= m->h ? 700 / (m->w) : 700 / (m->h);
	(*fdf)->big = m->w >= m->h ? m->w : m->h;
	(*fdf)->w = m->w;
	(*fdf)->h = m->h;
	(*fdf)->rise = 0;
	(*fdf)->run = 0;
	(*fdf)->m = 0;
	(*fdf)->win_w = 350 + ((*fdf)->gap) * ((*fdf)->big);
	(*fdf)->win_h = ((*fdf)->win_w) - 100;
	(*fdf)->cart = plot_cart(*fdf, m);
	(*fdf)->mlx = mlx_init();
	(*fdf)->win =
	mlx_new_window((*fdf)->mlx, (*fdf)->win_w, (*fdf)->win_h, "FdF");
}

t_env	*make_env(t_map *m)
{
	t_env *fdf;

	if (!(fdf = (t_env *)malloc(sizeof(t_env))))
		ft_error("Error: Failed to allocate memory.");
	populate_env(&fdf, m);
	return (fdf);
}
