/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phkevin <phkevin@42luxembourg.lu>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 10:41:34 by phkevin           #+#    #+#             */
/*   Updated: 2025/03/03 10:42:48 by phkevin          ###   Luxembour.lu      */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
	private:
		int nb;
		static const int bit = 8;

	public:
		Fixed();
		Fixed(Fixed& fix);
		Fixed& operator=(const Fixed& other);
		int getRawBits(void) const;
		void setRawBits(int const raw);
		~Fixed();
};
#endif // FIXED_HPP