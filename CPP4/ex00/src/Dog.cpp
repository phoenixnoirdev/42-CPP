/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phkevin <phkevin@42luxembourg.lu>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 11:47:39 by phkevin           #+#    #+#             */
/*   Updated: 2025/03/15 11:47:39 by phkevin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Dog.hpp"

//==============================
// Consturcteur
//==============================

/**
 * @brief Constructeur par d�faut de la classe Dog.
 *
 * Ce constructeur appelle le constructeur par d�faut de la classe Animal en lui passant "Dog" comme type.
 * Affiche un message indiquant que le constructeur par d�faut de la classe Dog a �t� appel�.
 */
Dog::Dog() : Animal("Dog")
{
	std::cout << GREEN << "DOG" << RESET << " Default constructor called" << std::endl;
}

/**
 * @brief Constructeur de la classe Dog avec un type personnalis�.
 *
 * Ce constructeur appelle le constructeur de la classe Animal avec le type pass� en param�tre.
 * Affiche un message indiquant que le constructeur de la classe Dog a �t� appel�.
 *
 * @param str Le type de l'animal (en l'occurrence "Dog").
 */
Dog::Dog(std::string str) : Animal(str)
{
	std::cout << GREEN << "DOG" << RESET << " Default constructor called" << std::endl;
}

/**
 * @brief Constructeur de copie de la classe Dog.
 *
 * Ce constructeur cr�e un nouvel objet Dog en copiant les informations d'un autre objet Dog.
 * Il appelle la m�thode `setType` pour d�finir le type de l'animal.
 * Affiche un message indiquant que le constructeur de copie de la classe Dog a �t� appel�.
 *
 * @param obj L'objet Dog � copier.
 */
Dog::Dog(const Dog& obj)
{
	this->setType(obj.getType());

	std::cout << GREEN << "DOG" << RESET << " Copy constructor called" << std::endl;
}

/**
 * @brief Surcharge de l'op�rateur d'affectation de la classe Dog.
 *
 * Cet op�rateur permet d'affecter un objet Dog � un autre objet Dog. Il copie les informations de l'objet source
 * dans l'objet actuel et v�rifie que l'objet � affecter n'est pas lui-m�me.
 * Affiche un message indiquant que l'op�rateur d'affectation de la classe Dog a �t� appel�.
 *
 * @param obj L'objet Dog � affecter � l'objet actuel.
 * @return Un objet Dog apr�s l'affectation.
 */
Dog& Dog::operator=(const Dog& obj)
{
	std::cout << GREEN << "DOG" << RESET << " Operator constructor call." << std::endl;
	if (this != &obj)
		this->setType(obj.getType());
	return *this;
}

/**
 * @brief Destructeur de la classe Dog.
 *
 * Le destructeur est appel� lors de la destruction d'un objet de la classe Dog.
 * Il affiche un message indiquant que le destructeur de la classe Dog a �t� appel�.
 */
Dog::~Dog()
{
	std::cout << GREEN << "DOG" << RESET << " Destructor called." << std::endl;
}

//==============================
// Fonction
//==============================

/**
 * @brief Fait le bruit caract�ristique d'un chien.
 *
 * Cette m�thode affiche un message simulant le bruit d'un chien : "Wouf Wouf".
 * Elle est appel�e lorsque l'on souhaite que l'objet Dog fasse un bruit sp�cifique.
 */
void Dog::makeSound() const
{
	std::cout << GREEN << "DOG" << RESET << " Wouf Wouf." << std::endl;
}