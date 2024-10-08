/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hurabe <hurabe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 21:35:47 by hurabe            #+#    #+#             */
/*   Updated: 2024/10/08 22:01:31 by hurabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char **argv)
{
	t_fractol	f;

	if (!validate(argc, argv, &f))
		return (-1);
	if (!init_data(&f))
		return (0);
	msg_operation();
	mlx_loop_hook(f.mlx, &render, &f);
	mlx_hook(f.win, 2, 1L << 0, &key_event, &f);
	mlx_hook(f.win, 4, 1L << 2, &mouse_zoom, &f);
	mlx_hook(f.win, 17, 0L, &close_win, &f);
	mlx_loop(f.mlx);
	return (0);
}
