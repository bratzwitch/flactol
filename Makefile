NAME = fractol

CFLAGS = -Wall -Wextra -Werror

LIBFT = ./lib_ft

MLX_PATH	= minilibx-linux/
MLX_NAME	= libmlx.a
MLX			= $(MLX_PATH)$(MLX_NAME)

SRC =	fractol.c numparseclean.c somehooks.c \
		fractals.c calculations.c pixelplayin.c \

OBJS = $(SRC:.c=.o)

RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
		@echo "Compiling this crap"
		@make -C $(LIBFT)  && make clean -C $(LIBFT)
		@make -sC $(MLX_PATH)
		@cc $(CFLAGS) $(OBJS) -o $(NAME) $(MLX) -lXext -lX11 -lm ./lib_ft/libft.a 
		@make clean
		@echo "All good you can rest(no)"
clean:
		@echo "Trashcan opened"
		@echo "Putting all your garbage but program"
		@make clean -C $(MLX_PATH)
		$(RM) $(OBJS)
		@echo "Trashcan closed"

fclean:	clean
		@echo "We decided that your program garbage too"
		@make fclean -C $(LIBFT)
		$(RM) $(NAME)
		@echo "Now trashcan really closed"

re: fclean all

.PHONY: all clean fclean re

.SILENT: