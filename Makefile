# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: jsaariko <jsaariko@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/11/09 16:26:10 by jsaariko       #+#    #+#                 #
#    Updated: 2019/11/16 11:30:41 by jsaariko      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRCS = ft_putchar_fd ft_putstr_fd ft_putendl_fd ft_putnbr_fd ft_isalpha \
ft_isdigit ft_isalnum ft_isascii ft_isprint ft_toupper ft_tolower ft_strlen \
ft_memset ft_bzero ft_memcpy ft_memccpy ft_memmove ft_memchr ft_memcmp \
ft_strlcpy ft_strlcat ft_strchr ft_strrchr ft_strnstr ft_strncmp ft_atoi \
ft_calloc ft_substr ft_strjoin ft_strtrim ft_strmapi ft_itoa ft_split \
ft_strdup ft_numlen
BONUS_SRCS = ft_lstnew_bonus ft_lstsize_bonus ft_lstadd_front_bonus \
ft_lstlast_bonus ft_lstadd_back_bonus ft_lstdelone_bonus ft_lstclear_bonus \
ft_lstiter_bonus ft_lstmap_bonus
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

test: bonus
	@gcc tests.c -L. -lft
	@echo "Tests compiled"

clean:
	@rm -f $(OBJECTS) $(BONUS_OBJECTS)
	@echo "Cleared object files"

fclean: clean
	@rm -f $(NAME)
	@rm -f a.out
	@echo "Clean!"

re: fclean all
