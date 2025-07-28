/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phkevin <phkevin@42luxembourg.lu>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 09:26:48 by phkevin           #+#    #+#             */
/*   Updated: 2025/03/31 11:12:22 by phkevin          ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

//==============================
// Consturcteur
//==============================

/**
 * @brief Constructeur de la classe ClapTrap avec un nom personnalisé.
 *
 * Initialise un objet ClapTrap avec :
 * - Un nom spécifié en paramètre.
 * - 10 points de vie.
 * - 10 points d'énergie.
 * - 0 points de dégâts d'attaque.
 *
 * Affiche également un message indiquant la création du ClapTrap
 * ainsi que ses statistiques initiales.
 *
 * @param str Nom du ClapTrap.
 */
ClapTrap::ClapTrap(const std::string str) : hit_points(10), energy_points(10), attack_damage(0)
{
	name = str;

	std::cout << YELLOW << "------------------------------------" << RESET << std::endl;
	std::cout << CYAN << "Creation of ClapTrap: " << GREEN << this->getName() << RESET << std::endl;
	std::cout << YELLOW << "------------------------------------" << RESET << std::endl;
	std::cout << "- Hit Points = " << this->getHitPoints() << std::endl;
	std::cout << "- Energy Points = " << this->getEnergyPoints() << std::endl;
	std::cout << "- Attack Damage = " << this->getAtkDamagePoints() << std::endl;
	std::cout << YELLOW << "------------------------------------" << RESET << std::endl;
}

/**
 * @brief Constructeur par copie de la classe ClapTrap.
 *
 * Initialise un nouvel objet ClapTrap en copiant les attributs d'un
 * autre ClapTrap existant. Un message est affiché pour indiquer la
 * copie du ClapTrap.
 *
 * @param other Référence vers l'objet ClapTrap à copier.
 */
ClapTrap::ClapTrap(const ClapTrap& other)
{
	std::cout << MAGENTA << "-= ClapTrap =- " << RESET << "Copy of ClapTrap: " << other.getName() << std::endl;

	this->name = other.name;
	this->hit_points = other.hit_points;
	this->energy_points = other.energy_points;
	this->attack_damage = other.attack_damage;
}

/**
 * @brief Surcharge de l'opérateur d'affectation pour ClapTrap.
 *
 * Copie les attributs d'un autre objet ClapTrap dans l'instance
 * actuelle, en s'assurant d'éviter l'auto-affectation. Un message
 * est affiché pour indiquer l'appel de l'opérateur.
 *
 * @param other Référence vers l'objet ClapTrap à copier.
 * @return Référence vers l'instance actuelle mise à jour.
 */
ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
	std::cout << MAGENTA << "-= ClapTrap =- " << RESET << "Operator constructor call." << std::endl;
	if (this != &other)
	{
		this->name = other.name;
		this->hit_points = other.hit_points;
		this->energy_points = other.energy_points;
		this->attack_damage = other.attack_damage;
	}
	return *this;
}

/**
 * @brief Destructeur de ClapTrap.
 *
 * Affiche un message indiquant la destruction de l'instance,
 * ainsi que ses attributs avant sa suppression.
 */
ClapTrap::~ClapTrap()
{
	std::cout << YELLOW << "------------------------------------" << RESET << std::endl;
	std::cout << RED << "Destruction of ClapTrap: " << this->getName() << RESET << std::endl;
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
 * @brief Attaque une cible en infligeant des dégâts.
 *
 * @param target Nom de la cible attaquée.
 *
 * @details Si ClapTrap a suffisamment de points de vie et d'énergie,
 * il attaque la cible et diminue son énergie de 1.
 * Sinon, un message indique qu'il ne peut pas attaquer.
 */
void ClapTrap::attack(const std::string& target)
{
	if (this->getEnergyPoints() > 0 && this->getHitPoints() > 0)
	{
		std::cout << MAGENTA << "-= ClapTrap =- " << RESET << this->getName() << " try to attack " << target << std::endl;
		this->setEnergyPoints(this->getEnergyPoints() - 1);
	}
	else
		std::cout << this->getName() << " cannot attack because he is no longer able to attack." << std::endl;
}

/**
 * @brief Applique des dégâts à ClapTrap.
 *
 * Cette fonction diminue les points de vie de ClapTrap en fonction de la quantité
 * de dégâts reçus. Si les points de vie de ClapTrap sont déjà à zéro, un message
 * est affiché pour indiquer que ClapTrap est mort.
 *
 * @param amount Nombre de points de dégâts reçus.
 */
void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->getHitPoints() > 0)
	{
		std::cout << MAGENTA << "-= ClapTrap =- " << RESET << this->getName() << " has just suffered an attack: " << amount << " damage." << std::endl;
		this->setHitPoints(this->getHitPoints() - amount);
	}
	else
	{
		std::cout << MAGENTA << "-= ClapTrap =- " << RESET << this->getName() << " died." << std::endl;
		std::cout << MAGENTA << "-= ClapTrap =- " << RESET << this->getName() << " It's wrong to hit a man on the ground." << std::endl;
	}
}

