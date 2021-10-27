# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/12 13:37:26 by ldermign          #+#    #+#              #
#    Updated: 2021/10/25 14:54:32 by ldermign         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_SER	=	server

NAME_CLI	=	client

SRCS_SER	=	./server.c ./utils.c ./utils_2.c

SRCS_CLI	=	./client.c ./utils.c

OBJS_SER	=	${SRCS_SER:.c=.o}

OBJS_CLI	=	${SRCS_CLI:.c=.o}

CC			=	clang

IDIR		=	./

CFLAGS  	=	-Wall -Wextra -Werror -I minitalk.h

RM			=	rm -rf

all:			${NAME_SER} ${NAME_CLI}

${NAME_SER}:	${OBJS_SER} minitalk.h
				@${CC} -o ${NAME_SER} ${OBJS_SER}

${NAME_CLI}:	${OBJS_CLI} minitalk.h
				@${CC} -o ${NAME_CLI} ${OBJS_CLI}

bonus:			all

.c.o:
				@${CC} ${CFLAGS} -c $< -o ${<:c=o}

clean:
				@${RM} ${OBJS_SER} ${OBJS_CLI}
				@echo "Rule clean for Minitalk done."

fclean:			clean
				@${RM} ${NAME_SER} ${NAME_CLI}
				@echo "No more Minitalk..."

re:				fclean all

.PHONY:			all clean fclean re