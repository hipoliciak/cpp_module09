/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmodrzej <dmodrzej@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 22:01:39 by dmodrzej          #+#    #+#             */
/*   Updated: 2025/04/13 20:19:16 by dmodrzej         ###   ########.fr       */
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
