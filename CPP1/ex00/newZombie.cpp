/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phkevin <phkevin@42luxembourg.lu>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 10:17:42 by phkevin           #+#    #+#             */
/*   Updated: 2025/02/03 10:17:42 by phkevin          ###   Luxembour.lu      */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/**
 * @brief Cr�e un nouveau zombie sur le tas.
 *
 * Cette fonction alloue dynamiquement un objet Zombie
 * et retourne un pointeur vers celui-ci.
 *
 * @param name Nom � attribuer au zombie.
 * @return Zombie* Pointeur vers le nouveau zombie.
 */
Zombie *newZombie(std::string name)
{
	Zombie *z = new Zombie(name);
	return z;
}