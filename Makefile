# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abenlahb <abenlahb@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/17 19:00:56 by abenlahb          #+#    #+#              #
#    Updated: 2023/07/15 23:48:45 by abenlahb         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRC = ft_printf/ft_printf.c ft_printf/ft_put_address.c ft_printf/ft_put_hex_maj_nbr.c \
ft_printf/ft_put_hex_min_nbr.c  ft_printf/ft_put_sign.c ft_printf/ft_put_uns_nbr.c  ft_printf/ft_putchar.c \
ft_printf/ft_putnbr.c ft_printf/ft_putstr.c

NAME = minitalk
CLIENT = $(SRC) client.c
SERVER =$(SRC) server.c

CLIENT_B = $(SRC) bonuss/client_bonus.c
SERVER_B = $(SRC) bonuss/server_bonus.c

OBJ_S = $(SERVER:.c=.o)
OBJ_C = $(CLIENT:.c=.o)

OBJ_SB = $(SERVER_B:.c=.o)
OBJ_CB = $(CLIENT_B:.c=.o)

CFLAGS = -Wall -Wextra -Werror
CC = cc
all:$(NAME)

$(NAME): client server

bonus: client_b server_b
client_b: $(OBJ_CB)
	$(CC) $(OBJ_CB) -o client
server_b: $(OBJ_SB)
	$(CC) $(OBJ_SB) -o server

client: $(OBJ_C)
	$(CC) $(OBJ_C) -o client
server: $(OBJ_S)
	$(CC) $(OBJ_S) -o server
	
%.o: %.c
	$(CC) -c $< -o $@
clean:
	rm -rf $(OBJ_C) $(OBJ_S) $(OBJ_SB) $(OBJ_CB)

fclean:clean
	rm -rf client server
re: fclean all