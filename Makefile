NAME = libft.a
SRCS = ft_putchar_fd ft_putstr_fd ft_putendl_fd ft_putnbr_fd ft_isalpha \
ft_isdigit ft_isalnum ft_isascii ft_isprint ft_toupper ft_tolower ft_strlen \
ft_memset ft_bzero ft_memcpy ft_memccpy ft_memmove ft_memchr ft_memcmp \
ft_strlcpy ft_strlcat ft_strchr ft_strrchr ft_strnstr ft_strncmp ft_atoi \
ft_calloc ft_substr ft_strjoin ft_strtrim ft_strmapi ft_itoa ft_split ft_strdup
CFILES = $(SRCS:%=%.c)
OBJECTS = $(SRCS:%=%.o)
FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJECTS)
	@ar -rc $(NAME) $(OBJECTS)
	@rm $(OBJECTS)
	@ranlib $(NAME)
	@echo "Library compiled"


$(OBJECTS):
	@gcc $(FLAGS) -c $(CFILES)
	@echo "Objects compiled"

test: $(NAME)
	@gcc tests.c -L. -lft
	@echo "Compiling tests"

clean:
	@rm $(OBJECTS)
	@echo "Cleared object files"


fclean: clean
	rm $(NAME)
	rm a.out

re: fclean all



# bonus: $(OBJECTS) $(BONUS_OFILES)
#     ar rc $(NAME) $(OBJECTS) $(BONUS_OFILES)