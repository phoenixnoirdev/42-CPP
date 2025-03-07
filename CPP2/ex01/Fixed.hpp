/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phkevin <phkevin@42luxembourg.lu>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 11:26:53 by phkevin           #+#    #+#             */
/*   Updated: 2025/03/05 14:50:23 by phkevin          ###   Luxembour.lu      */
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
		Fixed& operator=(const Fixed& other);
		int getRawBits(void) const;
		void setRawBits(int const raw);
		int	toInt() const;
		float toFloat() const;
		~Fixed();
};

std::ostream& operator<<(std::ostream& os, const Fixed& other);

#endif // FIXED_HPP