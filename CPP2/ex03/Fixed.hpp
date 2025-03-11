/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phkevin <phkevin@42luxembourg.lu>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 11:26:53 by phkevin           #+#    #+#             */
/*   Updated: 2025/03/11 09:05:42 by phkevin          ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <iomanip>
#include <math.h>

class Fixed
{
private:
	int nb;
	static const int bit = 8;

public:
	Fixed();
	Fixed(const Fixed& fix);
	Fixed(const int i);
	Fixed(const float i);
	bool operator<(const Fixed& other) const;
	bool operator>(const Fixed& other) const;
	bool operator<=(const Fixed& other) const;
	bool operator>=(const Fixed& other) const;
	bool operator==(const Fixed& other) const;
	bool operator!=(const Fixed& other) const;
	Fixed& operator=(const Fixed& other);
	Fixed operator+(const Fixed& other) const;
	Fixed operator-(const Fixed& other) const;
	Fixed operator*(const Fixed& other) const;
	Fixed operator/(const Fixed& other) const;
	Fixed operator++();
	Fixed operator++(int);
	Fixed operator--();
	Fixed operator--(int);
	int getRawBits(void) const;
	void setRawBits(int const raw);
	int	toInt() const;
	float toFloat() const;
	static Fixed& max(Fixed& a, Fixed& b);
	static const Fixed& max(const Fixed& a, const Fixed& b);
	~Fixed();
};

std::ostream& operator<<(std::ostream& os, const Fixed& other);

#endif // FIXED_HPP