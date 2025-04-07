/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmodrzej <dmodrzej@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 21:57:09 by dmodrzej          #+#    #+#             */
/*   Updated: 2025/04/07 23:33:29 by dmodrzej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <fstream>
#include <iostream>
#include <sstream>
#include <iomanip>

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cerr << "Usage: " << argv[0] << " <input_file>" << std::endl;
        return 1;
    }

    BitcoinExchange exchange("data.csv");
    std::ifstream input(argv[1]);
    if (!input.is_open())
    {
        std::cerr << "Error: could not open input file." << std::endl;
        return 1;
    }

    std::string line;
    std::getline(input, line);

    while (std::getline(input, line))
    {
        std::istringstream ss(line);
        std::string date, valueStr;

        if (std::getline(ss, date, '|') && std::getline(ss, valueStr))
        {
            date = trim(date);
            valueStr = trim(valueStr);

            double value;
            if (!isValidDate(date))
            {
                std::cerr << "Error: invalid date => " << date << std::endl;
                continue;
            }
            if (!isValidValue(valueStr, value))
            {
                std::cerr << "Error: invalid value => " << valueStr << std::endl;
                continue;
            }

            try
            {
                double rate = exchange.getExchangeRate(date);
                double result = value * rate;

                if (result == static_cast<int>(result))
                    std::cout << date << " => " << value << " = " << static_cast<int>(result) << std::endl;
                else
                    std::cout << date << " => " << value << " = " << result << std::endl;
            }
            catch (const std::exception &e)
            {
                std::cerr << "Error: " << e.what() << std::endl;
            }
        }
        else
        {
            std::cerr << "Error: bad input => " << line << std::endl;
        }
    }

    return 0;
}
