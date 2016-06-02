/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mroturea <mroturea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/31 11:57:26 by mroturea          #+#    #+#             */
/*   Updated: 2016/06/02 18:10:44 by mroturea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		parse_name(char *av, t_struct *s)
{
	s->type = 0;
	if (ft_strcmp(av, "julia") == 0)
		s->type = 1;
	else if (ft_strcmp(av, "mandelbrot") == 0)
		s->type = 2;
	else if (ft_strcmp(av, "tricorn") == 0)
		s->type = 3;
	else if (ft_strcmp(av, "medusa") == 0)
		s->type = 4;
	if (s->type < 1)
		ERROR_NAME;
	return (1);
}

void	init_type(t_struct *s)
{
	if (s->type == 1)
		init_julia(s);
	if (s->type == 2)
		init_mandel(s);
	if (s->type == 3)
		init_tricorn(s);
	if (s->type == 4)
		init_medusa(s);
}

void	choose_type(t_struct *s)
{
	if (s->bol == 0)
	{
		init_type(s);
		s->bol = 1;
	}
	if (s->type == 1)
		julia(s);
	if (s->type == 2)
		mandelbrot(s);
	if (s->type == 3)
	tricorn(s);
	if (s->type == 4)
		medusa(s);

}

void	put_img(t_struct *s)
{
	s->mlx_img = mlx_new_image(s->mlx, HGT, WDT);
	s->ptr_img = mlx_get_data_addr(s->mlx_img, &(s->bit_pp),
		&(s->size_line), &(s->endian));
	choose_type(s);
	mlx_hook(s->win, 2, 3, ft_key_print, s);
	mlx_mouse_hook(s->win, key_mouse, s);
  mlx_put_image_to_window(s->mlx, s->win, s->mlx_img, 0, 0);
  mlx_loop(s->mlx);
}

void	mlx(t_struct *s)
{
	s->mlx = mlx_init();
	s->win = mlx_new_window(s->mlx, HGT, WDT, "fractol");
	s->bol = 0;
	init_color(s);
	s->color++;
	put_img(s);
}

int		main(int ac, char **av)
{
	t_struct *s;

	if (ac < 2)
		ERROR_NAME;
	s = (t_struct *)malloc(sizeof(t_struct));
	if(!parse_name(av[1], s))
		return (0);
	s->color = 0;
	mlx(s);
	return (0);
}
