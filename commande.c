/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commande.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mroturea <mroturea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/01 16:14:25 by mroturea          #+#    #+#             */
/*   Updated: 2016/06/02 19:20:14 by mroturea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	key_rgb(int key, t_struct *s)
{
	if (key == 89)
		s->red -= 1;
	if (key == 86)
		s->red += 1;
	if (key == 91)
		s->blue -= 1;
	if (key == 87)
		s->blue += 1;
	if (key == 92)
		s->green -= 1;
	if (key == 88)
		s->green += 1;
}

int		ft_key_print(int key, t_struct *s)
{
	key_rgb(key, s);
	if (key == 85)
	{
		init_color(s);
		s->color++;
		if (s->color == 6)
		s->color = 0;
	}
	if (key == 53)
	{
		exit(2);
		mlx_destroy_image(s->mlx, s->ptr_img);
		mlx_destroy_window(s->mlx, s->win);
	}
	if (key == 125)
		s->y1 *= 1.01;
	if (key == 126)
		s->y1 *= 0.99;
	if (key == 124)
		s->x1 -= 0.01;
	if (key == 123)
		s->x1 += 0.01;
	if (key == 69)
	{
		s->iter_max += 1;
		s->zoom *= 1.05;
	}
	if (key == 78)
	{
		s->iter_max -= 1;
		s->zoom *= 0.97;
	}
	if (key == 75)
		s->iter_max += 1;
	if (key == 67)
		s->iter_max -= 1;
	if (key == 83)
	{
		s->type++;
		s->bol = 0;
		if (s->type == 5)
			s->type = 1;
	}
	if (key == 84)
	{
		if (s->bw == 1)
		s->bw = 0;
		else
		s->bw = 1;
	}
	put_img(s);
	return (1);
}

int		key_mouse(int key, int x, int y, t_struct *s)
{
	double	xt;
	double	yt;

	if (y > 0)
	{
		xt = (x / s->zoom) + s->x1;
		yt = (y / s->zoom) + s->y1;
		if (key == 4)
		{
			s->zoom *= 1.1;
			s->iter_max += 1;
			s->x1 = xt - (x / s->zoom);
			s->y1 = yt - (y / s->zoom);
		}
		else if (key == 5)
		{
			s->iter_max -= 1;
			s->zoom *= 0.9;
			s->x1 = xt - (x / s->zoom);
			s->y1 = yt - (y / s->zoom);
		}
		choose_type(s);
	}
	return (0);
}
