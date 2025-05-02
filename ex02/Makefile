# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dmodrzej <dmodrzej@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/07 21:56:39 by dmodrzej          #+#    #+#              #
#    Updated: 2025/05/02 17:26:36 by dmodrzej         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

name = PmergeMe

sources = main.cpp PmergeMe.cpp

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
	./$(name) 3 5 9 7 4
	./$(name) `shuf -i 1-100 -n 10 | tr "\n" " "`
	./$(name) `shuf -i 1-1000 -n 30 | tr "\n" " "`
#	./$(name) `shuf -i 1-100000 -n 3000 | tr "\n" " "`
#	./$(name) 1 test
#	./$(name) 2147483648 3
#	./$(name) "-1" "2"

.PHONY: all clean fclean re test