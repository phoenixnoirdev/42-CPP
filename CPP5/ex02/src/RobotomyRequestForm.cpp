/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phkevin <phkevin@42luxembourg.lu>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 11:09:18 by phkevin           #+#    #+#             */
/*   Updated: 2025/03/27 11:09:18 by phkevin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/RobotomyRequestForm.hpp"

//==============================
// CONSTRUCTEUR
//==============================

/**
 * @brief Constructeur par d�faut pour la classe RobotomyRequestForm.
 *
 * Initialise un formulaire de demande de robotisation avec un nom pr�d�fini "Robotomy",
 * un grade de signature de 72 et un grade d'ex�cution de 45. Le g�n�rateur de nombres
 * al�atoires est initialis� pour simuler le processus de robotisation.
 *
 * Ce constructeur ne prend aucun param�tre et est utilis� pour cr�er une instance de
 * RobotomyRequestForm sans sp�cifier de cible.
 */
RobotomyRequestForm::RobotomyRequestForm() : Form("Robotomy", 72, 45)
{
	srand(time(0));

	std::cout << GREEN << LOGOROB << RESET << "Default constructor called" << std::endl;
}

/**
 * @brief Constructeur par d�faut pour la classe RobotomyRequestForm.
 *
 * Initialise un formulaire de demande de robotisation avec un nom pr�d�fini "Robotomy",
 * un grade de signature de 72 et un grade d'ex�cution de 45. Le g�n�rateur de nombres
 * al�atoires est initialis� pour simuler le processus de robotisation.
 *
 * @param target La cible de la demande de robotisation.
 */
RobotomyRequestForm::RobotomyRequestForm(std::string target) : Form("Robotomy", 72, 45), _target(target)
{
	srand(time(0));

	std::cout << GREEN << LOGOROB << RESET << "Default constructor called" << std::endl;
}

/**
 * @brief Constructeur de copie pour la classe RobotomyRequestForm.
 *
 * Copie les donn�es de l'objet source dans l'objet actuel, y compris le nom, les
 * grades de signature et d'ex�cution en appelant le constructeur de la classe de base Form.
 * Ensuite, initialise le g�n�rateur de nombres al�atoires pour simuler le processus de robotisation.
 *
 * @param obj L'objet RobotomyRequestForm � copier.
 */
RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm& obj) : Form(obj.GetName(), obj.GetGradeSigne(), obj.GetGradeExec()), _target(obj._target)
{
	srand(time(0));

	std::cout << GREEN << LOGOROB << RESET << "Copy constructor called" << std::endl;
}

/**
 * @brief Surcharge de l'op�rateur d'affectation pour la classe RobotomyRequestForm.
 *
 * V�rifie si l'objet � affecter n'est pas lui-m�me, puis effectue une affectation
 * en copiant les valeurs de l'objet source. Ensuite, initialise le g�n�rateur de nombres
 * al�atoires pour simuler le processus de robotisation.
 *
 * @param obj L'objet RobotomyRequestForm � affecter.
 * @return RobotomyRequestForm& L'objet actuel apr�s l'affectation.
 */
RobotomyRequestForm& RobotomyRequestForm::operator=(RobotomyRequestForm& obj)
{
	if (this != &obj)
		*this = obj;

	srand(time(0));

	std::cout << GREEN << LOGOROB << RESET << "Operator constructor called" << std::endl;

	return *this;
}

/**
 * @brief Destructeur de la classe RobotomyRequestForm.
 *
 * Affiche un message lors de la destruction de l'objet RobotomyRequestForm.
 */
RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << GREEN << LOGOROB << RESET << "Destructor called" << std::endl;
}



//==============================
// FONCTION
//==============================

/**
 * @brief Effectue une tentative de robotisation sur la cible.
 *
 * Affiche un message de tentative de robotisation suivi du bruit caract�ristique.
 * Ensuite, une chance al�atoire d�termine si la robotisation r�ussit ou �choue.
 * Si le r�sultat est positif, un message de succ�s est affich�. Si le r�sultat est
 * n�gatif, un message d'�chec est affich�.
 */
void RobotomyRequestForm::Execut() const
{
	std::cout << GREEN << LOGOROB << RESET << "Tentative de robotisation de " << GREEN << this->_target << RESET << std::endl;
	std::cout << GREEN << LOGOROB << RESET << "BZZZ brrrr BZEEEEE rrrre" << std::endl;

	if (rand() % 2) {
		std::cout << GREEN << LOGOROB << RESET << "La robotisation sur " << GREEN << this->_target << RESET << " est un " << CYAN << " SUCCES " << RESET << std::endl;
	}
	else {
		std::cout << GREEN << LOGOROB << RESET << "La robotisation sur " << GREEN << this->_target << RESET << " est un " << RED << " ECHEC " << RESET << std::endl;
	}
}