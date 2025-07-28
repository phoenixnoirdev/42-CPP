/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phkevin <phkevin@42luxembourg.lu>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 08:34:34 by phkevin           #+#    #+#             */
/*   Updated: 2025/03/31 08:34:34 by phkevin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

//==============================
// CONSTRUCTEUR
//==============================

/**
 * @brief Constructeur par d�faut de la classe Serializer.
 *
 * Affiche un message de confirmation lorsque le constructeur par d�faut
 * de la classe Serializer est appel�.
 */
Serializer::Serializer()
{
	std::cout << GREEN << LOGO << RESET << "Default constructor called" << std::endl;
}

/**
 * @brief Constructeur de copie de la classe Serializer.
 *
 * Ce constructeur cr�e une nouvelle instance de Serializer en copiant
 * l'objet pass� en param�tre et affiche un message de confirmation.
 *
 * @param obj L'objet Serializer � copier.
 */
Serializer::Serializer(const Serializer &obj)
{
	*this = obj;

	std::cout << GREEN << LOGO << RESET << "Copy constructor called" << std::endl;
}

/**
 * @brief Surcharge de l'op�rateur d'assignation pour la classe Serializer.
 *
 * Cette fonction permet d'assigner un objet Serializer � un autre,
 * tout en �vitant l'auto-assignation. Un message est affich� pour
 * indiquer que l'op�rateur a �t� appel�.
 *
 * @param obj L'objet Serializer � assigner.
 * @return Serializer& L'objet actuel apr�s l'assignation.
 */
Serializer& Serializer::operator=(const Serializer &obj)
{
	if (this != &obj)
		*this = obj;

	std::cout << GREEN << LOGO << RESET << "Operator constructor called" << std::endl;

	return *this;
}

/**
 * @brief Destructeur de la classe Serializer.
 *
 * Ce destructeur est appel� lors de la destruction d'un objet Serializer.
 * Un message est affich� pour indiquer que le destructeur a �t� invoqu�.
 */
Serializer::~Serializer()
{
	std::cout << GREEN << LOGO << RESET << "Destructor called" << std::endl;
}


//==============================
// FONCTION
//==============================

/**
 * @brief S�rialise un pointeur vers un objet Data en une valeur uintptr_t.
 *
 * Cette m�thode permet de convertir un pointeur de type Data* en une valeur
 * enti�re de type uintptr_t � l'aide d'un cast de type. Cela permet de
 * s�rialiser un objet pour le stockage ou la transmission sous forme de
 * valeur enti�re.
 *
 * @param ptr Le pointeur vers l'objet Data � s�rialiser.
 * @return La valeur s�rialis�e sous forme de uintptr_t.
 */
uintptr_t Serializer::Serialize(Data *ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

/**
 * @brief D�s�rialise une valeur uintptr_t en un pointeur vers un objet Data.
 *
 * Cette m�thode permet de convertir une valeur de type uintptr_t en un
 * pointeur vers un objet Data � l'aide d'un cast de type. Cela permet de
 * reconstruire l'objet original � partir de sa valeur s�rialis�e.
 *
 * @param raw La valeur s�rialis�e sous forme de uintptr_t.
 * @return Le pointeur vers l'objet Data d�s�rialis�.
 */
Data* Serializer::Deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data*>(raw));
}