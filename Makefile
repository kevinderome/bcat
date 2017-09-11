CXX = 		g++

CXXFLAGS =	-W -Wextra -Wall -I./include -g

LDXX_FLAGS =	-lbrlapi

RM = 		rm -f

SRC = 		src/BDevice.cpp \
		src/Bcat.cpp \
		src/main.cpp


NAME = 		bcat

OBJ = 		$(SRC:.cpp=.o)

$(NAME):	$(OBJ)
		$(CXX) -lbrlapi $(OBJ) -o $(NAME)

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
