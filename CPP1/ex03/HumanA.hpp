/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phkevin <phkevin@42luxembourg.lu>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 10:21:23 by phkevin           #+#    #+#             */
/*   Updated: 2025/03/03 10:21:52 by phkevin          ###   Luxembour.lu      */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
#define HUMANA_HPP

#include <iostream>
#include <string>
#include "Weapon.hpp"

class HumanA
{
private:
	std::string name;
	Weapon& weapon;

public:
	HumanA(std::string nam, Weapon& a);

	void	attack();
};

#endif // HUMANA_HPP