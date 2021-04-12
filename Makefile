# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: lwiedijk <lwiedijk@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2021/02/14 15:20:32 by lwiedijk      #+#    #+#                  #
#    Updated: 2021/03/07 16:52:36 by lwiedijk      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
SRC_FILES = ft_printf.c
HEADER_FILES = ft_printf.h

PARSE_DIR = parser/
PARSE_SRC_FILES = parse.c \
parse_flag.c parse_width.c \
parse_length.c parse_precision.c \
parse_type.c

OUTPUT_DIR = type_output/
OUTPUT_SRC_FILES = print.c \
print_char.c print_hex.c \
print_hex_utils.c \
print_string.c print_percent.c \
print_address.c print_decimal.c \
print_decimal_unsigned.c \
print_decimal_utils.c \
type_output_utils.c \

LIBFT_DIR = libft/
LIBFT =	libft.a

CFLAGS = -g -Wall -Wextra -Werror

OBJ_FILES = $(SRC_FILES:.c=.o) \
$(addprefix $(PARSE_DIR), $(PARSE_SRC_FILES:.c=.o)) \
$(addprefix $(OUTPUT_DIR), $(OUTPUT_SRC_FILES:.c=.o)) \

all: $(NAME)

$(NAME): $(OBJ_FILES)
	make -C $(LIBFT_DIR)
	cp $(LIBFT_DIR)$(LIBFT) $(NAME)
	ar -rcs $@ $^

%.o: %.c $(HEADER_FILES)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ_FILES)
	make clean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(NAME) $(LIBFT_DIR)$(LIBFT)

re:
	$(MAKE) fclean
	$(MAKE) all

bonus: $(NAME)

.PHONY: all clean fclean re bonus
