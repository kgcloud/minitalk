# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: canjugun <canjugun@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/09 15:47:44 by canjugun          #+#    #+#              #
#    Updated: 2021/09/09 15:59:11 by canjugun         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CLIENT		= client
SERVER		= server
NAME		= $(CLIENT) $(SERVER)

CC			= gcc
INCLUDE		= includes
CFLAGS		= -Wall -Wextra -Werror -I$(INCLUDE)
RM			= rm -rf

CLIENT_S 	= client.c
SERVER_S 	= server.c
UTILS_S		= utils.c

CLIENT_O 	= $(CLIENT_S:%.c=%.o)
SERVER_O 	= $(SERVER_S:%.c=%.o)
UTILS_O 	= $(UTILS_S:%.c=%.o)

all:		$(NAME)

bonus: 		all

$(CLIENT):	$(CLIENT_O) $(UTILS_O)
			@$(CC) $(CFLAGS) $(CLIENT_O) $(UTILS_O) -o client
			@echo "Linked into executable \033[0;32mclient\033[0m."

$(SERVER):	$(SERVER_O) $(UTILS_O)
			@$(CC) $(CFLAGS) $(SERVER_O) $(UTILS_O) -o server
			@echo "Linked into executable \033[0;32mserver\033[0m."

.c.o:
			@$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)
			@echo "Compiling $<."

clean:
			@$(RM) $(CLIENT_O) $(SERVER_O) $(UTILS_O)
			@echo "Removed object files."

fclean: 	clean
			@$(RM) $(NAME)
			@echo "Removed executables."

re:			fclean all

c:			all clean

.PHONY:		all clean fclean re
