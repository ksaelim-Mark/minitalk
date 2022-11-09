# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ksaelim <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/16 13:38:42 by ksaelim           #+#    #+#              #
#    Updated: 2022/10/16 18:12:01 by ksaelim          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk
SERVER = server
CLIENT = client

SERV_SRCS = server.c
CLIT_SRCS = client.c
SRCS = ft_utils.c

FLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(SERVER) $(CLIENT)

server:
	gcc $(FLAGS) $(SERV_SRCS) $(SRCS) -o $(SERVER)

client:
	gcc $(FLAGS) $(CLIT_SRCS) $(SRCS) -o $(CLIENT)

$(OBJS): %.o: %.c
	gcc $(FLAGS) -c $< -o $@

clean :
	rm -rf $(SERVER)
	rm -rf $(CLIENT)

fclean : clean
	rm -f $(NAME)

re : fclean all
