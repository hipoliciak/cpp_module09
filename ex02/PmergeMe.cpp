/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmodrzej <dmodrzej@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 22:01:46 by dmodrzej          #+#    #+#             */
/*   Updated: 2025/05/02 17:24:49 by dmodrzej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &other)
{
    *this = other;
}

PmergeMe& PmergeMe::operator=(const PmergeMe &other)
{
    if (this != &other)
	{
        this->_vec = other._vec;
        this->_deq = other._deq;
    }
    return *this;
}

PmergeMe::~PmergeMe() {}

void PmergeMe::run(int argc, char** argv)
{
    parseInput(argc, argv);
    printSequence("Before: ", _vec);

    clock_t startVec = clock();
    fordJohnsonSort(_vec);
    clock_t endVec = clock();

    clock_t startDeq = clock();
    fordJohnsonSort(_deq);
    clock_t endDeq = clock();

    printSequence("After:  ", _vec);
    std::cout << "Time to process a range of " << _vec.size()
              << " elements with std::vector: "
        	  << static_cast<double>(endVec - startVec) / CLOCKS_PER_SEC * 100
              << " us" << std::endl;

    std::cout << "Time to process a range of " << _deq.size()
              << " elements with std::deque: "
              << static_cast<double>(endDeq - startDeq) / CLOCKS_PER_SEC * 100
              << " us" << std::endl;
}

void PmergeMe::parseInput(int argc, char** argv)
{
    for (int i = 1; i < argc; ++i)
	{
        std::string arg(argv[i]);
        for (size_t j = 0; j < arg.length(); ++j)
		{
            if (!isdigit(arg[j]))
                throw std::runtime_error("Error: invalid character in input.");
        }
        long val = std::atol(arg.c_str());
        if (val < 0 || val > INT_MAX)
            throw std::runtime_error("Error: invalid number.");
        _vec.push_back(static_cast<int>(val));
        _deq.push_back(static_cast<int>(val));
    }
}

void PmergeMe::printSequence(const std::string &prefix, const std::vector<int> &container)
{
    std::cout << prefix;
    for (size_t i = 0; i < container.size(); ++i)
        std::cout << container[i] << " ";
    std::cout << std::endl;
}

void PmergeMe::printSequence(const std::string &prefix, const std::deque<int> &container)
{
    std::cout << prefix;
    for (size_t i = 0; i < container.size(); ++i)
        std::cout << container[i] << " ";
    std::cout << std::endl;
}

void PmergeMe::mergeInsertSortVector(std::vector<int> &vec)
{
    if (vec.size() <= 1)
        return;

    std::vector<std::pair<int, int> > pairs;
    std::vector<int> pendings;
    size_t i = 0;
    while (i + 1 < vec.size())
	{
        if (vec[i] > vec[i + 1])
            pairs.push_back(std::make_pair(vec[i], vec[i + 1]));
        else
            pairs.push_back(std::make_pair(vec[i + 1], vec[i]));
        i += 2;
    }
    if (i < vec.size())
        pendings.push_back(vec[i]);

    std::vector<int> mainChain;
    for (size_t j = 0; j < pairs.size(); ++j)
        mainChain.push_back(pairs[j].first);

    mergeInsertSortVector(mainChain);

    for (size_t j = 0; j < pairs.size(); ++j)
        pendings.push_back(pairs[j].second);

    for (size_t j = 0; j < pendings.size(); ++j)
	{
        std::vector<int>::iterator pos = std::lower_bound(mainChain.begin(), mainChain.end(), pendings[j]);
        mainChain.insert(pos, pendings[j]);
    }

    vec = mainChain;
}

void PmergeMe::mergeInsertSortDeque(std::deque<int> &deq)
{
    if (deq.size() <= 1)
        return;

    std::deque<std::pair<int, int> > pairs;
    std::deque<int> pendings;
    size_t i = 0;
    while (i + 1 < deq.size()) {
        if (deq[i] > deq[i + 1])
            pairs.push_back(std::make_pair(deq[i], deq[i + 1]));
        else
            pairs.push_back(std::make_pair(deq[i + 1], deq[i]));
        i += 2;
    }
    if (i < deq.size())
        pendings.push_back(deq[i]);

    std::deque<int> mainChain;
    for (size_t j = 0; j < pairs.size(); ++j)
        mainChain.push_back(pairs[j].first);

    mergeInsertSortDeque(mainChain);

    for (size_t j = 0; j < pairs.size(); ++j)
        pendings.push_back(pairs[j].second);

    for (size_t j = 0; j < pendings.size(); ++j) {
        std::deque<int>::iterator pos = std::lower_bound(mainChain.begin(), mainChain.end(), pendings[j]);
        mainChain.insert(pos, pendings[j]);
    }

    deq = mainChain;
}

void PmergeMe::fordJohnsonSort(std::vector<int> &vec)
{
    mergeInsertSortVector(vec);
}

void PmergeMe::fordJohnsonSort(std::deque<int> &deq)
{
    mergeInsertSortDeque(deq);
}
