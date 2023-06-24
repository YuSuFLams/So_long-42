NAME = so_long

C_BLUE    = \033[0;34m
C_CYAN  = \033[0;36m
C_RESET   = \033[0m

CC = cc

RM = rm -rf

CFLAGS	= -Wall -Wextra -Werror

HEADER = so_long.h 

SRCS = src/check_map_name.c src/check_map_variable.c src/check_number_char.c src/close_open_map.c \
	src/get_next_line_utils.c src/get_next_line.c src/key_movement.c src/libft_utils_1.c so_long.c \
	src/libft_utils_2.c src/move_player.c src/put_map.c src/read_map.c src/close_open_windows.c \
	src/ft_printf.c src/ft_printf_utils.c

OBJS = ${SRCS:.c=.o}

all: $(NAME)

$(NAME): $(OBJS) $(HEADER)
	@$(CC) $(CFLAGS)  $(OBJS) -o $(NAME) 
	@echo "$(C_BLUE)    - Compilation finished!....$(C_RESET)"

%.o: %.c $(HEADER)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJS)
	@echo "$(C_CYAN)    - Removed Object File finished!....$(C_RESET)"

fclean: clean
	@$(RM)  $(NAME)
	@echo "$(C_CYAN)    - Removed finished!....$(C_RESET)"

re: fclean all

.PHONY: all clean fclean re