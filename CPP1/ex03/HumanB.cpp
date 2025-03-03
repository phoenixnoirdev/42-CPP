/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phkevin <phkevin@42luxembourg.lu>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 10:22:37 by phkevin           #+#    #+#             */
/*   Updated: 2025/03/03 10:22:40 by phkevin          ###   Luxembour.lu      */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

/**
 * @brief Constructeur de la classe HumanB.
 *
 * Ce constructeur initialise un personnage avec un nom spécifié.
 * L'arme du personnage n'est pas encore définie à ce stade.
 *
 * @param nam Le nom du personnage.
 */
HumanB::HumanB(std::string nam)
{
	name = nam;
	weapon = NULL;
}

/**
 * @brief Définit l'arme du personnage.
 *
 * Cette méthode permet d'assigner une arme à un personnage en la passant par référence.
 *
 * @param a L'arme à attribuer au personnage.
 */
void	HumanB::setWeapon(Weapon& a)
{
	weapon = &a;
}

/**
 * @brief Effectue une attaque avec l'arme du personnage.
 *
 * Cette méthode affiche une phrase indiquant que le personnage attaque en utilisant
 * l'arme qu'il possède, en précisant le type de l'arme.
 */
void	HumanB::attack()
{
	std::cout << name + " attack avec " << weapon->getType() << std::endl;
}