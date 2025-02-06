CC = cc 
CFLAGS = -Wall -Wextra -Werror
SRC = ft_printf.c ft_printf_utils.c ft_printf_utils_2.c ft_printf_utils_3.c
HEADER = ft_printf.h 

OBJ_FILES = $(SRC:.c=.o)

NAME = printf.out

all: $(NAME)

$(NAME): $(OBJ_FILES)
	$(CC) $(OBJ_FILES) $(CFLAGS) -I . -o $@

%.o: %.c$
	$(CC) $(CFLAGS) -I . -c $< -o $@

clean: 
	rm -f $(OBJ_FILES)

fclean:clean
	rm -f $(NAME)

re: fclean all

.PHONY :all clean fclean re 
