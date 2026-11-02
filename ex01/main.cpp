/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alubrano <alubrano@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 16:28:04 by alubrano          #+#    #+#             */
/*   Updated: 2026/11/02 16:28:05 by alubrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cctype>
#include "iter.hpp"


template <typename T>
void	print(T const &x)
{
	std::cout << x << " ";
}

void	addOne(int &n)
{
	n++;
}

void	toUpper(std::string &s)
{
	for (size_t i = 0; i < s.length(); i++)
		s[i] = std::toupper(s[i]);
}

int main(void)
{
	std::cout << "--- tableau de int ---" << std::endl;
	int tab[5] = {1, 2, 3, 4, 5};
	iter(tab, 5, print<int>);
	std::cout << std::endl;
	iter(tab, 5, addOne);
	iter(tab, 5, print<int>);
	std::cout << std::endl;

	std::cout << "--- tableau de string ---" << std::endl;
	std::string words[2] = {"hello", "toi"};
	iter(words, 2, print<std::string>);
	std::cout << std::endl;
	iter(words, 2, toUpper);
	iter(words, 2, print<std::string>);
	std::cout << std::endl;

	std::cout << "--- tableau const de double ---" << std::endl;
	const double nums[3] = {1.5, 2.5, 3.5};
	iter(nums, 3, print<double>);
	std::cout << std::endl;

	return 0;
}
