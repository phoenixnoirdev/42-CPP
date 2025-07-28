/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phkevin <phkevin@42luxembourg.lu>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 09:39:05 by phkevin           #+#    #+#             */
/*   Updated: 2025/03/21 09:39:05 by phkevin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/AMateria.hpp"


//=================
//Constructeur
//=================

/**
 * @brief Constructeur de la classe AMateria.
 *
 * Initialise une mati�re avec un type donn� et affiche un message de
 * confirmation selon la langue d�finie (FR ou ENG).
 *
 * @param type Type de la mati�re � initialiser.
 */
AMateria::AMateria(std::string const & type)
{
	this->_types = type;

	std::string message = (LANG == LANG_FR) ? FRCONST : ENGCONST;
	std::cout << GREEN << "AMateria" << RESET << message << std::endl;
}

/**
 * @brief Constructeur par copie de la classe AMateria.
 *
 * Initialise une nouvelle instance de AMateria en copiant le type de
 * l'objet source et affiche un message selon la langue d�finie (FR ou ENG).
 *
 * @param obj Objet AMateria � copier.
 */
AMateria::AMateria(AMateria const& obj)
{
	this->_types = obj.getType();

	std::string message = (LANG == LANG_FR) ? FRCPYCONST : ENGCPYCONST;
	std::cout << GREEN << "AMateria" << RESET << message << std::endl;
}

/**
 * @brief Op�rateur d'affectation pour la classe AMateria.
 *
 * Copie le type de l'objet source dans l'instance actuelle,
 * si ce n'est pas le m�me objet, puis affiche un message en fonction
 * de la langue d�finie (FR ou ENG).
 *
 * @param obj Objet AMateria � copier.
 * @return R�f�rence vers l'instance actuelle apr�s affectation.
 */
AMateria& AMateria::operator=(AMateria const& obj)
{
	if (this != &obj)
		this->_types = obj.getType();

	std::string message = (LANG == LANG_FR) ? FROPCONST : ENGOPCONST;
	std::cout << GREEN << "AMateria" << RESET << message << std::endl;

	return *this;
}

/**
 * @brief Destructeur de la classe AMateria.
 *
 * Affiche un message indiquant la destruction de l'objet,
 * en fonction de la langue d�finie (FR ou ENG).
 */
AMateria::~AMateria()
{
	std::string message = (LANG == LANG_FR) ? FRDESCONST : ENGDESCONST;
	std::cout << GREEN << "AMateria" << RESET << message << std::endl;
}

//=================
//Fonction
//=================

/**
 * @brief Retourne le type de la mati�re.
 *
 * @return Une r�f�rence constante vers la cha�ne de caract�res
 * repr�sentant le type de la mati�re.
 */
std::string const& AMateria::getType() const
{
	return this->_types;
}

/**
 * @brief Utilise la mati�re sur une cible sp�cifique.
 *
 * Cette fonction affiche un message indiquant l'utilisation de
 * la mati�re sur le personnage cible.
 *
 * @param target R�f�rence vers l'objet ICharacter repr�sentant la cible.
 */
void AMateria::use(ICharacter& target)
{
	std::string message = (LANG == LANG_FR) ? FRUSETARGET : ENGUSETARGET;
	std::cout << GREEN << "AMateria" << RESET << message << GREEN << target.getName() << RESET << std::endl;
}
