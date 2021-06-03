##
## EPITECH PROJECT, 2020
## PSU_zappy_2019
## File description:
## Makefile
##

NAME_SERVER	=	zappy_server

NAME_CLIENT =	zappy_ai

SRC_SERVER =	src/server/main.c	\
				src/server/client_handle.c 	\
				src/server/init_server.c\
				src/server/mapgen.c		\
				src/server/init.c	\
				src/server/look.c	\
				src/server/check_command.c		\
				src/server/check_command_next.c	\
				src/server/cmd/eject.c	\
				src/server/cmd/broadcast.c \
				src/server/cmd/connect_nbr.c \
				src/server/cmd/fork.c \
				src/server/cmd/forward.c \
				src/server/cmd/incantation_p1.c	\
				src/server/cmd/incantation_p2.c	\
				src/server/cmd/inventory.c \
				src/server/cmd/left.c \
				src/server/cmd/right.c \
				src/server/cmd/set.c \
				src/server/cmd/take.c \



SRC_CLIENT =	src/client/main.cpp	\
				src/client/fork.cpp	\
				src/client/survive.cpp	\
				src/client/ia.cpp	\
				src/client/init_objectif.cpp\
				src/client/init_objectif2.cpp\
				src/client/server_handle.cpp

INC_SERVER	= -I include/server/

GCC		=	gcc
GPP		=	g++

all:			$(NAME_SERVER) $(NAME_CLIENT)

$(NAME_SERVER):		$(SRC_SERVER:.c=.o)
			$(GCC) -g -o $@ $^

$(NAME_CLIENT):		$(SRC_CLIENT:.cpp=.o)
			$(GPP) -g -o $@ $^

clean:
			rm -f $(SRC_SERVER:.c=.o)
			rm -f $(SRC_CLIENT:.cpp=.o)

fclean:			clean
			rm -f $(NAME_SERVER)
			rm -f $(NAME_CLIENT)

re:			fclean all

.PHONY:		all clean fclean re