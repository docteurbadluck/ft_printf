CC = cc 
CFLAGS = -Wall -Wextra -Werror
SRC = ft_printf.c ft_printf_utils.c ft_printf_utils_2.c
HEADER = ft_printf.h 

OBJ_FILES = $(SRC:.c=.o)

NAME = ft_printf.a

all: $(NAME)

$(NAME): $(OBJ_FILES)
	ar rcs $@ $^

%.o: %.c$
	$(CC) $(CFLAGS) -I . -c $< -o $@

clean: 
	rm -f $(OBJ_FILES)

fclean:clean
	rm -f $(NAME)

re: fclean all

.PHONY :all clean fclean re 
