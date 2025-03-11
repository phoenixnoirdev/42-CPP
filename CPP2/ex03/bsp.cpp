/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phkevin <phkevin@42luxembourg.lu>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 13:07:26 by phkevin           #+#    #+#             */
/*   Updated: 2025/03/11 08:55:33 by phkevin          ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

/**
 * @brief Vérifie si un point est strictement à l'intérieur d'un triangle.
 * 
 * Cette fonction utilise la méthode des aires pour déterminer si le point `point`
 * est contenu à l'intérieur du triangle défini par les points `a`, `b` et `c`.
 * 
 * @param a Premier sommet du triangle.
 * @param b Deuxième sommet du triangle.
 * @param c Troisième sommet du triangle.
 * @param point Point à tester.
 * @return true Si le point est strictement à l'intérieur du triangle.
 * @return false Si le point est en dehors ou sur un des côtés du triangle.
 */
bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	float aire = 0, res1 = 0, res2 = 0, res3 = 0;

	aire = std::abs ((a.getx() * (b.gety() - c.gety()) + b.getx() * (c.gety() - a.gety()) + c.getx() * (a.gety() - b.gety())) / 2.0f);

	res1 = std::abs ((point.getx() * (b.gety() - c.gety()) + b.getx() * (c.gety() - point.gety()) + c.getx() * (point.gety() - b.gety())) / 2.0f);
	res2 = std::abs ((a.getx() * (point.gety() - c.gety()) + point.getx() * (c.gety() - a.gety()) + c.getx() * (a.gety() - point.gety())) / 2.0f);
	res3 = std::abs ((a.getx() * (b.gety() - point.gety()) + b.getx() * (point.gety() - a.gety()) + point.getx() * (a.gety() - b.gety())) / 2.0f);

	if(aire == (res1 + res2 + res3) && res1 > 0 && res2 > 0 && res3 > 0)
		return true;
	
	return false;
}
