/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phkevin <phkevin@42luxembourg.lu>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 11:09:29 by phkevin           #+#    #+#             */
/*   Updated: 2025/03/27 11:09:29 by phkevin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/PresidentialPardonForm.hpp"

//==============================
// CONSTRUCTEUR
//==============================

/**
 * @brief Constructeur par d�faut de PresidentialPardonForm.
 *
 * Initialise un formulaire de gr�ce pr�sidentielle avec un nom par d�faut,
 * un niveau requis pour la signature de 25 et un niveau requis pour
 * l'ex�cution de 5. Un message est affich� pour indiquer l'appel du
 * constructeur.
 */
PresidentialPardonForm::PresidentialPardonForm() : Form("PresidentialPardon", 25, 5)
{
	std::cout << GREEN << LOGOPRE << RESET << "Default constructor called" << std::endl;
}

/**
 * @brief Constructeur param�tr� de PresidentialPardonForm.
 *
 * Initialise un formulaire de gr�ce pr�sidentielle avec un nom sp�cifique,
 * un niveau requis pour la signature de 25 et un niveau requis pour
 * l'ex�cution de 5. Un message est affich� pour indiquer l'appel du
 * constructeur.
 *
 * @param target Nom de la cible du formulaire de gr�ce pr�sidentielle.
 */
PresidentialPardonForm::PresidentialPardonForm(std::string target) : Form("PresidentialPardon", 25, 5), _target(target)
{
	std::cout << GREEN << LOGOPRE << RESET << "Default constructor called" << std::endl;
}

/**
 * @brief Constructeur par copie de PresidentialPardonForm.
 *
 * Ce constructeur initialise un nouvel objet en copiant les valeurs
 * d'un autre PresidentialPardonForm existant. Un message est affich�
 * pour indiquer l'appel du constructeur.
 *
 * @param obj R�f�rence vers l'objet PresidentialPardonForm � copier.
 */
PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm& obj) : Form(obj.GetName(), obj.GetGradeSigne(), obj.GetGradeExec()), _target(obj._target)
{
	std::cout << GREEN << LOGOPRE << RESET << "Copy constructor called" << std::endl;
}

/**
 * @brief Surcharge de l'op�rateur d'affectation pour PresidentialPardonForm.
 *
 * Cette fonction copie les valeurs d'un autre objet PresidentialPardonForm
 * tout en �vitant l'auto-affectation. Un message est affich� pour indiquer
 * l'appel de l'op�rateur.
 *
 * @param obj R�f�rence vers l'objet � copier.
 * @return R�f�rence vers l'objet courant apr�s l'affectation.
 */
PresidentialPardonForm& PresidentialPardonForm::operator=(PresidentialPardonForm& obj)
{
	if (this != &obj)
		*this = obj;

	std::cout << GREEN << LOGOPRE << RESET << "Operator constructor called" << std::endl;

	return *this;
}

/**
 * @brief Destructeur de PresidentialPardonForm.
 *
 * Cette fonction affiche un message indiquant la destruction de l'objet,
 * incluant le logo ou l'identifiant `_logoLog`.
 */
PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << GREEN << LOGOPRE << RESET << "Destructor called" << std::endl;
}



//==============================
// FONCTION
//==============================

/**
 * @brief Ex�cute l'action sp�cifique du formulaire de gr�ce pr�sidentielle.
 *
 * Cette fonction affiche un message indiquant que la gr�ce pr�sidentielle a �t�
 * accord�e � la cible sp�cifi�e dans `_target`. Le message inclut �galement le
 * logo ou l'identifiant `_logoLog`.
 *
 * @note Cette fonction ne v�rifie pas si l'ex�cution est autoris�e, cette v�rification
 * doit �tre effectu�e en amont via `Form::Execute()`.
 */
void PresidentialPardonForm::Execut() const
{
	std::cout << GREEN << LOGOPRE << RESET << "La grace presidentiel a ete accorder a " << CYAN << this->_target << RESET << std::endl;
}
