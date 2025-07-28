/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phkevin <phkevin@42luxembourg.lu>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 03:52:11 by phkevin           #+#    #+#             */
/*   Updated: 2025/04/04 03:52:11 by phkevin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
#define BASE_HPP

#include <cstdlib>
#include <ctime>
#include "Param.hpp"

class Base
{
	public:
		//==============================
		// CONSTRUCTEUR
		//==============================

		virtual ~Base();
};

Base* Generate(void);

void identify(Base* p);
void identify(Base& p);

class A : public Base {};
class B : public Base {};
class C : public Base {};

//Type unknown
class D : public Base {};


#endif //BASE_HPP