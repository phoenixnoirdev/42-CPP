/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phkevin <phkevin@42luxembourg.lu>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 10:20:35 by phkevin           #+#    #+#             */
/*   Updated: 2025/03/03 10:23:41 by phkevin          ###   Luxembour.lu      */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

/**
 * @brief Constructeur de la classe Weapon.
 *
 * Ce constructeur initialise une nouvelle arme avec le type spécifié.
 *
 * @param typ Le type de l'arme à créer.
 */
Weapon::Weapon(std::string typ)
{
	type = typ;
}

/**
 * @brief Définit le type de l'arme.
 *
 * Cette méthode permet d'assigner un type à l'arme.
 *
 * @param typ Le type à attribuer à l'arme.
 */
void	Weapon::setType(std::string typ)
{
	type = typ;
}

/**
 * @brief Récupère le type de l'arme.
 *
 * Cette méthode retourne une référence constante vers le type de l'arme.
 *
 * @return const std::string& Le type de l'arme.
 */
const std::string&	Weapon::getType() const
{
	return type;
}