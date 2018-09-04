CXX = 		g++

CXXFLAGS =	-std=c++14 -W -Wextra -Wall -I./include -g

LDXX_FLAGS =	-lbrlapi

RM = 		rm -f

SRC = 		src/BDevice.cpp \
		src/Bcat.cpp \
		src/main.cpp


NAME = 		bcat

OBJ = 		$(SRC:.cpp=.o)

$(NAME):	$(OBJ)
		$(CXX) $(LDXX_FLAGS)  $(OBJ) -o $(NAME)

all:		$(NAME)

clean:
		$(RM) $(OBJ)

fclean:		clean
		$(RM) $(NAME)

install:
	@echo "Installing..."
	@chmod 444 /etc/brlapi.key
	@cp $(NAME) /usr/bin
	@echo "Install success fully !"
uninstall:
	@echo "Uninstalling..."
	@$(RM) /usr/bin/$(NAME)
	@echo "Uninstall success fully !"
re:		clean fclean all
