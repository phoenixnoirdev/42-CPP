/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phkevin <phkevin@42luxembourg.lu>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 04:36:54 by phkevin           #+#    #+#             */
/*   Updated: 2025/03/14 04:36:17 by phkevin          ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

//==============================
// Consturcteur
//==============================

/**
 * @brief Constructeur pour `DiamondTrap`.
 *
 * Initialise un objet `DiamondTrap` avec un nom, et configure les propriétés des sous-classes `ClapTrap`, `ScavTrap` 
 * et `FragTrap` en utilisant ce même nom.
 * Définit les points de vie, les points d'énergie et les points de dégâts d'attaque spécifiques au `DiamondTrap`.
 *
 * @param str Le nom du `DiamondTrap` à créer.
 */
DiamondTrap::DiamondTrap(const std::string str) : ClapTrap(str), ScavTrap(str), FragTrap(str)
{
	this->name = str;
	this->ClapTrap::setName(name + "_clap_name");
	this->setHitPoints(100);
	this->setEnergyPoints(50);
	this->setAtkDamagePoints(30);
	
	std::cout << YELLOW << "------------------------------------" << RESET << std::endl;
	std::cout << CYAN << "Creation of DiamondTrap: " << GREEN << this->name << RESET << std::endl;
	std::cout << YELLOW << "------------------------------------" << RESET << std::endl;
	std::cout << "- Hit Points = " << this->getHitPoints() << std::endl;
	std::cout << "- Energy Points = " << this->getEnergyPoints() << std::endl;
	std::cout << "- Attack Damage = " << this->getAtkDamagePoints() << std::endl;
	std::cout << YELLOW << "------------------------------------" << RESET << std::endl;
}

/**
 * @brief Constructeur de copie pour `DiamondTrap`.
 *
 * Copie les propriétés du `DiamondTrap` source dans un nouvel objet, en initialisant également les sous-classes `ClapTrap`, 
 * `FragTrap` et `ScavTrap` avec le nom du `DiamondTrap` source.
 *
 * @param other L'objet `DiamondTrap` à copier.
 */
DiamondTrap::DiamondTrap(const DiamondTrap& other): ClapTrap(other.getName()), ScavTrap(other.getName()), FragTrap(other.getName())
{
	std::cout << MAGENTA << "-= DiamondTrap =- " << RESET << "Copy of DiamondTrap: " << other.getName() << std::endl;

	this->setName(other.getName());
	this->setHitPoints(other.getHitPoints());
	this->setEnergyPoints(other.getEnergyPoints());
	this->setAtkDamagePoints(other.getAtkDamagePoints());
}

/**
 * @brief Surcharge de l'opérateur d'affectation pour `DiamondTrap`.
 *
 * Copie les propriétés du `DiamondTrap` source vers l'objet actuel, y compris le nom, les points de vie, d'énergie et de dégâts.
 * Le nom de `ClapTrap` est modifié pour inclure un suffixe "_clap_name".
 *
 * @param other L'objet `DiamondTrap` à copier.
 * @return Référence à l'objet actuel après l'affectation.
 */
DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other)
{
	std::cout << MAGENTA << "-= DiamondTrap =- " << RESET << "Operator constructor call." << std::endl;
	if (this != &other)
	{
		this->setName(other.getName());
		this->ClapTrap::setName(name + "_clap_name");
		this->setHitPoints(other.getHitPoints());
		this->setEnergyPoints(other.getEnergyPoints());
		this->setAtkDamagePoints(other.getAtkDamagePoints());
	}
	return *this;
}

/**
 * @brief Détruit le `DiamondTrap` et affiche ses caractéristiques.
 *
 * Affiche un message détaillant la destruction du `DiamondTrap` ainsi que ses points de vie, d'énergie et de dégâts.
 */
DiamondTrap::~DiamondTrap()
{
	std::cout << YELLOW << "------------------------------------" << RESET << std::endl;
	std::cout << RED << "Destruction of DiamondTrap: " << GREEN << this->name << RESET << std::endl;
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
 * @brief Affiche l'identité complète du `DiamondTrap`.
 *
 * Affiche le nom du `DiamondTrap` ainsi que celui de son parent `ClapTrap`, avec un formatage coloré.
 */
void DiamondTrap::whoAmI()
{
	std::cout << MAGENTA << "-= DiamondTrap =- " << RESET << "I am a DiamondTrap Named " << getDiamName() << " and my ClapTrap name is " << GREEN << ClapTrap::getName() << RESET << std::endl;
}

/**
 * @brief Récupère le nom du `DiamondTrap` formaté.
 *
 * Retourne le nom du `DiamondTrap` avec une couleur appliquée.
 *
 * @return Nom du `DiamondTrap` formaté.
 */
std::string DiamondTrap::getDiamName() const
{
	return GREEN + this->DiamondTrap::name + RESET;
}
