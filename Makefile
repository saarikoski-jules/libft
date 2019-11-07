NAME = libft.a
SRCS = ft_putchar_fd ft_putstr_fd ft_putendl_fd ft_putnbr_fd ft_isalpha \
ft_isdigit ft_isalnum ft_isascii ft_isprint ft_toupper ft_tolower ft_strlen \
ft_memset ft_bzero ft_memcpy ft_memccpy ft_memmove ft_memchr ft_memcmp \
ft_strlcpy ft_strlcat ft_strchr ft_strrchr ft_strnstr ft_strncmp ft_atoi \
ft_calloc ft_substr ft_strjoin ft_strtrim ft_strmapi ft_itoa ft_split ft_strdup
BONUS_SRCS = ft_lstnew ft_lstsize ft_lstadd_front ft_lstlast ft_lstadd_back \
ft_lstdelone ft_lstclear ft_lstiter ft_lstmap
CFILES = $(SRCS:%=%.c)
OBJECTS = $(SRCS:%=%.o)
BONUS = $(BONUS_SRCS:%=%.c)
BONUS_OBJECTS = $(BONUS_SRCS:%=%.o)
FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJECTS)
	@ar -rc $(NAME) $(OBJECTS)
	@ranlib $(NAME)
	@echo "Library compiled"

bonus:
	@gcc $(FLAGS) -c $(CFILES) $(BONUS)
	@ar -rc $(NAME) $(OBJECTS) $(BONUS_OBJECTS)
	@ranlib $(NAME)
	@echo "Bonus compiled"

$(OBJECTS):
	@gcc $(FLAGS) -c $(CFILES)
	@echo "Objects compiled"

$(BONUS_OBJECTS):
	@gcc $(FLAGS) -c $(BONUS)
	@echo "Bonus objects compiled"

testmachine: bonus
	@gcc testmachine.c -L. -lft

test: bonus
	@gcc tests.c -L. -lft
	@rm $(OBJECTS) $(BONUS_OBJECTS)
	@echo "Tests compiled"

clean:
	@rm -f $(OBJECTS) $(BONUS_OBJECTS)
	@echo "Cleared object files"


fclean:
	@rm -f $(NAME)
	@rm -f a.out
	@Clean!

re: fclean all



# bonus: $(OBJECTS) $(BONUS_OFILES)
#     ar rc $(NAME) $(OBJECTS) $(BONUS_OFILES)