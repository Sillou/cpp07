/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alubrano <alubrano@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 16:28:09 by alubrano          #+#    #+#             */
/*   Updated: 2026/11/02 16:28:10 by alubrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


template <typename T>
Array<T>::Array( void ) : _array(NULL), _size(0)
{

}

template <typename T>
Array<T>::~Array( void )
{
	delete[] _array;
}

template <typename T>
unsigned int Array<T>::size() const
{
	return (_size);
}

template <typename T>
Array<T>::Array(unsigned int n) : _array(new T[n]()), _size(n)
{

}

template <typename T>
Array<T>::Array(Array<T> const &other) : _array(new T[other._size]()), _size(other._size)
{
	for(unsigned int i = 0; i < _size; i++)
		_array[i] = other._array[i];
}

template <typename T>
Array<T> &Array<T>::operator=(Array<T> const &other)
{
	if (this != &other)
	{
		T	*tmp = new T[other._size]();
		for (unsigned int i = 0; i < other._size; i++)
			tmp[i] = other._array[i];
		delete[] _array;
		_array = tmp;
		_size = other._size;
	}
	return (*this);
}

template <typename T>
T &Array<T>::operator[](unsigned int index)
{
	if(index >= _size)
		throw std::out_of_range("index out of bounds");
	return (_array[index]);
}

template <typename T>
T const &Array<T>::operator[](unsigned int index) const
{
	if(index >= _size)
		throw std::out_of_range("index out of bounds");
	return (_array[index]);
}
