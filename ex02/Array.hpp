/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alubrano <alubrano@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 16:28:07 by alubrano          #+#    #+#             */
/*   Updated: 2026/11/02 16:28:08 by alubrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <cstddef>
#include <stdexcept>


template <typename T>

class Array
{
private:
	T				*_array;
	unsigned int	_size;

public:
	Array( void );
	Array(unsigned int n);
	Array(Array const &other);
	Array&operator=(Array const &other);
	~Array();

	T &operator[](unsigned int index);
	T const &operator[](unsigned int index) const;
	unsigned int size() const;
};

#include "Array.tpp"

#endif
