/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mroturea <mroturea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/31 11:54:04 by mroturea          #+#    #+#             */
/*   Updated: 2016/06/01 18:53:30 by mroturea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft/libft.h"
# include "color.h"
# include <mlx.h>
# include <math.h>
# include <stdio.h>
#include <stdlib.h>
# define HGT 1280
# define WDT 1080

# define ERROR_NAME {ft_putstr("Wrong name: Write :\n->mandelbrot\n->julia\n->tricorn\n->medusa"); exit(0);}

typedef struct s_struct
{
  void    *mlx;
  void    *win;
  void    *mlx_img;
  char    *ptr_img;
  int     bit_pp;
  int     size_line;
  int     endian;
  float   x1;
  float   x2;
  float   y1;
  float   y2;
  float   image_x;
  float   image_y;
  int     iter_max;
  int     blue;
  int     red;
  int     green;
  int     x;
  int     y;
  double  zoom_x;
  double  zoom_y;
  double  zoom;
  double  c_r;
  double  c_i;
  double  z_r;
  double  z_i;
  float   i;
  double  tmp;
  char    *av;
  int     type;
  int bol;

}               t_struct;

int		ft_key_print(int key, t_struct *s);
void    put_img(t_struct *s);
void    tricorn(t_struct *s);
void    init_tricorn(t_struct *s);
void    init_julia(t_struct *s);
void    init_mandel(t_struct *s);
void    julia(t_struct *s);
void    init_medusa(t_struct *s);
void    medusa(t_struct *s);
void    put_pixel_to_image(t_struct *s);
void    mandelbrot(t_struct *s);
void init_type(t_struct *s);
#endif
