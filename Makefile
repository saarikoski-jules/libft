# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: jsaariko <jsaariko@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/11/09 16:26:10 by jsaariko      #+#    #+#                  #
#    Updated: 2020/11/13 11:08:37 by jsaariko      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
DPRINTF_DIR = ft_dprintf/
GNL_DIR = get_next_line/
LFT_SRCS =	ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_putbytes_fd.c \
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
		ft_strchrset.c \
		ft_strdupchr.c \
		ft_strjoinchar.c \
		ft_strsplice.c \
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
		vector_init.c \
		vector_search.c \
		vector_get.c \
		vector_resize.c \
		vector_print.c \

DPRINTD_SRCS =	$(DPRINTF_DIR)ft_dprintf.c \
				$(DPRINTF_DIR)gen_arg_str.c \
				$(DPRINTF_DIR)store_conv.c \
				$(DPRINTF_DIR)gen_arg_list.c \
				$(DPRINTF_DIR)parse.c \
				$(DPRINTF_DIR)transition_code.c \
				$(DPRINTF_DIR)base_state.c \
				$(DPRINTF_DIR)dash_state.c \
				$(DPRINTF_DIR)zero_state.c \
				$(DPRINTF_DIR)num_state.c \
				$(DPRINTF_DIR)ast_state.c \
				$(DPRINTF_DIR)precision_state.c \
				$(DPRINTF_DIR)error_state.c \
				$(DPRINTF_DIR)print_result.c \
				$(DPRINTF_DIR)execute.c \
				$(DPRINTF_DIR)convert_char.c \
				$(DPRINTF_DIR)convert_int.c \
				$(DPRINTF_DIR)convert_hex.c \
				$(DPRINTF_DIR)convert_str.c \
				$(DPRINTF_DIR)convert_ptr.c \
				$(DPRINTF_DIR)convert_float.c \
				$(DPRINTF_DIR)format_buffer.c \
				$(DPRINTF_DIR)clear_list.c \

LIBFT_OBJECTS = $(LFT_SRCS:%.c=%.o)
DPRINTF_OBJECTS = $(DPRINTD_SRCS:%.c=%.o)
FLAGS = -Wall -Wextra -Werror

all: $(NAME)

%.o: %.c
	@gcc $(FLAGS) -c $< -o $@

$(NAME): $(LIBFT_OBJECTS)
	@make -C $(DPRINTF_DIR) dprintf
	@ar -rc $(NAME) $(LIBFT_OBJECTS) $(DPRINTF_OBJECTS)
	@ranlib $(NAME)
	@echo "libft compiled"

clean:
	@rm -f $(LIBFT_OBJECTS)
	@make -C $(DPRINTF_DIR) clean
	@echo "Cleared libft object files"

fclean: clean
	@rm -f $(NAME)
	@make -C $(DPRINTF_DIR) fclean
	@echo "Libft clean!"

re: fclean all
