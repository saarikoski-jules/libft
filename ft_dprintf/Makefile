# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: jsaariko <jsaariko@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/12/03 20:38:39 by jsaariko      #+#    #+#                  #
#    Updated: 2020/10/22 10:10:57 by jsaariko      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = dprintf
LIBFT_DIR = ../
C_FILES	=	ft_dprintf.c \
			gen_arg_str.c \
			store_conv.c \
			gen_arg_list.c \
			parse.c \
			transition_code.c \
			base_state.c \
			dash_state.c \
			zero_state.c \
			num_state.c \
			ast_state.c \
			precision_state.c \
			error_state.c \
			print_result.c \
			execute.c \
			convert_char.c \
			convert_int.c \
			convert_hex.c \
			convert_str.c \
			convert_ptr.c \
			convert_float.c \
			format_buffer.c \
			clear_list.c \

O_FILES_dprintf	=	$(C_FILES:%.c=%.o)
FLAGS	=	-Wall -Wextra -Werror

all: $(NAME)

%.o: %.c
	@gcc $(FLAGS) -I.. -c $< -o $@

$(NAME): $(O_FILES_dprintf)
	@echo "dprintf objects compiled"

clean:
	@rm -f $(O_FILES_dprintf)
	@echo "Cleared dprintf object files"

fclean: clean
	@rm -f $(NAME)
	@echo "dprintf all clean!"

re: fclean all
