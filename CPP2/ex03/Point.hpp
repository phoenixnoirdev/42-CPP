/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phkevin <phkevin@42luxembourg.lu>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 13:07:29 by phkevin           #+#    #+#             */
/*   Updated: 2025/03/11 09:02:10 by phkevin          ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP

#include <math.h>
#include "Fixed.hpp"

class Point
{
private:
	Fixed FixedX, FixedY;

public:
	Point();
	Point(const Fixed x, const Fixed y);
	Point(const Point &pt);
	Point& operator=(const Point &other);
	float getx() const;
	float gety() const;
	~Point();
};

bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif // POINT_HPP