/**
 * @brief Répare ClapTrap en utilisant des points d'énergie.
 *
 * Cette fonction restaure les points de vie de ClapTrap en fonction de la quantité
 * de points de vie fournis, en utilisant un point d'énergie. Si ClapTrap n'a plus
 * d'énergie ou si ses points de vie sont à zéro, un message est affiché pour indiquer
 * que la réparation ne peut pas être effectuée.
 *
 * @param amount Nombre de points de vie à restaurer.
 */
void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->getEnergyPoints() > 0 && this->getHitPoints() > 0)
	{
		std::cout << MAGENTA << "-= ClapTrap =- " << RESET << "First aid was given to " << this->getName() << " against 1 energy point for " << amount << " pv." << std::endl;
		this->setHitPoints(this->getHitPoints() + amount);
		this->setEnergyPoints(this->getEnergyPoints() - 1);
	}
	else
		std::cout << MAGENTA << "-= ClapTrap =- " << RESET << "First aid cannot be given to " << this->getName() << " because he has no more energy or he is already dead." << std::endl;
}

//==============================
// Getter and setter
//==============================

/**
 * @brief Définit le nom de ClapTrap.
 *
 * Cette fonction permet de définir un nouveau nom pour l'objet ClapTrap. Le nom est stocké sous forme de chaîne de caractères.
 *
 * @param nam Le nom à attribuer à ClapTrap.
 */
void ClapTrap::setName(std::string str)
{
	name = str;
}

/**
 * @brief Récupère le nom de ClapTrap.
 *
 * Cette fonction retourne le nom de ClapTrap, avec une couleur définie pour la sortie,
 * et le formatage nécessaire pour afficher le nom dans un format spécifique.
 *
 * @return std::string Le nom de ClapTrap, formaté avec une couleur.
 */
std::string ClapTrap::getName() const
{
	return GREEN + this->name + RESET;
}

/**
 * @brief Modifie les points de vie de ClapTrap.
 *
 * Cette fonction permet de définir les points de vie (PV) de ClapTrap et affiche un message indiquant que ses PV ont fluctué.
 *
 * @param i Le nombre de points de vie à attribuer à ClapTrap.
 */
void ClapTrap::setHitPoints(int i)
{
	std::cout << MAGENTA << "-= ClapTrap =- " << RESET << this->getName() << " sees his PV fluctuate." << std::endl;
	hit_points = i;
}

/**
 * @brief Récupère les points de vie actuels de ClapTrap.
 *
 * Cette fonction retourne le nombre actuel de points de vie (PV) de ClapTrap.
 *
 * @return int Le nombre de points de vie de ClapTrap.
 */
int ClapTrap::getHitPoints() const
{
	return this->hit_points;
}

/**
 * @brief Modifie les points d'énergie de ClapTrap.
 *
 * Cette fonction permet de modifier le nombre de points d'énergie (PM) de ClapTrap.
 * Un message est affiché pour indiquer que les points d'énergie fluctuent.
 *
 * @param i Le nouveau nombre de points d'énergie de ClapTrap.
 */
void ClapTrap::setEnergyPoints(int i)
{
	std::cout << MAGENTA << "-= ClapTrap =- " << RESET << this->getName() << " sees his PM fluctuate." << std::endl;
	energy_points = i;
}

/**
 * @brief Récupère les points d'énergie de ClapTrap.
 *
 * Cette fonction permet de récupérer le nombre actuel de points d'énergie (PM) de ClapTrap.
 *
 * @return Le nombre actuel de points d'énergie de ClapTrap.
 */
int	ClapTrap::getEnergyPoints() const
{
	return this->energy_points;
}

/**
 * @brief Modifie les points de dégâts d'attaque de ClapTrap.
 *
 * Cette fonction permet de définir la valeur des points de dégâts d'attaque (ATK) de ClapTrap.
 * Elle affiche également un message indiquant que les points d'attaque de ClapTrap ont changé.
 *
 * @param i La nouvelle valeur des points de dégâts d'attaque.
 */
void ClapTrap::setAtkDamagePoints(int i)
{
	std::cout << MAGENTA << "-= ClapTrap =- " << RESET << this->getName() << " sees his ATK fluctuate." << std::endl;
	attack_damage = i;
}

/**
 * @brief Récupère les points de dégâts d'attaque de ClapTrap.
 *
 * Cette fonction retourne la valeur actuelle des points de dégâts d'attaque (ATK) de ClapTrap.
 *
 * @return La valeur des points de dégâts d'attaque de ClapTrap.
 */
unsigned int ClapTrap::getAtkDamagePoints() const
{
	return this->attack_damage;
}
