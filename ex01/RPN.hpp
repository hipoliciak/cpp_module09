/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmodrzej <dmodrzej@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 22:00:48 by dmodrzej          #+#    #+#             */
/*   Updated: 2025/04/13 19:11:14 by dmodrzej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <stack>
#include <sstream>
#include <iostream>

class RPN {
	public:
		RPN();
		RPN(const RPN &other);
		RPN& operator=(const RPN &other);
		~RPN();

		int evaluate(const std::string &expression);

	private:
		std::stack<int> stack;

		bool isOperator(const std::string &token) const;
		int applyOperator(const std::string &op, int a, int b);
};
