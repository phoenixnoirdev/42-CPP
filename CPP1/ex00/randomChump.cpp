/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phkevin <phkevin@42luxembourg.lu>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 10:17:52 by phkevin           #+#    #+#             */
/*   Updated: 2025/02/03 10:17:52 by phkevin          ###   Luxembour.lu      */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/**
 * @brief Cr�e un zombie temporaire et l'annonce.
 *
 * Cette fonction instancie un objet Zombie sur la pile
 * et appelle sa m�thode Announce().
 *
 * @param name Nom � attribuer au zombie.
 */
void randomChump(std::string name)
{
	Zombie z(name);
	z.Announce();
}