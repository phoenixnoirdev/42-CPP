/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phkevin <phkevin@42luxembourg.lu>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 02:05:48 by phkevin           #+#    #+#             */
/*   Updated: 2025/03/14 02:05:48 by phkevin          ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

//==============================
// Consturcteur
//==============================

/**
 * @brief Constructeur de la classe FragTrap.
 *
 * Initialise un objet FragTrap avec un nom donné et définit ses points de vie,
 * d'énergie et de dégâts d'attaque selon les valeurs par défaut spécifiques
 * aux FragTrap.
 *
 * @param str Nom du FragTrap.
 */
FragTrap::FragTrap(const std::string str) : ClapTrap(str)
{
	this->setHitPoints(100);
	this->setEnergyPoints(100);
	this->setAtkDamagePoints(30);

	std::cout << YELLOW << "------------------------------------" << RESET << std::endl;
	std::cout << CYAN << "Creation of FragTrap: " << GREEN << this->getName() << RESET << std::endl;
	std::cout << YELLOW << "------------------------------------" << RESET << std::endl;
	std::cout << "- Hit Points = " << this->getHitPoints() << std::endl;
	std::cout << "- Energy Points = " << this->getEnergyPoints() << std::endl;
	std::cout << "- Attack Damage = " << this->getAtkDamagePoints() << std::endl;
	std::cout << YELLOW << "------------------------------------" << RESET << std::endl;
}

/**
 * @brief Constructeur par copie de la classe FragTrap.
 *
 * Crée une copie d'un objet `FragTrap` existant en recopiant ses attributs.
 *
 * @param other Objet `FragTrap` à copier.
 */
FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other)
{
	std::cout << MAGENTA << "-= FragTrap =- " << RESET << "Copy of FragTrap: " << other.getName() << std::endl;
	this->setName(other.getName());
	this->setHitPoints(other.getHitPoints());
	this->setEnergyPoints(other.getEnergyPoints());
	this->setAtkDamagePoints(other.getAtkDamagePoints());
}

/**
 * @brief Surcharge de l'opérateur d'affectation pour la classe FragTrap.
 *
 * Copie les attributs d'un autre objet `FragTrap` dans l'instance actuelle,
 * en vérifiant l'auto-affectation.
 *
 * @param other Objet `FragTrap` à copier.
 * @return Référence vers l'objet `FragTrap` actuel.
 */
FragTrap& FragTrap::operator=(const FragTrap& other)
{
	std::cout << MAGENTA << "-= FragTrap =- " << RESET << "Operator constructor call." << std::endl;
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
 * @brief Destructeur de la classe FragTrap.
 *
 * Affiche un message lors de la destruction de l'objet `FragTrap`,
 * indiquant ses attributs avant suppression.
 */
FragTrap::~FragTrap()
{
	std::cout << YELLOW << "------------------------------------" << RESET << std::endl;
	std::cout << RED << "Destruction of FragTrap: " << this->getName() << RESET << std::endl;
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
 * @brief Demande un high five aux autres.
 *
 * Affiche un message indiquant que le `FragTrap` propose un high five pour motiver son équipe.
 */
void FragTrap::highFivesGuys(void)
{
	std::cout << MAGENTA << "-= FragTrap =- " << RESET << this->getName() << " high five, we can do it." << std::endl;
}
