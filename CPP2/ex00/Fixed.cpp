/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phkevin <phkevin@42luxembourg.lu>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 10:41:28 by phkevin           #+#    #+#             */
/*   Updated: 2025/03/03 10:41:46 by phkevin          ###   Luxembour.lu      */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : nb(0)
{
	std::cout << "Default constructor called\n";
}

Fixed::Fixed(Fixed &fix)
{
	nb = fix.nb;
	std::cout << "Copy constructor called\n";
}

Fixed &Fixed::operator=(const Fixed &other) {
	std::cout << "Copy assignment operator called\n";
	if (this != &other) {
		this->nb = other.nb;
	}
	return *this;
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called\n";
	return nb;
}

void Fixed::setRawBits(int const raw)
{
	nb = raw;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called\n";
}