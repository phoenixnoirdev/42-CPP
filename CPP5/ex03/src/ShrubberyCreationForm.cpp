/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phkevin <phkevin@42luxembourg.lu>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 12:07:08 by phkevin           #+#    #+#             */
/*   Updated: 2025/03/28 12:07:08 by phkevin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

//==============================
// CONSTRUCTEUR
//==============================

/**
 * @brief Constructeur par d�faut pour la classe ShrubberyCreationForm.
 *
 * Ce constructeur initialise un objet ShrubberyCreationForm avec un nom pr�d�fini ("Shrubbery"),
 * un grade de signature (145) et un grade d'ex�cution (137). Il initialise �galement l'attribut
 * _target avec une cha�ne vide (""). Un message de d�bogage est affich� lors de l'appel du constructeur.
 */
ShrubberyCreationForm::ShrubberyCreationForm() : Form("Shrubbery", 145, 137), _target("")
{
	std::cout << GREEN << LOGOSHRUB << RESET << "Default constructor called" << std::endl;
}

/**
 * @brief Constructeur par d�faut pour la classe ShrubberyCreationForm.
 *
 * Ce constructeur initialise un objet ShrubberyCreationForm avec un nom pr�d�fini ("Shrubbery"),
 * un grade de signature (145) et un grade d'ex�cution (137). Il initialise �galement l'attribut
 * _target avec la valeur fournie. Un message de d�bogage est affich� lors de l'appel du constructeur.
 *
 * @param target Le nom de la cible pour la cr�ation du shrubbery.
 */
ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : Form("Shrubbery", 145, 137), _target(target)
{
	std::cout << GREEN << LOGOSHRUB << RESET << "Default constructor called" << std::endl;
}

/**
 * @brief Constructeur de copie pour la classe ShrubberyCreationForm.
 *
 * Ce constructeur permet de cr�er une nouvelle instance de ShrubberyCreationForm
 * en copiant les attributs d'un autre objet ShrubberyCreationForm. Les donn�es de l'objet source
 * sont transf�r�es vers le nouvel objet. Ce constructeur affiche �galement un message de d�bogage.
 *
 * @param obj L'objet ShrubberyCreationForm � copier.
 */
ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm& obj) : Form(obj.GetName(), obj.GetGradeSigne(), obj.GetGradeExec()), _target(obj._target)
{
	std::cout << GREEN << LOGOSHRUB << RESET << "Copy constructor called" << std::endl;
}

/**
 * @brief Surcharge de l'op�rateur d'affectation pour la classe ShrubberyCreationForm.
 *
 * Cette m�thode permet d'affecter un objet ShrubberyCreationForm � un autre. Si l'objet source
 * et l'objet cible sont diff�rents, il effectue une copie de l'objet source dans l'objet cible.
 * Cette op�ration affiche un message pour indiquer que l'op�rateur d'affectation a �t� appel�.
 *
 * @param obj L'objet ShrubberyCreationForm � affecter � l'objet courant.
 *
 * @return L'objet actuel apr�s l'affectation.
 */
ShrubberyCreationForm& ShrubberyCreationForm::operator=(ShrubberyCreationForm& obj)
{
	if (this != &obj)
		*this = obj;

	std::cout << GREEN << LOGOSHRUB << RESET << "Operator constructor called" << std::endl;

	return *this;
}

/**
 * @brief Destructeur pour la classe ShrubberyCreationForm.
 *
 * Ce destructeur est appel� lorsque l'objet ShrubberyCreationForm est d�truit. Il affiche
 * un message de d�bogage pour indiquer que le destructeur a �t� invoqu�.
 *
 * @note Ce destructeur ne lib�re pas de ressources dynamiques sp�cifiques, car il est
 * principalement utilis� pour le suivi des objets.
 */
ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << GREEN << LOGOSHRUB << RESET << "Destructor called" << std::endl;
}

//==============================
// FONCTION
//==============================

/**
 * @brief Ex�cute la cr�ation d'un arbuste en g�n�rant un fichier.
 *
 * Cette m�thode g�n�re un fichier contenant un dessin ASCII repr�sentant un arbuste.
 * Le fichier est nomm� en fonction de la cible du formulaire et a l'extension `_shrubbery`.
 * Le contenu du fichier est un arbre ASCII.
 */
void ShrubberyCreationForm::Execut() const
{
	std::ofstream output((this->_target + "_shrubbery").c_str());
	output << "        ccee88oo\n"
		<< "     C8O8O8Q8PoOb o8oo\n"
		<< "  dOB69QO8PdUOpugoO9bD\n"
		<< " CgggbU8OU qOp qOdoUOdcb\n"
		<< "    6OuU  /p u gcoUodpP\n"
		<< "      \\\\//  /douUP\n"
		<< "        \\\\////\n"
		<< "         |||/\\\n"
		<< "         |||\\/\n"
		<< "         |||||\n"
		<< "   .....//||||\\....\n";
	output.close();
}