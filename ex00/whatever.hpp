/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alubrano <alubrano@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 16:27:50 by alubrano          #+#    #+#             */
/*   Updated: 2026/11/02 16:27:51 by alubrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP


template <typename T>

T const &min(T const &a, T const &b)
{
	if (a < b)
		return (a);
	return (b);
}


template <typename T>

void	swap(T &a, T &b)
{
	T tmp = a;
	a = b;
	b = tmp;
}


template <typename T>

T const &max(T const &a, T const &b)
{
	if (a <= b)
		return (b);
	return (a);
}

#endif
