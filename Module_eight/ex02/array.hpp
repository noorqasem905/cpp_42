/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nqasem <nqasem@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 23:00:40 by nqasem            #+#    #+#             */
/*   Updated: 2026/03/01 23:22:02 by nqasem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP
#include <cstddef>
#include <stdexcept>

template <typename T>
class Array
{
public:
    Array() : _size(0), _data(NULL) {}
    explicit Array(unsigned int n) : _size(n), _data(new T[n]()) {}
    Array(const Array& other) : _size(other._size), _data(new T[other._size]())
    {
        for (unsigned int i = 0; i < _size; ++i)
            _data[i] = other._data[i];
    }
    ~Array() { delete[] _data; }

    Array& operator=(const Array& other)
    {
        if (this != &other)
        {
            delete[] _data;
            _size = other._size;
            _data = new T[_size]();
            for (unsigned int i = 0; i < _size; ++i)
                _data[i] = other._data[i];
        }
        return *this;
    }

    T& operator[](unsigned int index)
    {
        if (index >= _size)
            throw std::out_of_range("Index out of bounds");
        return _data[index];
    }

    const T& operator[](unsigned int index) const
    {
        if (index >= _size)
            throw std::out_of_range("Index out of bounds");
        return _data[index];
    }

    unsigned int size() const { return _size; }

private:
    unsigned int _size;
    T* _data;
};

#endif