/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phkevin <phkevin@42luxembourg.lu>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 09:39:27 by phkevin           #+#    #+#             */
/*   Updated: 2025/03/21 09:39:27 by phkevin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Ice.hpp"

//==============================
// Consturcteur
//==============================

/**
 * @brief Constructeur par d�faut de la classe "Ice".
 *
 * Ce constructeur initialise une instance de la classe "Ice" en utilisant
 * le constructeur de la classe de base AMateria avec le type "ice".
 * Il affiche �galement un message dans la langue d�finie (fran�ais ou anglais)
 * pour indiquer la cr�ation de l'objet.
 */
Ice::Ice() : AMateria("ice")
{
	std::string message = (LANG == LANG_FR) ? FRCONST : ENGCONST;
	std::cout << GREEN << "Ice" << RESET << message << std::endl;
}

/**
 * @brief Constructeur de copie de la classe "Ice".
 *
 * Ce constructeur initialise une instance de la classe "Ice" en copiant
 * les donn�es de l'objet pass� en argument. Il appelle le constructeur
 * de copie de la classe de base AMateria pour copier le type, puis effectue
 * la copie des autres attributs si n�cessaire.
 * Un message est affich� pour indiquer la cr�ation d'une copie de l'objet
 * dans la langue d�finie (fran�ais ou anglais).
 */
Ice::Ice(const Ice& obj) : AMateria(obj)
{
	*this = obj;

	std::string message = (LANG == LANG_FR) ? FRCPYCONST : ENGCPYCONST;
	std::cout << GREEN << "Ice" << RESET << message << std::endl;
}

/**
 * @brief Assigne un objet Ice � l'objet actuel.
 *
 * Si l'objet � assigner n'est pas le m�me que l'objet actuel,
 * cette m�thode copie les valeurs de l'objet source vers l'objet cible.
 * Elle affiche �galement un message en fonction de la langue choisie.
 *
 * @param obj L'objet Ice � assigner.
 * @return Ice& R�f�rence sur l'objet courant apr�s l'assignation.
 */
Ice& Ice::operator=(const Ice& obj)
{
	if (this != &obj)
		*this = obj;

	std::string message = (LANG == LANG_FR) ? FROPCONST : ENGOPCONST;
	std::cout << GREEN << "Ice" << RESET << message << std::endl;

	return *this;
}

/**
 * @brief D�truit l'objet Ice.
 *
 * Cette m�thode est appel�e lors de la destruction de l'objet Ice.
 * Elle affiche un message en fonction de la langue choisie pour indiquer
 * que l'objet Ice est d�truit.
 */
Ice::~Ice()
{
	std::string message = (LANG == LANG_FR) ? FRDESCONST : ENGDESCONST;
	std::cout << GREEN << "Ice" << RESET << message << std::endl;
}

//==============================
// Fonction
//==============================

/**
 * @brief Utilise l'objet Ice sur une cible.
 *
 * Cette m�thode permet d'utiliser l'objet Ice sur un personnage cible.
 * Elle affiche un message indiquant que l'objet Ice lance un rayon de glace
 * sur la cible sp�cifi�e.
 *
 * @param target La cible sur laquelle l'objet Ice est utilis�.
 */
void Ice::use(ICharacter& target)
{
	std::cout << GREEN << "Ice " << RESET << " * shoots an ice bolt at " << target.getName() << " *" << std::endl;
}

/**
 * @brief Cr�e une copie de l'objet Ice.
 *
 * Cette m�thode retourne une nouvelle instance de l'objet Ice,
 * en clonant l'objet actuel.
 *
 * @return Un pointeur vers la nouvelle instance de l'objet Ice.
 */
AMateria* Ice:: clone() const
{
	Ice *clone = new Ice;

	return clone;
}