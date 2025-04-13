/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmodrzej <dmodrzej@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 22:00:40 by dmodrzej          #+#    #+#             */
/*   Updated: 2025/04/13 19:14:06 by dmodrzej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <cstdlib>

RPN::RPN() {}

RPN::RPN(const RPN &other)
{
	*this = other;
}

RPN &RPN::operator=(const RPN &other)
{
	if (this != &other)
		this->stack = other.stack;
	return *this;
}

RPN::~RPN() {}

bool RPN::isOperator(const std::string& token) const
{
    return token == "+" || token == "-" || token == "*" || token == "/";
}

int RPN::applyOperator(const std::string &op, int a, int b)
{
    if (op == "+") return a + b;
    if (op == "-") return a - b;
    if (op == "*") return a * b;
    if (op == "/")
	{
        if (b == 0) throw std::runtime_error("Error: division by zero");
        return a / b;
    }
    throw std::runtime_error("Error: unknown operator");
}

int RPN::evaluate(const std::string &expression)
{
    std::istringstream iss(expression);
    std::string token;

    while (iss >> token)
	{
        if (isOperator(token))
		{
            if (stack.size() < 2)
                throw std::runtime_error("Error: not enough operands");

            int b = stack.top(); stack.pop();
            int a = stack.top(); stack.pop();

            int result = applyOperator(token, a, b);
            stack.push(result);
        }
        else if (token.length() == 1 && isdigit(token[0]))
            stack.push(token[0] - '0');
        else
            throw std::runtime_error("Error: invalid token \"" + token + "\"");
    }

    if (stack.size() != 1)
        throw std::runtime_error("Error: invalid expression");

    return stack.top();
}
