/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phkevin <phkevin@42luxembourg.lu>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 09:26:48 by phkevin           #+#    #+#             */
/*   Updated: 2025/04/14 11:02:49 by phkevin          ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

//==============================
// Consturcteur
//==============================

/**
 * @brief Constructeur de la classe ScavTrap.
 *
 * Initialise un objet ScavTrap avec un nom donné et définit ses points de vie,
 * d'énergie et de dégâts d'attaque selon les valeurs par défaut spécifiques
 * aux ScavTrap.
 *
 * @param str Nom du ScavTrap.
 */
ScavTrap::ScavTrap(const std::string str) : ClapTrap(str)
{
	this->setHitPoints(100);
	this->setEnergyPoints(50);
	this->setAtkDamagePoints(20);

	std::cout << YELLOW << "------------------------------------" << RESET << std::endl;
	std::cout << CYAN << "Creation of ScavTrap: " << GREEN << this->getName() << RESET << std::endl;
	std::cout << YELLOW << "------------------------------------" << RESET << std::endl;
	std::cout << "- Hit Points = " << this->getHitPoints() << std::endl;
	std::cout << "- Energy Points = " << this->getEnergyPoints() << std::endl;
	std::cout << "- Attack Damage = " << this->getAtkDamagePoints() << std::endl;
	std::cout << YELLOW << "------------------------------------" << RESET << std::endl;
}

/**
 * @brief Constructeur par copie de la classe ScavTrap.
 *
 * Crée une copie d'un objet `ScavTrap` existant en recopiant ses attributs.
 *
 * @param other Objet `ScavTrap` à copier.
 */
ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other)
{
	std::cout << MAGENTA << "-= ScavTrap =-" << RESET << "Copy of ScavTrap: " << other.getName() << std::endl;

	this->setName(other.getName());
	this->setHitPoints(other.getHitPoints());
	this->setEnergyPoints(other.getEnergyPoints());
	this->setAtkDamagePoints(other.getAtkDamagePoints());
}

/**
 * @brief Surcharge de l'opérateur d'affectation pour la classe ScavTrap.
 *
 * Copie les attributs d'un autre objet `ScavTrap` dans l'instance actuelle,
 * en vérifiant l'auto-affectation.
 *
 * @param other Objet `ScavTrap` à copier.
 * @return Référence vers l'objet `ScavTrap` actuel.
 */
ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
	std::cout << MAGENTA << "-= ScavTrap =- " << RESET << "Operator constructor call." << std::endl;
	if (this != &other)
	{
		this->setName(other.getName());
		this->setHitPoints(other.getHitPoints());
		this->setEnergyPoints(other.getEnergyPoints());
		this->setAtkDamagePoints(other.getAtkDamagePoints());
	}
	return *this;
}

/**
 * @brief Destructeur de la classe ScavTrap.
 *
 * Affiche un message lors de la destruction de l'objet `ScavTrap`,
 * indiquant ses attributs avant suppression.
 */
ScavTrap::~ScavTrap()
{
	std::cout << YELLOW << "------------------------------------" << RESET << std::endl;
	std::cout << RED << "Destruction of ScavTrap: " << this->getName() << RESET << std::endl;
	std::cout << YELLOW << "------------------------------------" << RESET << std::endl;
	std::cout << "- Hit Points = " << this->getHitPoints() << std::endl;
	std::cout << "- Energy Points = " << this->getEnergyPoints() << std::endl;
	std::cout << "- Attack Damage = " << this->getAtkDamagePoints() << std::endl;
	std::cout << YELLOW << "------------------------------------" << RESET << std::endl;
}


//==============================
// Fonction
//==============================

/**
 * @brief Effectue une attaque sur une cible spécifiée.
 *
 * Réduit les points d'énergie du `ScavTrap` s'il est encore en état d'attaquer.
 * Affiche un message en fonction de l'état du `ScavTrap`.
 *
 * @param target Nom de la cible à attaquer.
 */
void ScavTrap::attack(const std::string& target)
{
	if (this->getEnergyPoints() > 0 && this->getHitPoints() > 0)
	{
		std::cout << MAGENTA << "-= ScavTrap =- " << RESET << this->getName() << " try to hard attack " << target << std::endl;
		this->setEnergyPoints(this->getEnergyPoints() - 1);
	}
	else
		std::cout << MAGENTA << "-= ScavTrap =- " << RESET << this->getName() << " cannot attack because he is no longer able to attack." << std::endl;
}

/**
 * @brief Active le mode "Garde de la porte".
 *
 * Affiche un message indiquant que le `ScavTrap` prend position pour garder la porte.
 */
void ScavTrap::guardGate()
{
	std::cout << MAGENTA << "-= ScavTrap =- " << RESET << this->getName() << " come guard the door." << std::endl;
}
