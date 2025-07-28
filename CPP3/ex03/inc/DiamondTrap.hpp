/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phkevin <phkevin@42luxembourg.lu>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 04:40:54 by phkevin           #+#    #+#             */
/*   Updated: 2025/03/14 04:40:17 by phkevin          ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
private:
	std::string name;

public:
	//==============================
	// CONSTRUCTEUR
	//==============================
	DiamondTrap(const std::string str);
	DiamondTrap(const DiamondTrap& other);
	DiamondTrap& operator=(const DiamondTrap& other);
	~DiamondTrap();

	//==============================
	// FONCTION
	//==============================
	void whoAmI();

	//==============================
	// GETTER AND SETTER
	//==============================
	std::string getDiamName() const;

};
#endif // DIAMONDTRAP_HPP
