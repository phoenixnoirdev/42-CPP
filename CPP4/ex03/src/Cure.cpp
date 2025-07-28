/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phkevin <phkevin@42luxembourg.lu>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 09:39:24 by phkevin           #+#    #+#             */
/*   Updated: 2025/03/21 09:39:24 by phkevin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Cure.hpp"

//=================
//Constructeur
//=================

/**
 * @brief Constructeur par d�faut de Cure.
 *
 * Ce constructeur initialise l'objet Cure en appelant le constructeur de la
 * classe de base AMateria avec le type "cure". Il affiche �galement un message
 * d'initialisation selon la langue choisie (fran�ais ou anglais).
 */
Cure::Cure() : AMateria("cure")
{
	std::string message = (LANG == LANG_FR) ? FRCONST : ENGCONST;
	std::cout << GREEN << "Cure" << RESET << message << std::endl;
}

/**
 * @brief Constructeur de copie de Cure.
 *
 * Ce constructeur cr�e une nouvelle instance de Cure en copiant les donn�es
 * de l'objet pass� en param�tre. Il appelle le constructeur de copie de la
 * classe de base AMateria et effectue l'op�ration d'assignation de l'objet.
 * Un message d'initialisation est ensuite affich� selon la langue choisie.
 *
 * @param obj L'objet Cure � copier.
 */
Cure::Cure(const Cure &obj) : AMateria(obj)
{
	*this = obj;

	std::string message = (LANG == LANG_FR) ? FRCPYCONST : ENGCPYCONST;
	std::cout << GREEN << "Cure" << RESET << message << std::endl;
}

/**
 * @brief Surcharge de l'op�rateur d'assignation pour Cure.
 *
 * Cette m�thode permet d'assigner les valeurs de l'objet `obj` � l'objet
 * courant. Si l'objet � affecter n'est pas le m�me que l'objet courant,
 * elle effectue l'assignation et affiche un message correspondant � la langue
 * choisie.
 *
 * @param obj L'objet Cure � assigner.
 *
 * @return L'objet courant apr�s l'assignation.
 */
Cure& Cure::operator=(const Cure& obj)
{
	if (this != &obj)
		*this = obj;

	std::string message = (LANG == LANG_FR) ? FROPCONST : ENGOPCONST;
	std::cout << GREEN << "Cure" << RESET << message << std::endl;

	return *this;
}

/**
 * @brief Destructeur de la classe Cure.
 *
 * Ce destructeur est appel� lors de la destruction d'un objet de type Cure.
 * Il affiche un message indiquant que le destructeur a �t� appel�, selon la langue d�finie.
 */
Cure::~Cure()
{
	std::string message = (LANG == LANG_FR) ? FRDESCONST : ENGDESCONST;
	std::cout << GREEN << "Cure" << RESET << message << std::endl;
}

//===============
//Fonctions
//===============

/**
 * @brief Utilise la comp�tence "Cure" sur une cible.
 *
 * Cette m�thode affiche un message indiquant que l'effet de soin a �t� appliqu�
 * � la cible sp�cifi�e, en affichant le nom de la cible dans le message.
 *
 * @param target La cible sur laquelle l'effet de soin sera appliqu�.
 */
void Cure::use(ICharacter& target)
{
	std::cout << GREEN << "Cure " << RESET << " * heal " << target.getName() << "'s wounds *" << std::endl;
}

/**
 * @brief Cr�e une copie de l'objet actuel "Cure".
 *
 * Cette m�thode cr�e une nouvelle instance de l'objet "Cure" en utilisant
 * le constructeur par d�faut et la retourne sous forme de pointeur vers
 * un objet AMateria.
 *
 * @return Un pointeur vers une nouvelle instance de "Cure".
 */
AMateria* Cure::clone() const
{
	Cure *clone = new Cure;

	return clone;
}
