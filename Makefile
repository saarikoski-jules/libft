# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: jsaariko <jsaariko@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/11/09 16:26:10 by jsaariko       #+#    #+#                 #
#    Updated: 2020/03/15 16:21:58 by jsaariko      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
PRINTF_DIR = ft_printf/
GNL_DIR = get_next_line/
LFT_SRCS =	ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_isalpha.c \
		ft_isdigit.c \
		ft_isalnum.c \
		ft_isascii.c \
		ft_isprint.c \
		ft_toupper.c \
		ft_tolower.c \
		ft_strlen.c \
		ft_memset.c \
		ft_bzero.c \
		ft_memcpy.c \
		ft_memccpy.c \
		ft_memmove.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_strlcpy.c \
		ft_strlcat.c \
		ft_strchr.c \
		ft_strrchr.c \
		ft_strnstr.c \
		ft_strncmp.c \
		ft_atoi.c \
		ft_atoll.c \
		ft_calloc.c \
		ft_substr.c \
		ft_strjoin.c \
		ft_strtrim.c \
		ft_strmapi.c \
		ft_itoa.c \
		ft_split.c \
		ft_strdup.c \
		ft_numlen.c \
		ft_realloc.c \
		ft_recalloc.c \
		ft_strchrset.c \
		ft_strdupchr.c \
		ft_strjoinchar.c \
		ft_numlen_base.c \
		ft_numtochar_base.c \
		ft_lltoa_base.c \
		ft_ulltoa_base.c \
		ft_toupperstr.c \
		ft_tolowerstr.c \
		ft_strjoinindex.c \
		ft_strmatch.c \
		ft_ftoa.c \
		ft_ftoa_utils.c \
		get_next_line.c \
		get_next_line_utils.c \
		ft_pow.c \
		ft_atof.c \

PRINTF_SRCS =	$(PRINTF_DIR)ft_printf.c \
				$(PRINTF_DIR)gen_arg_str.c \
				$(PRINTF_DIR)store_conv.c \
				$(PRINTF_DIR)gen_arg_list.c \
				$(PRINTF_DIR)parse.c \
				$(PRINTF_DIR)transition_code.c \
				$(PRINTF_DIR)base_state.c \
				$(PRINTF_DIR)dash_state.c \
				$(PRINTF_DIR)zero_state.c \
				$(PRINTF_DIR)num_state.c \
				$(PRINTF_DIR)ast_state.c \
				$(PRINTF_DIR)precision_state.c \
				$(PRINTF_DIR)error_state.c \
				$(PRINTF_DIR)print_result.c \
				$(PRINTF_DIR)execute.c \
				$(PRINTF_DIR)convert_char.c \
				$(PRINTF_DIR)convert_int.c \
				$(PRINTF_DIR)convert_hex.c \
				$(PRINTF_DIR)convert_str.c \
				$(PRINTF_DIR)convert_ptr.c \
				$(PRINTF_DIR)convert_float.c \
				$(PRINTF_DIR)format_buffer.c \
				$(PRINTF_DIR)clear_list.c \

LIBFT_OBJECTS = $(LFT_SRCS:%.c=%.o)
PRINTF_OBJECTS = $(PRINTF_SRCS:%.c=%.o)
FLAGS = -Wall -Wextra -Werror

all: $(NAME)

%.o: %.c
	@echo "Compiling $@"
	@gcc $(FLAGS) -c $< -o $@

$(NAME): $(LIBFT_OBJECTS)
	@make -C $(PRINTF_DIR) printf
	@ar -rc $(NAME) $(LIBFT_OBJECTS) $(PRINTF_OBJECTS)
	@ranlib $(NAME)
	@echo "Library compiled"

clean:
	@rm -f $(LIBFT_OBJECTS)
	@make -C $(PRINTF_DIR) clean
	@echo "Cleared libft object files"

fclean: clean
	@rm -f $(NAME)
	@make -C $(PRINTF_DIR) fclean
	@echo "Libft clean!"

re: fclean all
