CXX = c++

CPPFLAGS = -Wall -Wextra -Werror -std=c++98

NAME = ex02

SRCS = main.cpp Base.cpp A.cpp B.cpp C.cpp 

OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CPPFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
	$(CXX) $(CPPFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re