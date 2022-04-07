NAME = fdf
SRCS = src/main.c src/fdf.c src/read_map.c\
       src/memory_cleaning.c src/read_map_utils.c src/fill_matrix.c\
	   src/drawing_utils.c src/common_utils.c src/draw_line.c\
	   src/draw_map.c\
       get_next_line/get_next_line.c get_next_line/get_next_line_utils.c
OBJS = $(SRCS:%.c=%.o)
LIBFT = libft/libft.a
HEADERS = inc/fdf.h 
CC = gcc
CFLAGS = -Wall -Wextra -Werror


all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(LIBFT) -Lmlx -lmlx -framework OpenGL -framework AppKit $(OBJS) -o $(NAME)

$(LIBFT):
	make -s -C libft

%.o: %.c $(HEADERS) Makefile
	$(CC) $(CFLAGS) -c $< -Imlx -Ilibft -Iinc -o $@

clean:
	rm -f $(OBJS) && make -s -C libft clean

fclean: clean
	rm -f $(NAME) && make -s -C libft fclean

re: fclean all