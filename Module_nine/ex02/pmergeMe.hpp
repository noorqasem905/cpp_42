/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pmergeMe.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nqasem <nqasem@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 18:50:55 by nqasem            #+#    #+#             */
/*   Updated: 2026/07/23 17:48:47 by nqasem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <string>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include <cctype>
#include <algorithm>
#include <sys/time.h>

class PmergeMe {
private:
    std::vector<int> _vec;
    std::deque<int>  _deq;

    double _vecTime;
    double _deqTime;

    struct Pair {
        int main;
        int pending;
    };

    void _sortVector(std::vector<int>& vec);
    void _insertVector(std::vector<int>& mainChain, std::vector<int>& pending, int straggler);

    void _sortDeque(std::deque<int>& deq);
    void _insertDeque(std::deque<int>& mainChain, std::deque<int>& pending, int straggler);

	std::vector<size_t> _generateJacobsthalSequence(size_t size);

public:
    PmergeMe();
    PmergeMe(const PmergeMe& other);
    PmergeMe& operator=(const PmergeMe& other);
    ~PmergeMe();

    void run(int argc, char** argv);
};

#endif