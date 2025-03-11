/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phkevin <phkevin@42luxembourg.lu>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 13:07:08 by phkevin           #+#    #+#             */
/*   Updated: 2025/03/11 08:54:52 by phkevin          ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Point.hpp"

int main(void)
{
	Point const 	a (Fixed( 5 ), Fixed( 10 ));
	Point const 	b (Fixed( 7 ), Fixed( 5 ));
	Point const 	c (Fixed( 17 ), Fixed( 8 ));
	Point const 	pt1 (Fixed( 10 ), Fixed( 8 ));
	Point const 	pt2 (Fixed( 15 ), Fixed( 3 ));
	Point const 	pt3 (Fixed( 5 ), Fixed( 10 ));
	
	bool inTriang = bsp(a, b, c, pt1);
	bool outTriang = bsp(a, b, c, pt2);
	bool sommetTriang = bsp(a, b, c, pt3);

	std::cout << "---------------- Data triangle ----------------" << std::endl;
	std::cout << "A: " << a.getx() << " / "<<  a.gety() << std::endl;
	std::cout << "B: " << b.getx() << " / "<<  b.gety() << std::endl;
	std::cout << "C: " << c.getx() << " / "<<  c.gety() << std::endl;
	std::cout << "PT1: " << pt1.getx() << " / "<<  pt1.gety() << std::endl;
	std::cout << "PT2: " << pt2.getx() << " / "<<  pt2.gety() << std::endl;
	std::cout << "PT3: " << pt3.getx() << " / "<<  pt3.gety() << std::endl;
	std::cout << "-----------------------------------------------" << std::endl;
	std::cout << "PT1 in triangle " << inTriang << std::endl;
	std::cout << "PT2 out triangle " << outTriang << std::endl;
	std::cout << "PT3 sommmet triangle " << sommetTriang << std::endl;
	std::cout << "-----------------------------------------------" << std::endl;

	return 0;
}