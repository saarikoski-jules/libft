NAME = libft
SRCS = tests.c ft_putchar.c ft_putstr.c ft_putendl.c ft_putnbr.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c ft_memchr.c ft_memcmp.c ft_strcpy.c ft_strdup.c ft_strncpy.c
FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	gcc $(FLAGS) $(SRCS) -o $(NAME)

fclean:
	rm libft

re: fclean all