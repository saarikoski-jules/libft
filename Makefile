# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: jsaariko <jsaariko@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/11/09 16:26:10 by jsaariko       #+#    #+#                 #
#    Updated: 2020/03/14 12:26:25 by jsaariko      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRCS = ft_putchar_fd ft_putstr_fd ft_putendl_fd ft_putnbr_fd ft_isalpha \
ft_isdigit ft_isalnum ft_isascii ft_isprint ft_toupper ft_tolower ft_strlen \
ft_memset ft_bzero ft_memcpy ft_memccpy ft_memmove ft_memchr ft_memcmp \
ft_strlcpy ft_strlcat ft_strchr ft_strrchr ft_strnstr ft_strncmp ft_atoi \
ft_calloc ft_substr ft_strjoin ft_strtrim ft_strmapi ft_itoa ft_split \
ft_strdup ft_numlen ft_realloc ft_recalloc ft_strchrset ft_strdupchr \
ft_strjoinchar ft_numlen_base ft_numtochar_base ft_lltoa_base ft_ulltoa_base \
ft_toupperstr ft_tolowerstr ft_strjoinindex ft_strmatch ft_ftoa ft_ftoa_utils
CFILES = $(SRCS:%=%.c)
LIBFT_OBJECTS = $(SRCS:%=%.o)
FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(LIBFT_OBJECTS)
	@ar -rc $(NAME) $(LIBFT_OBJECTS)
	@ranlib $(NAME)
	@echo "Library compiled"

$(LIBFT_OBJECTS):
	@gcc $(FLAGS) -c $(CFILES)
	@echo "Libft objects compiled"

clean:
	@rm -f $(LIBFT_OBJECTS)
	@echo "Cleared libft object files"

fclean: clean
	@rm -f $(NAME)
	@rm -f a.out
	@echo "Libft clean!"

re: fclean all
