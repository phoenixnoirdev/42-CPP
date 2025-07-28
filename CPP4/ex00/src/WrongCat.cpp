/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phkevin <phkevin@42luxembourg.lu>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 11:14:32 by phkevin           #+#    #+#             */
/*   Updated: 2025/03/15 11:14:32 by phkevin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/WrongCat.hpp"

//==============================
// Consturcteur
//==============================

/**
 * @brief Constructeur par d�faut de la classe WrongCat.
 *
 * Ce constructeur appelle le constructeur par d�faut de la classe Animal en lui passant "WrongCat" comme type.
 * Affiche un message indiquant que le constructeur par d�faut de la classe WrongCat a �t� appel�.
 */
WrongCat::WrongCat() : WrongAnimal("WrongCat")
{
	std::cout << GREEN << "WRONG-CAT" << RESET << " Default constructor called" << std::endl;
}

/**
 * @brief Constructeur de la classe WrongCat avec un type personnalis�.
 *
 * Ce constructeur appelle le constructeur de la classe Animal avec le type pass� en param�tre.
 * Affiche un message indiquant que le constructeur de la classe WrongCat a �t� appel�.
 *
 * @param str Le type de l'animal (en l'occurrence "WrongCat").
 */
WrongCat::WrongCat(std::string str) : WrongAnimal(str)
{
	std::cout << GREEN << "WRONG-CAT" << RESET << " Default constructor called" << std::endl;
}

/**
 * @brief Constructeur de copie de la classe WrongCat.
 *
 * Ce constructeur cr�e un nouvel objet WrongCat en copiant les informations d'un autre objet WrongCat.
 * Il appelle la m�thode `setType` pour d�finir le type de l'animal.
 * Affiche un message indiquant que le constructeur de copie de la classe WrongCat a �t� appel�.
 *
 * @param obj L'objet WrongCat � copier.
 */
WrongCat::WrongCat(const WrongCat& obj)
{
	this->setType(obj.getType());

	std::cout << GREEN << "WRONG-CAT" << RESET << " Copy constructor called" << std::endl;
}

/**
 * @brief Surcharge de l'op�rateur d'affectation de la classe WrongCat.
 *
 * Cet op�rateur permet d'affecter un objet WrongCat � un autre objet WrongCat. Il copie les informations de l'objet source
 * dans l'objet actuel et v�rifie que l'objet � affecter n'est pas lui-m�me.
 * Affiche un message indiquant que l'op�rateur d'affectation de la classe WrongCat a �t� appel�.
 *
 * @param obj L'objet WrongCat � affecter � l'objet actuel.
 * @return Un objet WrongCat apr�s l'affectation.
 */
WrongCat& WrongCat::operator=(const WrongCat& obj)
{
	std::cout << GREEN << "WRONG-CAT" << RESET << " Operator constructor call." << std::endl;
	if (this != &obj)
		this->setType(obj.getType());
	return *this;
}

/**
 * @brief Destructeur de la classe WrongCat.
 *
 * Le destructeur est appel� lors de la destruction d'un objet de la classe WrongCat.
 * Il affiche un message indiquant que le destructeur de la classe WrongCat a �t� appel�.
 */

WrongCat::~WrongCat()
{
	std::cout << GREEN << "WRONG-CAT" << RESET << " Destructor called." << std::endl;
}

//==============================
// Fonction
//==============================

/**
 * @brief Fait le bruit caract�ristique d'un chat erron�.
 *
 * Cette m�thode affiche un message simulant le bruit d'un chat erron� : "Miaou miaou".
 * Elle est appel�e lorsque l'on souhaite que l'objet WrongCat fasse un bruit sp�cifique.
 */
void WrongCat::makeSound() const
{
	std::cout << GREEN << "WRONG-CAT" << RESET << " Miaou miaou." << std::endl;
}