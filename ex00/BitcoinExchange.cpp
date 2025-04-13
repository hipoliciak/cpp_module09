/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmodrzej <dmodrzej@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 21:57:35 by dmodrzej          #+#    #+#             */
/*   Updated: 2025/04/13 19:10:33 by dmodrzej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <fstream>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <cctype>

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const std::string &inputFile)
{
    loadDatabase(inputFile);
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
	*this = other;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
    if (this != &other)
        this->rates = other.rates;
    return *this;
}

BitcoinExchange::~BitcoinExchange() {}

void BitcoinExchange::loadDatabase(const std::string &inputFile)
{
	std::ifstream file(inputFile.c_str());
	if (!file.is_open())
	{
		std::cerr << "Error: could not open input file." << std::endl;
		return ;
	}

	std::string line;
	std::getline(file, line);

	while (std::getline(file, line))
	{
        std::istringstream ss(line);
        std::string date, rateStr;
        if (std::getline(ss, date, ',') && std::getline(ss, rateStr))
		{
            double rate = std::strtod(rateStr.c_str(), NULL);
            rates[date] = rate;
        }
    }
}

double BitcoinExchange::getExchangeRate(const std::string &date) const
{
    std::map<std::string, double>::const_iterator it = rates.lower_bound(date);
    if (it == rates.begin() && it->first > date)
        throw std::runtime_error("No earlier date found in DB.");
    if (it == rates.end() || it->first > date)
        --it;
    return it->second;
}

bool isLeapYear(int year)
{
    return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
}

bool isValidDate(const std::string &date)
{
    if (date.length() != 10 || date[4] != '-' || date[7] != '-')
        return false;

    std::string y = date.substr(0, 4);
    std::string m = date.substr(5, 2);
    std::string d = date.substr(8, 2);

    for (int i = 0; i < 4; ++i) if (!isdigit(y[i]))
		return false;
    for (int i = 0; i < 2; ++i) if (!isdigit(m[i]) || !isdigit(d[i]))
		return false;

    int year = atoi(y.c_str());
    int month = atoi(m.c_str());
    int day = atoi(d.c_str());

    if (month < 1 || month > 12 || day < 1)
        return false;

    int daysInMonth[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    if (month == 2 && isLeapYear(year))
        return day <= 29;
    
    return day <= daysInMonth[month - 1];
}

std::string trim(const std::string &str)
{
	size_t first = str.find_first_not_of(" \t");
	size_t last = str.find_last_not_of(" \t");
	return str.substr(first, last - first + 1);
}

bool isValidValue(const std::string &valueStr, double &value)
{
	char *end;
	value = std::strtod(valueStr.c_str(), &end);
	return (*end == '\0' && value >= 0.0 && value <= 1000.0);
}
