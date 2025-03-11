/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phkevin <phkevin@42luxembourg.lu>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 10:17:55 by phkevin           #+#    #+#             */
/*   Updated: 2025/02/03 10:17:55 by phkevin          ###   Luxembour.lu      */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/**
 * @brief Affiche un message indiquant que le zombie parle.
 *
 * Cette fonction affiche le nom du zombie suivi de "BraiiiiiiinnnzzzZ...".
 */
void	Zombie::Announce(void) const
{
	std::cout << name + ": BraiiiiiiinnnzzzZ..." << std::endl;
}

/**
 * @brief Constructeur de la classe Zombie.
 *
 * Initialise un zombie avec le nom sp�cifi� en param�tre.
 *
 * @param nam Nom du zombie � assigner.
 */
Zombie::Zombie(const std::string& nam)
{
	name = nam;
}