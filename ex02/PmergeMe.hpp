/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmodrzej <dmodrzej@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 22:01:54 by dmodrzej          #+#    #+#             */
/*   Updated: 2025/05/02 17:25:17 by dmodrzej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <vector>
#include <deque>
#include <string>
#include <cstdlib>
#include <ctime>
#include <stdexcept>
#include <climits>

class PmergeMe
{
	public:
		PmergeMe();
		PmergeMe(const PmergeMe &other);
		PmergeMe& operator=(const PmergeMe &other);
		~PmergeMe();

		void run(int argc, char** argv);
		
	private:
		std::vector<int> _vec;
		std::deque<int> _deq;

		void parseInput(int argc, char** argv);
		void printSequence(const std::string &prefix, const std::vector<int> &container);
		void printSequence(const std::string &prefix, const std::deque<int> &container);

		void fordJohnsonSort(std::vector<int> &vec);
		void fordJohnsonSort(std::deque<int> &deq);

		void mergeInsertSortVector(std::vector<int> &vec);
		void mergeInsertSortDeque(std::deque<int> &deq);
};
