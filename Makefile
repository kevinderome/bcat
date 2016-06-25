##
## Makefile for  in /home/derome_k/rendu/my_42sh
## 
## Made by Kevin Derome
## Login   <derome_k@epitech.net>
## 
## Started on  Wed May 11 17:28:45 2016 Kevin Derome
## Last update Sat Jun 25 21:35:25 2016 Kevin Derome
##

CC = 		gcc

CFLAGS =	-W -Wextra -Wall -I./include -ansi -Werror -g

LD_FLAGS =	-lbrlapi

RM = 		rm -f

SRC = 		src/main.c \
		src/initialize.c \
		src/get_next_line.c \
		src/display.c \
		src/key_display_manager.c \
		src/free_bcat.c \
		src/string.c \
		src/special_key.c \
		src/parse_display.c


NAME = 		bcat

OBJ = 		$(SRC:.c=.o)

$(NAME):	$(OBJ)
		$(CC) -lbrlapi $(OBJ) -o $(NAME)

all:		$(NAME)

clean:
		$(RM) $(OBJ)

fclean:		clean
		$(RM) $(NAME)

install:
	@chmod 444 /etc/brlapi.key
	@cp $(NAME) /usr/bin
	@echo "success install"
uninstall:
	@$(RM) /usr/bin/$(NAME)
	@echo "success uninstall"
re:		clean fclean all
