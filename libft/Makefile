# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: lwiedijk <lwiedijk@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2021/02/17 15:37:10 by lwiedijk      #+#    #+#                  #
#    Updated: 2021/03/09 17:57:50 by lwiedijk      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRC_FILES = ft_isdigit.c ft_numlen_base.c \
ft_itoa_base.c ft_itoa_base_unsigned.c ft_strjoin.c \
ft_strjoin_free.c ft_power.c ft_isalpha.c \
ft_strlen.c ft_strcpy.c

HEADER_FILES = libft.h
CFLAGS = -g -Wall -Wextra -Werror
OBJ_FILES = $(SRC_FILES:.c=.o)

all: $(NAME)

$(NAME): $(OBJ_FILES)
	ar -rcs $@ $^

%.o: %.c $(HEADER_FILES)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ_FILES)

fclean: clean
	rm -f $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all

.PHONY: all clean fclean re
