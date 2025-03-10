NAME := so_long

SRCS := game_logic/check_map_rectangular.c\
	game_logic/controls.c\
	game_logic/errors.c\
	game_logic/errors1.c\
	game_logic/ft_add_in_graphics.c\
	game_logic/ft_check_errors.c\
	game_logic/graphics.c\
	game_logic/initialiser.c\
	game_logic/map.c\
	game_logic/read_map.c\
	game_logic/so_long.c\
	get_next_line/get_next_line.c\
	get_next_line/get_next_line_utils.c\
	printf/ft_printf.c\
	printf/ft_putaddr.c\
	printf/ft_putchar.c\
	printf/ft_putnbr.c\
	printf/ft_putnbr_base.c\
	printf/ft_putnbr_u.c\
	printf/ft_putstr.c\
	libft/ft_strdup.c\
	libft/ft_strlen.c

OBJS := $(SRCS:.c=.o)

CC := cc
CFLAGS := -Wall -Wextra -Werror 

LIBRARY := -lmlx -lX11 -lXext
all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBRARY) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
.SECONDARY:$(OBJS)
