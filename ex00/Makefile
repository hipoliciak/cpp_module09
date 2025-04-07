# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dmodrzej <dmodrzej@student.42warsaw.pl>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/07 22:00:01 by dmodrzej          #+#    #+#              #
#    Updated: 2025/04/07 22:00:04 by dmodrzej         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

name = btc

sources = main.cpp BitcoinExchange.cpp

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

.PHONY: all clean fclean re