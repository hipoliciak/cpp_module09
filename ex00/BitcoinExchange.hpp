/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmodrzej <dmodrzej@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 21:57:31 by dmodrzej          #+#    #+#             */
/*   Updated: 2025/04/13 19:10:17 by dmodrzej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <map>
#include <string>

class BitcoinExchange
{
	public:
		BitcoinExchange();
		BitcoinExchange(const std::string &inputFile);
		BitcoinExchange(const BitcoinExchange &other);
		BitcoinExchange &operator=(const BitcoinExchange &other);
		~BitcoinExchange();

		double getExchangeRate(const std::string &date) const;

	private:
		std::map<std::string, double> rates;
		void loadDatabase(const std::string &inputFile);
};

bool isLeapYear(int year);
bool isValidDate(const std::string &date);
bool isValidValue(const std::string &valueStr, double &value);
std::string trim(const std::string &str);
