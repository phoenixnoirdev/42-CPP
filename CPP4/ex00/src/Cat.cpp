/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phkevin <phkevin@42luxembourg.lu>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 11:47:42 by phkevin           #+#    #+#             */
/*   Updated: 2025/03/15 11:47:42 by phkevin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Cat.hpp"

//==============================
// Consturcteur
//==============================

/**
 * @brief Constructeur par d�faut de la classe Cat.
 *
 * Ce constructeur appelle le constructeur par d�faut de la classe Animal en lui passant "Cat" comme type.
 * Affiche un message indiquant que le constructeur par d�faut de la classe Cat a �t� appel�.
 */
Cat::Cat() : Animal("Cat")
{
	std::cout << GREEN << "CAT" << RESET << " Default constructor called" << std::endl;
}

/**
 * @brief Constructeur de la classe Cat avec un type personnalis�.
 *
 * Ce constructeur appelle le constructeur de la classe Animal avec le type pass� en param�tre.
 * Affiche un message indiquant que le constructeur de la classe Cat a �t� appel�.
 *
 * @param str Le type de l'animal (en l'occurrence "Cat").
 */
Cat::Cat(std::string str) : Animal(str)
{
	std::cout << GREEN << "CAT" << RESET << " Default constructor called" << std::endl;
}

/**
 * @brief Constructeur de copie de la classe Cat.
 *
 * Ce constructeur cr�e un nouvel objet Cat en copiant les informations d'un autre objet Cat.
 * Il appelle la m�thode `setType` pour d�finir le type de l'animal.
 * Affiche un message indiquant que le constructeur de copie de la classe Cat a �t� appel�.
 *
 * @param obj L'objet Cat � copier.
 */
Cat::Cat(const Cat& obj)
{
	this->setType(obj.getType());

	std::cout << GREEN << "CAT" << RESET << " Copy constructor called" << std::endl;
}

/**
 * @brief Surcharge de l'op�rateur d'affectation de la classe Cat.
 *
 * Cet op�rateur permet d'affecter un objet Cat � un autre objet Cat. Il copie les informations de l'objet source
 * dans l'objet actuel et v�rifie que l'objet � affecter n'est pas lui-m�me.
 * Affiche un message indiquant que l'op�rateur d'affectation de la classe Cat a �t� appel�.
 *
 * @param obj L'objet Cat � affecter � l'objet actuel.
 * @return Un objet Cat apr�s l'affectation.
 */
Cat& Cat::operator=(const Cat& obj)
{
	std::cout << GREEN << "CAT" << RESET << " Operator constructor call." << std::endl;
	if (this != &obj)
		this->setType(obj.getType());
	return *this;
}

/**
 * @brief Destructeur de la classe Cat.
 *
 * Le destructeur est appel� lors de la destruction d'un objet de la classe Cat.
 * Il affiche un message indiquant que le destructeur de la classe Cat a �t� appel�.
 */

Cat::~Cat()
{
	std::cout << GREEN << "CAT" << RESET << " Destructor called." << std::endl;
}

//==============================
// Fonction
//==============================

/**
 * @brief Fait le bruit caract�ristique d'un chat.
 *
 * Cette m�thode affiche un message simulant le bruit d'un chat : "Miaou miaou".
 * Elle est appel�e lorsque l'on souhaite que l'objet Cat fasse un bruit sp�cifique.
 */
void Cat::makeSound() const
{
	std::cout << GREEN << "CAT" << RESET << " Miaou miaou." << std::endl;
}