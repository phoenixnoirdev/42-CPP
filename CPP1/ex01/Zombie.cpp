/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phkevin <phkevin@42luxembourg.lu>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 10:00:12 by phkevin           #+#    #+#             */
/*   Updated: 2025/03/03 10:00:24 by phkevin          ###   Luxembour.lu      */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/**
 * @brief Définit le nom du zombie.
 *
 * Cette méthode permet d'assigner un nom au zombie.
 *
 * @param nam Le nom à attribuer au zombie.
 */
void	Zombie::SetName(std::string nam)
{
	name = nam;
}

/**
 * @brief Affiche un message indiquant que le zombie parle.
 *
 * Cette fonction affiche le nom du zombie suivi de "BraiiiiiiinnnzzzZ...".
 */
void	Zombie::Announce(void) const
{
	std::cout << name + ": BraiiiiiiinnnzzzZ...\n";
}

/**
 * @brief Constructeur par défaut de la classe Zombie.
 *
 * Initialise une instance de la classe Zombie sans lui attribuer de valeurs spécifiques.
 */
Zombie::Zombie()
{

}