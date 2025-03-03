/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phkevin <phkevin@42luxembourg.lu>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 10:21:25 by phkevin           #+#    #+#             */
/*   Updated: 2025/03/03 10:21:32 by phkevin          ###   Luxembour.lu      */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

/**
 * @brief Constructeur de la classe HumanA.
 *
 * Ce constructeur initialise un personnage avec un nom et une arme spécifiés.
 * Le personnage reçoit l'arme par référence pour pouvoir l'utiliser lors des attaques.
 *
 * @param nam Le nom du personnage.
 * @param a L'arme du personnage, passée par référence.
 */
//HumanA::HumanA(std::string nam, Weapon& a) : name(nam), weapon(a){}
HumanA::HumanA(std::string nam, Weapon& a) : name(nam), weapon(a) {}

/**
 * @brief Effectue une attaque avec l'arme du personnage.
 *
 * Cette méthode affiche une phrase indiquant que le personnage attaque en utilisant
 * l'arme qu'il possède, en précisant le type de l'arme.
 */
void	HumanA::attack()
{
	std::cout << name + " attack avec " << weapon.getType() << std::endl;
}