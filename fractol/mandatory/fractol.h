/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hurabe <hurabe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 21:50:46 by hurabe            #+#    #+#             */
/*   Updated: 2024/10/08 22:27:17 by hurabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

// include
# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include <X11/keysym.h>

// define
# define WIDTH 1000.00
# define HEIGHT 1000.00

// struct
typedef struct s_img
{
	void	*img; // 画像のメモリアドレス
	void	*addr; // 画像の中身のメモリアドレス
	int		bpp;
	int		line_size;
	int		endian;
}			t_img;

typedef struct s_fractol
{
	void	*mlx; // minilibxとしての設定はここから始まる。メモリを確保
	void	*win; // minilibxの画面アドレス
	int		kind;
	double	arg_r; // ジュリア集合用のパラメーター、
	double	arg_i; // 
	double	max_r; // 画面幅
	double	max_i;
	double	min_r;
	double	min_i;
	double	max_iter;
	int		color;
	t_img	img;
}			t_fractol;

// mandatory
int			msg_error(void);
int			msg_julia_prm(void);
int			msg_operation(void);
int			init_data(t_fractol *f);
int			close_win(t_fractol *f);
int			key_event(int key, t_fractol *f);
int			mouse_zoom(int key, int x, int y, t_fractol *f);
int			render(t_fractol *f);
int			validate(int argc, char **argv, t_fractol *f);

#endif
