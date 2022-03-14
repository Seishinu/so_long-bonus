NAME = so_long
NAME_BONUS = so_long_bonus

LIBFT = ./Libft/libft.a

GNL = get_next_line.c \
	  get_next_line_utils.c

MINILIB = ./minilibx/libmlx.a

SRCS = 	$(GNL) \
		so_long.c \
		read_map.c \
		checker.c \
		run_so_long.c \
		fill_map.c \
		fill_exit.c \
		move_player.c \
		check_win.c \
		switch_pics.c

SRCS_BONUS = $(GNL) \
		so_long_bonus.c \
		read_map.c \
		checker_bonus.c \
		run_so_long_bonus.c \
		fill_map_bonus.c \
		fill_exit.c \
		move_player_bonus.c \
		check_win.c \
		switch_pics_bonus.c \
		check_lose_bonus.c \
		move_enemy.c \
		switch_pics_enemy.c

LINKS = -L ./minilibx -I ./includes -lmlx -framework OpenGL -framework Appkit

OBJ = $(SRCS:%.c=bin/%.o)

OBJ_BONUS = $(SRCS_BONUS:%.c=bin/%.o)

all: $(NAME)

$(NAME): bin $(OBJ) $(LIBFT) $(MINILIB)
	$(CC) $(MINILIB) $(OBJ) -o $(NAME) $(LINKS) $(LIBFT)

$(LIBFT):
	make -C libft

bin/%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I ./includes

bin :
	@mkdir bin

bonus : $(NAME_BONUS)

$(NAME_BONUS): bin $(OBJ_BONUS) $(LIBFT) $(MINILIB)
	$(CC) $(MINILIB) $(OBJ_BONUS) -o $(NAME_BONUS) $(CFLAGS) $(LINKS) $(LIBFT)

clean:
	rm -rf bin
	make clean -C libft

fclean: clean
	rm -f $(NAME)
	rm -f $(NAME_BONUS)
	rm -f $(LIBFT)

re: fclean all