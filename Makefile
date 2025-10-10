# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: padan-pe <padan-pe@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/03 13:44:03 by padan-pe          #+#    #+#              #
#    Updated: 2025/10/02 15:25:34 by padan-pe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
CC = cc 
CFLAGS = -Wall -Wextra -Werror #-g3 -fsanitize=address
INCLUDE = -I. #directorio de cabeceras (dir actual)
SRC_FILES = main.c thread.c utils.c actions.c asign.c monitor.c parse.c 
OBJ_FILES = $(SRC_FILES:.c=.o)

# %.o: %.c #regla para compilar archivos .c en .o
# 	$(CC) $(C_FLAGS) $(INCLUDE) -c $< -o $@
	
all: $(NAME)


$(NAME): $(OBJ_FILES)
		$(CC) $(CFLAGS) $(OBJ_FILES) -o $(NAME)

clean: #regla para limpiar archivos .o
	rm -f $(OBJ_FILES)
fclean: #regla para limpiar todo incluyendo la lib
	rm -f $(NAME) $(OBJ_FILES)

re: fclean all #recompilar desde 0

.PHONY: all clean fclean re bonus