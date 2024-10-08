# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hurabe <hurabe@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/08 22:02:32 by hurabe            #+#    #+#              #
#    Updated: 2024/10/08 22:03:07 by hurabe           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Project name
NAME		=	fractol

# Mandatory Source files
M_SRCS		=	mandatory/main.c mandatory/render.c \
				mandatory/key_event.c mandatory/mouse_event.c \
				mandatory/validate.c mandatory/init.c \
				mandatory/ft_atof.c mandatory/print_msg.c \

# Bonus Source files
B_SRCS		=	bonus/fractol_bonus.c bonus/render_bonus.c \
				bonus/key_event_bonus.c bonus/mouse_event_bonus.c \
				bonus/validate_bonus.c bonus/init_bonus.c \
				bonus/ft_atof_bonus.c bonus/print_msg_bonus.c \

# Object files
M_OBJS 		=	$(M_SRCS:.c=.o)
B_OBJS 		=	$(B_SRCS:.c=.o)

# Minilibx configuration
MLX_PATH	=	minilibx-linux/
MLX_NAME	=	libmlx.a
MLX			=	$(MLX_PATH)$(MLX_NAME)

# Libft configuration
LIBFT_PATH	=	libft/
LIBFT_NAME	=	libft.a
LIBFT		=	$(LIBFT_PATH)$(LIBFT_NAME)

# Compiler settings
CC			=	clang
CFLAGS		=	-Wall -Wextra -Werror
LIBX_FLAGS	=	-L$(MLX_PATH) -lmlx -L$(LIBFT_PATH) -lft -lXext -lX11 -lm -O3

# Build ruless
all:		$(LIBFT) $(MLX) $(NAME)

$(NAME):	$(M_OBJS)
			$(CC) $(CFLAGS) $(M_OBJS) $(LIBFT) $(LIBX_FLAGS) -o $(NAME)

bonus:		fclean $(LIBFT) $(MLX) $(B_OBJS)
			@if [ ! -e $(NAME) ]; then \
				$(CC) $(CFLAGS) $(B_OBJS) $(LIBFT) $(LIBX_FLAGS) -o $(NAME); \
			fi

# Build libft
$(LIBFT):
			make -C $(LIBFT_PATH)

# Build MiniLibX
$(MLX):
			make -C $(MLX_PATH)

# Clean rules
clean:
			$(RM) $(M_OBJS) $(B_OBJS)
			make -C $(LIBFT_PATH) clean
			make -C $(MLX_PATH) clean

fclean:		clean
			$(RM) $(NAME)
			make -C $(LIBFT_PATH) fclean

re:			fclean all

.PHONY:		all clean fclean re bonus
