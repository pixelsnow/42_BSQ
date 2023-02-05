# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akurusio <akurusio@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/11 11:45:40 by akurusio          #+#    #+#              #
#    Updated: 2022/07/20 17:51:48 by akurusio         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = bsq

SRC = $(wildcard ./srcs/*.c)

HEADER = ./includes

all: ${NAME}

${NAME}:
	gcc -Wall -Wextra -Werror -o ${NAME} ${SRC} -I ${HEADER}

clean:

fclean: clean
	rm -f ${NAME}

re: fclean all
