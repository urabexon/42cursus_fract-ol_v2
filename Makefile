# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hurabe <hurabe@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/08 22:02:32 by hurabe            #+#    #+#              #
#    Updated: 2024/10/09 20:04:00 by hurabe           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	fract-ol

M_SRCS		=	fractol/mandatory/main.c fractol/mandatory/render.c \
				fractol/mandatory/key_event.c fractol/mandatory/mouse_event.c \
				fractol/mandatory/validate.c fractol/mandatory/init.c \
				fractol/mandatory/print_msg.c \

M_OBJS 		=	$(M_SRCS:.c=.o)

# Minilibx
MLX_PATH	=	fractol/minilibx-linux/
MLX_NAME	=	libmlx.a
MLX			=	$(MLX_PATH)$(MLX_NAME)

# Libft
LIBFT_PATH	=	fractol/libft/
LIBFT_NAME	=	libft.a
LIBFT		=	$(LIBFT_PATH)$(LIBFT_NAME)

# Compiler settings
CC			=	clang
CFLAGS		=	-Wall -Wextra -Werror
LIBX_FLAGS	=	-L$(MLX_PATH) -lmlx -L$(LIBFT_PATH) -lft -lXext -lX11 -lm -O3

all:		$(LIBFT) $(MLX) $(NAME)

$(NAME):	$(M_OBJS)
			$(CC) $(CFLAGS) $(M_OBJS) $(LIBFT) $(LIBX_FLAGS) -o $(NAME)

# Build libft
$(LIBFT):
			make -C $(LIBFT_PATH)

# Build MiniLibX
$(MLX):
			make -C $(MLX_PATH)

clean:
			$(RM) $(M_OBJS)
			make -C $(LIBFT_PATH) clean
			make -C $(MLX_PATH) clean

fclean:		clean
			$(RM) $(NAME)
			make -C $(LIBFT_PATH) fclean

re:			fclean all

.PHONY:		all clean fclean re
