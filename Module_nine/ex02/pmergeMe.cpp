/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pmergeMe.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nqasem <nqasem@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 18:50:55 by nqasem            #+#    #+#             */
/*   Updated: 2026/07/23 17:48:47 by nqasem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pmergeMe.hpp"

PmergeMe::PmergeMe() : _vecTime(0), _deqTime(0) {}

PmergeMe::PmergeMe(const PmergeMe& other) {
    *this = other;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
    if (this != &other) {
        this->_vec = other._vec;
        this->_deq = other._deq;
        this->_vecTime = other._vecTime;
        this->_deqTime = other._deqTime;
    }
    return *this;
}

PmergeMe::~PmergeMe() {}

std::vector<size_t> PmergeMe::_generateJacobsthalSequence(size_t size) {
    std::vector<size_t> jacob;
    if (size == 0) return jacob;

    jacob.push_back(1);
    if (size == 1) return jacob;

    jacob.push_back(3);
    while (true) {
        size_t next = jacob[jacob.size() - 1] + 2 * jacob[jacob.size() - 2];
        if (next >= size) {
            jacob.push_back(next);
            break;
        }
        jacob.push_back(next);
    }
    return jacob;
}

// ----------------------------------------------------
// --------------- STD::VECTOR IMPLEMENTATION ---------
// ----------------------------------------------------
void PmergeMe::_sortVector(std::vector<int>& vec) {
    size_t n = vec.size();
    if (n <= 1) return;

    int straggler = -1;
    bool hasStraggler = (n % 2 != 0);
    if (hasStraggler) {
        straggler = vec.back();
        vec.pop_back();
    }

    std::vector<Pair> pairs;
    for (size_t i = 0; i < vec.size(); i += 2) {
        Pair p;
        if (vec[i] > vec[i + 1]) {
            p.main = vec[i];
            p.pending = vec[i + 1];
        } else {
            p.main = vec[i + 1];
            p.pending = vec[i];
        }
        pairs.push_back(p);
    }

    std::vector<int> mainChain;
    for (size_t i = 0; i < pairs.size(); ++i) {
        mainChain.push_back(pairs[i].main);
    }
    _sortVector(mainChain);

    std::vector<int> pendingChain;
    for (size_t i = 0; i < mainChain.size(); ++i) {
        for (size_t j = 0; j < pairs.size(); ++j) {
            if (mainChain[i] == pairs[j].main) {
                pendingChain.push_back(pairs[j].pending);
                break;
            }
        }
    }

    if (!pendingChain.empty()) {
        mainChain.insert(mainChain.begin(), pendingChain[0]);
    }

    if (pendingChain.size() > 1) {
        std::vector<size_t> jacobSeq = _generateJacobsthalSequence(pendingChain.size());
        size_t lastInsertedIndex = 1;

        for (size_t k = 1; k < jacobSeq.size(); ++k) {
            size_t targetIndex = jacobSeq[k] - 1;
            if (targetIndex >= pendingChain.size()) {
                targetIndex = pendingChain.size() - 1;
            }

            for (size_t i = targetIndex; i >= lastInsertedIndex; --i) {
                int valToInsert = pendingChain[i];
                std::vector<int>::iterator pos = std::lower_bound(mainChain.begin(), mainChain.end(), valToInsert);
                mainChain.insert(pos, valToInsert);
                if (i == lastInsertedIndex) break; // حماية من الحلقات اللا نهائية لـ size_t
            }
            lastInsertedIndex = targetIndex + 1;
            if (lastInsertedIndex >= pendingChain.size()) break;
        }
    }

    if (hasStraggler) {
        std::vector<int>::iterator pos = std::lower_bound(mainChain.begin(), mainChain.end(), straggler);
        mainChain.insert(pos, straggler);
    }

    vec = mainChain;
}

// ----------------------------------------------------
// --------------- STD::DEQUE IMPLEMENTATION ----------
// ----------------------------------------------------
void PmergeMe::_sortDeque(std::deque<int>& deq) {
    size_t n = deq.size();
    if (n <= 1) return;

    int straggler = -1;
    bool hasStraggler = (n % 2 != 0);
    if (hasStraggler) {
        straggler = deq.back();
        deq.pop_back();
    }

    std::deque<Pair> pairs;
    for (size_t i = 0; i < deq.size(); i += 2) {
        Pair p;
        if (deq[i] > deq[i + 1]) {
            p.main = deq[i];
            p.pending = deq[i + 1];
        } else {
            p.main = deq[i + 1];
            p.pending = deq[i];
        }
        pairs.push_back(p);
    }

    std::deque<int> mainChain;
    for (size_t i = 0; i < pairs.size(); ++i) {
        mainChain.push_back(pairs[i].main);
    }
    _sortDeque(mainChain);

    std::deque<int> pendingChain;
    for (size_t i = 0; i < mainChain.size(); ++i) {
        for (size_t j = 0; j < pairs.size(); ++j) {
            if (mainChain[i] == pairs[j].main) {
                pendingChain.push_back(pairs[j].pending);
                break;
            }
        }
    }

    if (!pendingChain.empty()) {
        mainChain.push_front(pendingChain[0]);
    }

    if (pendingChain.size() > 1) {
        std::vector<size_t> jacobSeq = _generateJacobsthalSequence(pendingChain.size());
        size_t lastInsertedIndex = 1;

        for (size_t k = 1; k < jacobSeq.size(); ++k) {
            size_t targetIndex = jacobSeq[k] - 1;
            if (targetIndex >= pendingChain.size()) {
                targetIndex = pendingChain.size() - 1;
            }

            for (size_t i = targetIndex; i >= lastInsertedIndex; --i) {
                int valToInsert = pendingChain[i];
                std::deque<int>::iterator pos = std::lower_bound(mainChain.begin(), mainChain.end(), valToInsert);
                mainChain.insert(pos, valToInsert);
                if (i == lastInsertedIndex) break;
            }
            lastInsertedIndex = targetIndex + 1;
            if (lastInsertedIndex >= pendingChain.size()) break;
        }
    }

    if (hasStraggler) {
        std::deque<int>::iterator pos = std::lower_bound(mainChain.begin(), mainChain.end(), straggler);
        mainChain.insert(pos, straggler);
    }

    deq = mainChain;
}

// ----------------------------------------------------
// --------------- RUN & DISPLAY LOGIC ----------------
// ----------------------------------------------------
void PmergeMe::run(int argc, char** argv) {
    if (argc < 2) {
        std::cout << "Error" << std::endl;
        return;
    }

    // التحقق من المدخلات أنها أرقام صحيحة موجبة فقط
    for (int i = 1; i < argc; ++i) {
        std::string arg = argv[i];
        if (arg.empty()) {
            std::cout << "Error" << std::endl;
            return;
        }
        for (size_t j = 0; j < arg.length(); ++j) {
            if (!std::isdigit(arg[j])) {
                std::cout << "Error" << std::endl;
                return;
            }
        }
        long val = std::atol(arg.c_str());
        if (val <= 0 || val > 2147483647) {
            std::cout << "Error" << std::endl;
            return;
        }
        _vec.push_back(static_cast<int>(val));
        _deq.push_back(static_cast<int>(val));
    }

    std::cout << "Before: ";
    for (size_t i = 0; i < _vec.size(); ++i) {
        std::cout << _vec[i] << (i + 1 == _vec.size() ? "" : " ");
    }
    std::cout << std::endl;

    clock_t startVec = clock();
    _sortVector(_vec);
    clock_t endVec = clock();
	_vecTime = static_cast<double>(endVec - startVec) / CLOCKS_PER_SEC * 1000000.0;
    // 3. قياس وفرز std::deque
    clock_t startDeq = clock();
    _sortDeque(_deq);
    clock_t endDeq = clock();
	_deqTime = static_cast<double>(endDeq - startDeq) / CLOCKS_PER_SEC * 1000000.0;
    // 4. طباعة العناصر بعد الفرز والوقت المستغرق
    std::cout << "After:  ";
    for (size_t i = 0; i < _vec.size(); ++i) {
        std::cout << _vec[i] << (i + 1 == _vec.size() ? "" : " ");
    }
    std::cout << std::endl;

    std::cout << "Time to process a range of " << _vec.size() 
              << " elements with std::vector : " << _vecTime << " us" << std::endl;

    std::cout << "Time to process a range of " << _deq.size() 
              << " elements with std::deque  : " << _deqTime << " us" << std::endl;
}