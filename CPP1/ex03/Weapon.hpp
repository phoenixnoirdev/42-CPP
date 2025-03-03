/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phkevin <phkevin@42luxembourg.lu>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 10:20:59 by phkevin           #+#    #+#             */
/*   Updated: 2025/03/03 10:21:04 by phkevin          ###   Luxembour.lu      */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>

class Weapon
{
private:
	std::string type;

public:
	Weapon(std::string typ);

	void				setType(std::string typ);
	const std::string&	getType() const;
};

#endif // WEAPON_HPP