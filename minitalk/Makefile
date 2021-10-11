# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mchatzip <mchatzip@student.42wolfsburg.de> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/29 14:12:08 by mchatzip          #+#    #+#              #
#    Updated: 2021/07/29 15:15:28 by mchatzip         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME       = client

SNAME 	   = server

LIBFT_PATH = libft/

LIBFT_LIB  = libft.a

CLIENT_FILES = client.c

SERVER_FILES = server.c
			 
CLIENT_OBJS  = client.o

SERVER_OBJS = server.o

CC         = gcc

CFLAGS     = -Wall -Wextra -Werror

RM         = rm -f

AR         = ar crs

LIBFT_OBJS    = ${LIBFT_PATH}*.o

LIBFTMAKE    = $(MAKE) -C ${LIBFT_PATH}

all:			pmake ${NAME} ${SNAME}

${NAME}:    ${CLIENT_OBJS}
			${CC} ${CFLAGS} -o ${NAME} ${CLIENT_OBJS} -L libft/ -lft
			
${SNAME}:	${SERVER_OBJS}
			${CC} ${CFLAGS} -o ${SNAME} ${SERVER_OBJS} -L libft/ -lft
			

pmake:
			${LIBFTMAKE}

clean:
			make -C ${LIBFT_PATH} clean  
			${RM} ${CLIENT_OBJS} ${SERVER_OBJS}

fclean: 	clean
			${RM} ${NAME} ${SNAME}

re:         fclean all

.PHONY:     all clean fclean re