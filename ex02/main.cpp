/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmodrzej <dmodrzej@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 22:01:39 by dmodrzej          #+#    #+#             */
/*   Updated: 2025/04/13 20:11:56 by dmodrzej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char** argv)
{
	if (argc < 3)
	{
		std::cerr << "Error: not enough arguments." << std::endl;
		return 1;
	}
	for (int i = 1; i < argc; ++i)
	{
		std::string arg(argv[i]);
		for (size_t j = 0; j < arg.length(); ++j)
		{
			if (!isdigit(arg[j]))
			{
				std::cerr << "Error: invalid character in input." << std::endl;
				return 1;
			}
		}
		long val = std::atol(arg.c_str());
		if (val < 0 || val > INT_MAX)
		{
			std::cerr << "Error: invalid number." << std::endl;
			return 1;
		}
	}
	
    try
	{
        PmergeMe sorter;
        sorter.run(argc, argv);
    }
	catch (const std::exception &e)
	{
        std::cerr << e.what() << std::endl;
        return 1;
    }
    return 0;
}
