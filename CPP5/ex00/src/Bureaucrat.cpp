/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phkevin <phkevin@42luxembourg.lu>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 03:01:28 by phkevin           #+#    #+#             */
/*   Updated: 2025/03/23 03:01:28 by phkevin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"

//=================
//Constructeur
//=================

/**
 * @brief Constructeur par défaut de Bureaucrat.
 *
 * Initialise un Bureaucrat avec un nom par défaut "NoName"
 * et un grade de 150 (le plus bas).
 */
Bureaucrat::Bureaucrat() : _name("NoName"), _grade(150)
{
	std::cout << "Constructer called" << std::endl;
}

/**
 * @brief Constructeur de Bureaucrat avec paramètres.
 *
 * Initialise un Bureaucrat avec un nom donné et un grade.
 * Vérifie si le grade est valide avant de l'affecter.
 *
 * @param name Nom du Bureaucrat.
 * @param grade Grade du Bureaucrat (doit être dans les limites autorisées).
 */
Bureaucrat::Bureaucrat(std::string name, int grade)
{
	IsLimitGrade(name, grade);

	this->_name = name;
	this->_grade = grade;

	std::cout << "Constructer called" << std::endl;
}

/**
 * @brief Constructeur par copie de Bureaucrat.
 *
 * Copie les attributs d'un autre Bureaucrat.
 *
 * @param obj Bureaucrat à copier.
 */
Bureaucrat::Bureaucrat(Bureaucrat const &obj)
{
	*this = obj;

	std::cout << "Copy constructor called" << std::endl;
}

/**
 * @brief Opérateur d'affectation de Bureaucrat.
 *
 * Permet de copier les attributs d'un autre Bureaucrat.
 *
 * @param obj Bureaucrat à copier.
 * @return Référence vers l'instance actuelle de Bureaucrat.
 */
Bureaucrat Bureaucrat::operator=(Bureaucrat const& obj)
{
	if (this != &obj)
		*this = obj;

	std::cout << "Operator constructor called" << std::endl;

	return *this;
}

/**
 * @brief Destructeur de Bureaucrat.
 *
 * Détruit l'instance de Bureaucrat et libère les ressources associées.
 */
Bureaucrat::~Bureaucrat()
{
	std::cout << "Destructor called" << std::endl;
}



//=================
//Fonction
//=================

/**
 * @brief Obtient le grade du bureaucrate.
 *
 * @return Le grade actuel du bureaucrate.
 */
int Bureaucrat::GetGrade() const
{ 
	return this->_grade;
}

/**
 * @brief Obtient le nom du bureaucrate.
 *
 * @return Le nom du bureaucrate sous forme de chaîne de caractères.
 */
std::string Bureaucrat::GetName() const 
{ 
	return this->_name;
}

/**
 * @brief Incrémente le grade du bureaucrate.
 *
 * Augmente le grade du bureaucrate de 1, en vérifiant les limites.
 * Affiche un message indiquant le changement de grade.
 */
void Bureaucrat::IncreGrade()
{
	int GraTmp = GetGrade();

	IsLimitGrade(GetName(), GraTmp + 1);
	
	this->_grade++;

	std::cout << "Le bureaucrat " << GREEN << GetName() << RESET << " vient de passez du grade " << GREEN << GraTmp << RESET << " au grade " << GREEN << GetGrade() << RESET << std::endl;
}

/**
 * @brief Décrémente le grade du bureaucrate.
 *
 * Réduit le grade du bureaucrate de 1, en vérifiant les limites.
 * Affiche un message indiquant le changement de grade.
 */
void Bureaucrat::DecreGrade()
{
	int GraTmp = GetGrade();

	IsLimitGrade(GetName(), GraTmp - 1);

	this->_grade--;

	std::cout << "Le bureaucrat " << GREEN << GetName() << RESET << " vient de passez du grade " << GREEN << GraTmp << RESET << " au grade " << GREEN << GetGrade() << RESET << std::endl;
}

/**
 * @brief Vérifie si le grade est dans les limites autorisées.
 *
 * @param name Nom du bureaucrate.
 * @param grade Grade à vérifier.
 * @throws GradeException si le grade est hors des limites définies.
 */
void Bureaucrat::IsLimitGrade(std::string name,  int grade)
{
	if (grade < GRADE_MIN)
		throw GradeException("Bureaucrat - " + name + ": grade trop petit.");
	if (grade > GRADE_MAX)
		throw GradeException("Bureaucrat - " + name + ": grade trop grand.");
}

/**
 * Surcharge de l'operateur d'insertion pour afficher un objet Bureaucrat.
 *
 * @param os Le flux de sortie.
 * @param obj L'objet Bureaucrat à afficher.
 * @return Le flux de sortie avec les informations de l'objet Bureaucrat.
 */
std::ostream& operator<<(std::ostream& os, const Bureaucrat& obj)
{
	os << "Bureaucrat - " << GREEN << obj.GetName() << RESET << ", grade " << GREEN << obj.GetGrade() << RESET << "." << std::endl;
	return os;
}
