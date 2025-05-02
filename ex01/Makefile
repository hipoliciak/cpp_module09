# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dmodrzej <dmodrzej@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/07 21:56:39 by dmodrzej          #+#    #+#              #
#    Updated: 2025/05/02 17:09:54 by dmodrzej         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

name = RPN

sources = main.cpp RPN.cpp

objects = $(sources:.cpp=.o)

all: $(name)

$(name): $(objects)
	c++ -Wall -Wextra -Werror -std=c++98 $(objects) -o $(name)

%.o: %.cpp
	c++ -Wall -Wextra -Werror -std=c++98 -c $< -o $@

clean:
	rm $(objects)

fclean: clean
	rm $(name)

re: fclean all

test:
	./$(name) "8 9 * 9 - 9 - 9 - 4 - 1 +"
	./$(name) "7 7 * 7 -"
	./$(name) "1 2 * 2 / 2 * 2 4 - +"
	./$(name) "1 2 + 3 * 9 4 / +"
#	./$(name) "1 0 / 0 *"
#	./$(name) "(1 + 1)"
#	./$(name) "10 2 +"

.PHONY: all clean fclean re test