/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmodrzej <dmodrzej@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 22:00:32 by dmodrzej          #+#    #+#             */
/*   Updated: 2025/04/13 19:55:07 by dmodrzej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <iostream>

int main(int argc, char** argv)
{
    if (argc != 2)
	{
        std::cerr << "Usage: ./RPN \"expression\"" << std::endl;
        return 1;
    }

    try
	{
		RPN rpn;
        int result = rpn.evaluate(argv[1]);
        std::cout << result << std::endl;
    }
	catch (const std::exception &e)
	{
        std::cerr << e.what() << std::endl;
        return 1;
    }

    return 0;
}
