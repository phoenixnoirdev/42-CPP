/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phkevin <phkevin@42luxembourg.lu>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 11:09:39 by phkevin           #+#    #+#             */
/*   Updated: 2025/03/27 11:09:39 by phkevin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"

//=================
//Constructeur
//=================

/**
 * @brief Constructeur par d�faut de Bureaucrat.
 *
 * Initialise un Bureaucrat avec un nom par d�faut "NoName"
 * et un grade de 150 (le plus bas).
 */
Bureaucrat::Bureaucrat() : _name("NoName"), _grade(150)
{
	std::cout << GREEN << "Bureaucrat: " << RESET << "Constructer called" << std::endl;
}

/**
 * @brief Constructeur de Bureaucrat avec param�tres.
 *
 * Initialise un Bureaucrat avec un nom donn� et un grade.
 * V�rifie si le grade est valide avant de l'affecter.
 *
 * @param name Nom du Bureaucrat.
 * @param grade Grade du Bureaucrat (doit �tre dans les limites autoris�es).
 */
Bureaucrat::Bureaucrat(std::string name, int grade)
{
	IsLimitGrade(name, grade);

	this->_name = name;
	this->_grade = grade;

	std::cout << GREEN << "Bureaucrat: " << RESET << "Constructer called" << std::endl;
}

/**
 * @brief Constructeur par copie de Bureaucrat.
 *
 * Copie les attributs d'un autre Bureaucrat.
 *
 * @param obj Bureaucrat � copier.
 */
Bureaucrat::Bureaucrat(Bureaucrat const& obj)
{
	*this = obj;

	std::cout << GREEN << "Bureaucrat: " << RESET << "Copy constructor called" << std::endl;
}

/**
 * @brief Op�rateur d'affectation de Bureaucrat.
 *
 * Permet de copier les attributs d'un autre Bureaucrat.
 *
 * @param obj Bureaucrat � copier.
 * @return R�f�rence vers l'instance actuelle de Bureaucrat.
 */
Bureaucrat Bureaucrat::operator=(Bureaucrat const& obj)
{
	if (this != &obj)
		*this = obj;

	std::cout << GREEN << "Bureaucrat: " << RESET << "Operator constructor called" << std::endl;

	return *this;
}

/**
 * @brief Destructeur de Bureaucrat.
 *
 * D�truit l'instance de Bureaucrat et lib�re les ressources associ�es.
 */
Bureaucrat::~Bureaucrat()
{
	std::cout << GREEN << "Bureaucrat: " << RESET << "Destructor called" << std::endl;
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
 * @return Le nom du bureaucrate sous forme de cha�ne de caract�res.
 */
std::string Bureaucrat::GetName() const
{
	return this->_name;
}

/**
 * @brief Incr�mente le grade du bureaucrate.
 *
 * Augmente le grade du bureaucrate de 1, en v�rifiant les limites.
 * Affiche un message indiquant le changement de grade.
 */
void Bureaucrat::IncreGrade()
{
	int GraTmp = GetGrade();

	IsLimitGrade(GetName(), GraTmp + 1);

	this->_grade++;

	std::cout << GREEN << "Bureaucrat: " << RESET << "Le bureaucrat " << GREEN << GetName() << RESET << " vient de passez du grade " << GREEN << GraTmp << RESET << " au grade " << GREEN << GetGrade() << RESET << std::endl;
}

/**
 * @brief D�cr�mente le grade du bureaucrate.
 *
 * R�duit le grade du bureaucrate de 1, en v�rifiant les limites.
 * Affiche un message indiquant le changement de grade.
 */
void Bureaucrat::DecreGrade()
{
	int GraTmp = GetGrade();

	IsLimitGrade(GetName(), GraTmp - 1);

	this->_grade--;

	std::cout << GREEN << "Bureaucrat: " << RESET << "Le bureaucrat " << GREEN << GetName() << RESET << " vient de passez du grade " << GREEN << GraTmp << RESET << " au grade " << GREEN << GetGrade() << RESET << std::endl;
}

/**
 * @brief V�rifie si le grade est dans les limites autoris�es.
 *
 * @param name Nom du bureaucrate.
 * @param grade Grade � v�rifier.
 * @throws GradeException si le grade est hors des limites d�finies.
 */
void Bureaucrat::IsLimitGrade(std::string name, int grade)
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
 * @param obj L'objet Bureaucrat � afficher.
 * @return Le flux de sortie avec les informations de l'objet Bureaucrat.
 */
std::ostream& operator<<(std::ostream& os, const Bureaucrat& obj)
{
	os << GREEN << "Bureaucrat: " << RESET << "Bureaucrat " << GREEN << obj.GetName() << RESET << ", grade " << GREEN << obj.GetGrade() << RESET << "." << std::endl;
	return os;
}

/**
 * @brief Fonction permettant � un Bureaucrat de signer un formulaire.
 *
 * Cette m�thode permet � un Bureaucrat de signer un formulaire. Si la raison est vide,
 * le message indique simplement que le Bureaucrat a sign� le formulaire. Si une raison
 * est fournie, le message indique que le Bureaucrat n'a pas pu signer le formulaire en raison
 * de cette raison.
 *
 * @param form Le formulaire � signer.
 * @param reason La raison pour laquelle le Bureaucrat ne pourrait pas signer le formulaire.
 */
void Bureaucrat::signForm(Form* form, const std::string& reason)
{
	if (reason.empty())
		std::cout << GREEN << this->GetName() << RESET << " signe le document" << GREEN << form->GetName() << RESET << std::endl;
	else
		std::cout << GREEN << this->GetName() << RESET << " ne peu signer le document " << GREEN << form->GetName() << RESET << " car " << GREEN << reason << RESET << std::endl;
}