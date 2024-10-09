/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hurabe <hurabe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 21:35:53 by hurabe            #+#    #+#             */
/*   Updated: 2024/10/09 18:06:03 by hurabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	close_win(t_fractol *f)
{
	mlx_destroy_image(f->mlx, f->img.img);
	mlx_destroy_window(f->mlx, f->win);
	mlx_destroy_display(f->mlx);
	free(f->mlx);
	exit(0);
}

static void	key_zoom(int key, t_fractol *f)
{
	double	width;
	double	height;

	width = f->max_r - f->min_r;
	height = f->max_i - f->min_i;
	if (key == 'z')
	{
		f->max_r -= width / 10;
		f->min_r += width / 10;
		f->max_i -= height / 10;
		f->min_i += height / 10;
		f->max_iter += 2;
	}
	if (key == 'x')
	{
		f->max_r += width / 10;
		f->min_r -= width / 10;
		f->max_i += height / 10;
		f->min_i -= height / 10;
		if (f->max_iter > 30)
			f->max_iter -= 2;
	}
}

static void	key_move_width(int key, t_fractol *f)
{
	double	width;

	width = f->max_r - f->min_r;
	if (key == XK_Right)
	{
		f->max_r += width / 10;
		f->min_r += width / 10;
	}
	else if (key == XK_Left)
	{
		f->max_r -= width / 10;
		f->min_r -= width / 10;
	}
}

static void	key_move_height(int key, t_fractol *f)
{
	double	height;

	height = f->max_i - f->min_i;
	if (key == XK_Down)
	{
		f->max_i += height / 10;
		f->min_i += height / 10;
	}
	else if (key == XK_Up)
	{
		f->max_i -= height / 10;
		f->min_i -= height / 10;
	}
}

int	key_event(int key, t_fractol *f)
{
	if (key == XK_Escape)
		close_win(f);
	else if (key == XK_Left || key == XK_Right)
		key_move_width(key, f);
	else if (key == XK_Up || key == XK_Down)
		key_move_height(key, f);
	else if (key == 'z' || key == 'x')
		key_zoom(key, f);
	return (0);
}
