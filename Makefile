##
## EPITECH PROJECT, 2018
## 
## File description:
## 
##

NAME	= plazza

CC	= g++

RM	= rm -f

DIR	=	src/

DIRCLA	=	class/

SRCS	= 	$(DIR)main.cpp	\
		$(DIRCLA)Mutex.cpp	\
		$(DIRCLA)SafeQueue.cpp	\
		$(DIRCLA)Thread.cpp	\
		$(DIRCLA)Error.cpp	\
		$(DIRCLA)Parser.cpp	\
		$(DIRCLA)Child.cpp	\
		$(DIRCLA)Socket.cpp	\
		$(DIRCLA)ParserFile.cpp	\
		$(DIR)getline.cpp	\
		$(DIR)father.cpp

OBJS	= $(SRCS:.cpp=.o)

CXXFLAGS = -I./include
CXXFLAGS += -W -Wall -Wextra -std=c++14

LDLIB	= -lpthread

CREATE_GUI = create_gui_files

DELETE_GUI = delete_gui_files

all: $(NAME)

gui: $(CREATE_GUI)

$(CREATE_GUI): 	
			cd gui;		\
			qmake plazza.pro; 	\
			make;				\
			mv plazza ..; 

$(DELETE_GUI):
			cd gui;		\
			make clean;			\
			$(RM)  Makefile

$(NAME): $(OBJS)
	 $(CC) $(OBJS) -o $(NAME) $(LDLIB)

clean:
	$(RM) $(OBJS)

fclean: clean $(DELETE_GUI)
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re