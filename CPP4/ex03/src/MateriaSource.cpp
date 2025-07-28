/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phkevin <phkevin@42luxembourg.lu>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 09:39:37 by phkevin           #+#    #+#             */
/*   Updated: 2025/03/21 09:39:37 by phkevin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/MateriaSource.hpp"

//==============================
// Consturcteur
//==============================

/**
 * @brief Constructeur par d�faut de la classe MateriaSource.
 *
 * Ce constructeur initialise la source de mati�res en d�finissant tous les
 * emplacements de mati�res comme NULL. Il affiche �galement un message
 * indiquant la cr�ation de la source de mati�res.
 */
MateriaSource::MateriaSource()
{
	for (int i = 0; i < SLOT; i++)
		_learn[i] = NULL;

	std::string message = (LANG == LANG_FR) ? FRCONST : ENGCONST;
	std::cout << GREEN << "Materia source" << RESET << message << std::endl;
}

/**
 * @brief Constructeur de copie de la classe MateriaSource.
 *
 * Ce constructeur effectue une copie profonde de l'objet pass� en param�tre.
 * Il copie les mati�res apprises de l'autre source de mati�res et les
 * initialise tout en supprimant les mati�res pr�c�demment apprises.
 * Un message est �galement affich� lors de la cr�ation de la source de mati�res.
 *
 * @param obj L'objet MateriaSource � copier.
 */
MateriaSource::MateriaSource(const MateriaSource &obj)
{
	*this = obj;
	for (int i = 0; i < SLOT; i++)
	{
		if (this->_learn[i])
			delete this->_learn[i];
		this->_learn[i] = obj._learn[i];
	}

	std::string message = (LANG == LANG_FR) ? FRCONST : ENGCONST;
	std::cout << GREEN << "Materia source" << RESET << message << std::endl;
}

/**
 * @brief Surcharge de l'op�rateur d'affectation pour la classe MateriaSource.
 *
 * Cette m�thode effectue une copie profonde de l'objet MateriaSource pass� en param�tre.
 * Elle veille � lib�rer la m�moire des mati�res pr�c�demment apprises avant de copier
 * celles de l'objet source. Un message est affich� lors de l'op�ration d'affectation.
 *
 * @param obj L'objet MateriaSource � copier.
 * @return Une r�f�rence vers l'objet MateriaSource actuel.
 */
MateriaSource& MateriaSource::operator=(const MateriaSource &obj)
{
	if (this != &obj)
	{
		*this = obj;
		for (int i = 0; i < SLOT; i++)
		{
			if (this->_learn[i])
				delete this->_learn[i];
			this->_learn[i] = obj._learn[i];
		}
			
	}

	std::string message = (LANG == LANG_FR) ? FROPCONST : ENGOPCONST;
	std::cout << GREEN << "Materia source" << RESET << message << std::endl;

	return *this;
}

/**
 * @brief Destructeur pour la classe MateriaSource.
 *
 * Cette m�thode lib�re la m�moire allou�e pour les mati�res apprises dans la source.
 * Un message est affich� lors de la destruction de l'objet.
 */
MateriaSource::~MateriaSource()
{
	for (int i = 0; i < SLOT; i++)
		if (_learn[i])
			delete _learn[i];

	std::string message = (LANG == LANG_FR) ? FRDESCONST : ENGDESCONST;
	std::cout << GREEN << "Materia source" << RESET << message << std::endl;
}

//==============================
// Fonction
//==============================

/**
 * @brief Apprend une nouvelle mati�re � la source de mati�res.
 *
 * Cette m�thode ajoute une nouvelle mati�re � la source si une place est
 * disponible. Si la source est pleine, un message est affich� pour le
 * signaler.
 *
 * @param obj Un pointeur vers l'objet AMateria � apprendre.
 */
void MateriaSource::learnMateria(AMateria *obj)
{
	for (int i = 0; i < SLOT; i++)
	{
		if (!this->_learn[i])
		{
			this->_learn[i] = obj;

			if (LANG == LANG_FR)
				std::cout << GREEN << "Materia source" << RESET << FRMATSRC0 << GREEN << obj->getType() << RESET << FRMATSRC1 << std::endl;
			else
				std::cout << GREEN << "Materia source" << RESET << ENGMATSRC0 << GREEN << obj->getType() << RESET << ENGMATSRC1 << std::endl;

			return ;
		}

		if (i == SLOT - 1)
		{
			std::string message = (LANG == LANG_FR) ? FRMATSRC2 : ENGMATSRC2;
			std::cout << GREEN << "Materia source" << RESET << message << std::endl;

			delete obj;

			return;
		}
	}
}

/**
 * @brief Cr�e une nouvelle mati�re � partir du type sp�cifi�.
 *
 * Cette m�thode parcourt les mati�res apprises et retourne une copie
 * d'une mati�re ayant le type sp�cifi�. Si aucune mati�re de ce type n'est
 * trouv�e, un message est affich� et la m�thode retourne un pointeur nul.
 *
 * @param type Le type de la mati�re � cr�er.
 *
 * @return Un pointeur vers une nouvelle mati�re clon�e ou un pointeur nul
 *         si le type n'a pas �t� trouv�.
 */
AMateria* MateriaSource::createMateria(std::string const& type)
{
	for (int i = 0; i < SLOT; i++)
	{
		if (this->_learn[i] && this->_learn[i]->getType() == type)
			return this->_learn[i]->clone();

		if (i == SLOT - 1)
		{
			std::string message = (LANG == LANG_FR) ? FRMATSRC3 : ENGMATSRC3;
			std::cout << GREEN << "Materia source " << RESET << message << std::endl;

			return 0;
		}
	}

	return 0;
}