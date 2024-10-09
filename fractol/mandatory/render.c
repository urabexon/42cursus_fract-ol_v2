/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hurabe <hurabe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 22:04:15 by hurabe            #+#    #+#             */
/*   Updated: 2024/10/09 18:23:59 by hurabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	img_pix_put(t_img *img, int x, int y, int color)
{
	char	*pixel;

	pixel = img->addr + (y * img->line_size + x * (img->bpp / 8));
	*(int *)pixel = color;
}

static int	julia(double x, double y, t_fractol *f)
{
	double	zr;
	double	zi;
	double	tmp;
	int		iter;

	zr = x;
	zi = y;
	iter = 0;
	while (iter < f->max_iter)
	{
		tmp = 2 * zr * zi - f->arg_i;
		zr = zr * zr - zi * zi + f->arg_r;
		zi = tmp;
		if ((zr * zr + zi * zi) > 4)
			break ;
		iter++;
	}
	return (iter);
}

static int	mandelbrot(double x, double y, t_fractol *f)
{
	double	zr;
	double	zi;
	double	tmp;
	int		iter;

	zr = 0;
	zi = 0;
	iter = 0;
	while (iter < f->max_iter)
	{
		tmp = 2 * zr * zi + y;
		zr = zr * zr - zi * zi + x;
		zi = tmp;
		if ((zr * zr + zi * zi) > 4)
			break ;
		iter++;
	}
	return (iter);
}

static void	get_fractal_image(t_fractol *f)
{
	double	x;
	double	y;
	double	map_r;
	double	map_i;
	int		iter;

	x = -1;
	iter = 0;
	while (++x < WIDTH)
	{
		y = -1;
		while (++y < HEIGHT)
		{
			map_r = f->min_r + (x * (f->max_r - f->min_r)) / WIDTH;
			map_i = f->min_i + (y * (f->max_i - f->min_i)) / HEIGHT;
			if (f->kind == 1)
				iter = mandelbrot(map_r, map_i, f);
			else if (f->kind == 2)
				iter = julia(map_r, map_i, f);
			if (iter == f->max_iter)
				img_pix_put(&f->img, x, y, 0x000000);
			else
				img_pix_put(&f->img, x, y, f->color * iter * iter);
		}
	}
}

int	render(t_fractol *f)
{
	mlx_clear_window(f->mlx, f->win);
	get_fractal_image(f);
	mlx_put_image_to_window(f->mlx, f->win, f->img.img, 0, 0);
	return (1);
}
