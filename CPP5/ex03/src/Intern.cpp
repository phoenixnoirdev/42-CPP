/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phkevin <phkevin@42luxembourg.lu>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 12:07:19 by phkevin           #+#    #+#             */
/*   Updated: 2025/03/28 12:07:19 by phkevin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

//==============================
// CONSTRUCTEUR
//==============================

/**
 * Constructeur par d�faut de la classe Intern.
 * Affiche un message indiquant son appel.
 */
Intern::Intern()
{
	std::cout << GREEN << LOGOINT << RESET << "Default constructor called" << std::endl;

	this->_form[0] = "presidential pardon request";
	this->_form[1] = "robotomy request";
	this->_form[2] = "shrubbery creation request";
}

/**
 * Constructeur par copie de la classe Intern.
 * Copie l'objet pass� en param�tre.
 */
Intern::Intern(Intern& obj)
{
	*this = obj;

	std::cout << GREEN << LOGOINT << RESET << "Copy constructor called" << std::endl;
}

/**
 * Op�rateur d'affectation de la classe Intern.
 * Assigne les valeurs de l'objet pass� en param�tre � l'objet courant.
 */
Intern& Intern::operator=(Intern& obj)
{
	if (this != &obj)
		*this = obj;

	std::cout << GREEN << LOGOINT << RESET << "Copy constructor called" << std::endl;

	return *this;
}

/**
 * Destructeur de la classe Intern.
 * Libere les ressources utilisees par l'objet.
 */
Intern::~Intern()
{
	std::cout << GREEN << LOGOINT << RESET << "Destructor called" << std::endl;
}



//==============================
// FONCTION
//==============================

/**
 * Cree un formulaire en fonction du nom fourni.
 * @param nameform Nom du formulaire a creer.
 * @param target Cible du formulaire.
 * @return Pointeur vers une instance de formulaire creee.
 * @throws Form::GradeException si le type de formulaire est inconnu.
 */
Form* Intern::makeForm(std::string nameform, std::string target)
{
	int ref = -1;

	for (int i = 0; i < 3; ++i)
	{
		if (_form[i] == nameform)
		{
			ref = i;
			break;
		}
	}

	switch (ref)
	{
		case 0:
			return new PresidentialPardonForm(target);
		case 1:
			return new RobotomyRequestForm(target);
		case 2:
			return new ShrubberyCreationForm(target);
		default:
			throw Form::GradeException("Form type not found");
	};
}