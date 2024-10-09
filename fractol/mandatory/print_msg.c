/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hurabe <hurabe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 22:04:18 by hurabe            #+#    #+#             */
/*   Updated: 2024/10/09 16:35:12 by hurabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	msg_error(void)
{
	ft_putendl_fd("=================== How To Use ====================", 2);
	ft_putendl_fd("", 2);
	ft_putendl_fd("Usage example : ./fractol <type> <prm1*> <prm2*>", 2);
	ft_putendl_fd(" * : Julia needs two parameters", 2);
	ft_putendl_fd("", 2);
	ft_putendl_fd("[type]", 2);
	ft_putendl_fd("  Mandelbrot  /  M", 2);
	ft_putendl_fd("  Julia       /  J", 2);
	ft_putendl_fd("", 2);
	ft_putendl_fd("==================================================", 2);
	return (0);
}

int	msg_julia_prm(void)
{
	ft_putendl_fd("=================== How To Use ====================", 2);
	ft_putendl_fd("", 2);
	ft_putendl_fd("Usage example : ./fractol Julia <prm1> <prm2>", 2);
	ft_putendl_fd(" ! parameter must be between -2.0 and 2.0 !", 2);
	ft_putendl_fd("", 2);
	ft_putendl_fd("[recommended parameter]", 2);
	ft_putendl_fd("  -0.70176 -0.3842", 2);
	ft_putendl_fd("  -0.8 0.156", 2);
	ft_putendl_fd("  0.3 0.01", 2);
	ft_putendl_fd("  0.45 0.35", 2);
	ft_putendl_fd("", 2);
	ft_putendl_fd("==================================================", 2);
	return (0);
}

int	msg_operation(void)
{
	ft_putendl_fd("=================== How To Use ====================", 1);
	ft_putendl_fd("", 1);
	ft_putendl_fd("zoom : scroll mouse wheel  or  'z' / 'x'", 1);
	ft_putendl_fd("move : push arrow keys ", 1);
	ft_putendl_fd("", 1);
	ft_putendl_fd("==================================================", 1);
	return (0);
}
