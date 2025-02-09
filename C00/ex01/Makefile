NAME	= catalog
CC		= c++
CFLAGS	= -Wall -Werror -Wextra -std=c++98 -g3
RM		= rm -f

SRCS	= ./Phonebook.cpp \
			./Contact.cpp \
			./main.cpp
OBJS	= $(SRCS:.cpp=.o)

all	: $(NAME)

$(NAME)	: $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

%.o : %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	$(RM) *.o

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re
