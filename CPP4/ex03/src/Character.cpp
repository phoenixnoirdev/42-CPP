/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phkevin <phkevin@42luxembourg.lu>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 09:39:18 by phkevin           #+#    #+#             */
/*   Updated: 2025/03/21 09:39:18 by phkevin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Character.hpp"


//===============
//Constructeur
//===============

/**
 * @brief Constructeur de la classe Character.
 *
 * Initialise un personnage avec un nom donn� et un inventaire vide.
 *
 * @param name Nom du personnage.
 */
Character::Character(std::string const &name)
{
	this->_name = name;
	this->_idLaTras = 0;

	for (int i = 0; i < SLOT; i++)
		this->_inv[i] = NULL;

	for (int i = 0; i < TRASHSIZE; i++)
		this->_floor[i] = NULL;

	std::string message = (LANG == LANG_FR) ? FRCONST : ENGCONST;
	std::cout << GREEN << "Character" << RESET << message << std::endl;
}

/**
 * @brief Constructeur de copie de la classe Character.
 *
 * Copie le nom du personnage et duplique les objets de son inventaire.
 *
 * @param obj R�f�rence vers le Character � copier.
 */
Character::Character(Character const& obj)
{
	this->_name = obj._name;
	this->_idLaTras = obj._idLaTras;

	for (int i = 0; i < SLOT; i++)
	{
		if (obj._inv[i])
			this->_inv[i] = obj._inv[i]->clone();
		else
			this->_inv[i] = NULL;
	}

	for (int i = 0; i < SLOT; i++)
	{
		if (obj._inv[i])
		{
			delete this->_inv[i];
			this->_inv[i] = NULL;
		}
	}

	for (int i = 0; i < TRASHSIZE; i++)
	{
		if (obj._floor[i])
			this->_floor[i] = obj._floor[i]->clone();
		else
			this->_floor[i] = NULL;
	}

	for (int i = 0; i < TRASHSIZE; i++)
	{
		if (obj._floor[i])
		{
			delete this->_floor[i];
			this->_floor[i] = NULL;
		}
	}

	std::string message = (LANG == LANG_FR) ? FRCPYCONST : ENGCPYCONST;
	std::cout << GREEN << "Character" << RESET << message << std::endl;
}

/**
 * @brief Surcharge de l'op�rateur d'affectation pour la classe Character.
 *
 * Assure une copie profonde de l'inventaire du personnage.
 * Lib�re la m�moire des objets pr�c�dents avant d'en allouer de nouveaux.
 *
 * @param obj R�f�rence vers le Character � copier.
 * @return R�f�rence vers l'instance actuelle de Character.
 */
Character& Character::operator=(Character const& obj)
{
	if (this != &obj)
	{
		this->_name = obj._name;
		this->_idLaTras = obj._idLaTras;

		for (int i = 0; i < SLOT; i++)
		{
			delete this->_inv[i];
			this->_inv[i] = NULL;
		}

		for (int i = 0; i < SLOT; i++)
		{
			if (obj._inv[i])
				this->_inv[i] = obj._inv[i]->clone();
			else
				this->_inv[i] = NULL;
		}

		for (int i = 0; i < TRASHSIZE; i++)
		{
			if (obj._floor[i])
				this->_floor[i] = obj._floor[i]->clone();
			else
				this->_floor[i] = NULL;
		}

		for (int i = 0; i < TRASHSIZE; i++)
		{
			if (obj._floor[i])
			{
				delete this->_floor[i];
				this->_floor[i] = NULL;
			}
		}
	}

	std::string message = (LANG == LANG_FR) ? FROPCONST : ENGOPCONST;
	std::cout << GREEN << "Character" << RESET << message << std::endl;

	return *this;
}

/**
 * @brief Destructeur de la classe Character.
 *
 * Lib�re la m�moire allou�e pour l'inventaire et la liste des objets
 * d�s�quip�s afin d'�viter toute fuite m�moire.
 */
Character::~Character()
{
	for (int i = 0; i < SLOT; i++)
	{
		if (this->_inv[i])
			delete this->_inv[i];
	}

	for (int i = 0; i < TRASHSIZE; i++)
	{
		if (this->_floor[i])
			delete this->_floor[i];
	}
		
	std::string message = (LANG == LANG_FR) ? FRDESCONST : ENGDESCONST;
	std::cout << GREEN << "Character" << RESET << message << std::endl;
}

//===============
//Fonction
//===============

/**
 * @brief Permet d'�quiper un objet AMateria � un personnage.
 *
 * Cette m�thode tente d'ajouter l'objet `obj` � l'inventaire du personnage. Si l'objet
 * est d�j� allou� et que l'inventaire est plein, un message d'erreur est affich�.
 *
 * Si l'objet est correctement �quip�, un message de confirmation est affich�,
 * indiquant dans quel emplacement l'objet a �t� plac� et son type.
 *
 * @param obj L'objet AMateria � �quiper.
 */
void Character::equip(AMateria* obj)
{
	if (!obj)
	{
		std::string message = (LANG == LANG_FR) ? FRINVAMAT : ENGINVAMAT;
		std::cout << GREEN << "Character" << RESET << message << std::endl;

		return;
	}

	for (int i = 0; i < SLOT; i++)
	{
		if (!this->_inv[i])
		{
			this->_inv[i] = obj;

			if (LANG == LANG_FR)
				std::cout << GREEN << "Character" << RESET << FRMATSLOT0 << GREEN << i << RESET << FRMATSLOT1 << GREEN << this->_name << RESET << FRMATSLOT2 << GREEN << obj->getType() << RESET << std::endl;
			else
				std::cout << GREEN << "Character" << RESET << ENGMATSLOT0 << GREEN << i << RESET << ENGMATSLOT1 << GREEN << this->_name << RESET << ENGMATSLOT2 << GREEN << obj->getType() << RESET << std::endl;

			return ;
		}
	}

	if (LANG == LANG_FR)
		std::cout << GREEN << "Character" << RESET << FRMATSLOT3 << GREEN << this->_name << RESET << FRMATSLOT4 << std::endl;
	else
		std::cout << GREEN << "Character" << RESET << ENGMATSLOT3 << GREEN << this->_name << RESET << ENGMATSLOT4 << std::endl;
	
	for (int i = 0; i < TRASHSIZE; i++)
	{
		if (this->_floor[i] == NULL)
		{
			this->_floor[i] = obj;
			break;
		}
	}

	return ;
}

/**
 * @brief D�s�quipe un objet AMateria de l'inventaire du personnage.
 *
 * Cette m�thode retire un objet AMateria de l'inventaire � l'emplacement sp�cifi� par
 * l'indice `idx`. Si l'indice est invalide ou si l'emplacement est vide, un message
 * d'erreur est affich�. Sinon, l'objet est ajout� � la liste `_floor` et retir�
 * de l'inventaire.
 *
 * @param idx L'indice de l'objet � d�s�quiper dans l'inventaire.
 */
void Character::unequip(int idx)
{
	if (idx < 0 || idx >= SLOT)
	{
		std::string message = (LANG == LANG_FR) ? FRMATSLOT5 : ENGMATSLOT5;
		std::cout << GREEN << "Character" << RESET << message << std::endl;

		return ;
	}

	if (!this->_inv[idx])
	{
		std::string message = (LANG == LANG_FR) ? FRMATSLOT6 : ENGMATSLOT6;
		std::cout << GREEN << "Character " << RESET << message << std::endl;

		return ;
	}

	bool confTra = false;
	for (int i = 0; i < TRASHSIZE; i++)
	{
		if (this->_floor[i] == NULL)
		{
			this->_floor[i] = this->_inv[idx];
			this->_idLaTras = i;
			this->_inv[idx] = NULL;
			confTra = true;
			break;
		}

		if (confTra == false)
		{
			std::string message = (LANG == LANG_FR) ? FRMATSLOT10 : ENGMATSLOT10;
			std::cout << GREEN << "Character " << RESET << message << std::endl;
			
			if (this->_idLaTras == TRASHSIZE)
				this->_idLaTras = 0;
			
			delete this->_floor[this->_idLaTras];
			this->_floor[this->_idLaTras] = this->_inv[idx];
			this->_inv[idx] = NULL;
		}
	}

	std::string message = (LANG == LANG_FR) ? FRMATSLOT7 : ENGMATSLOT7;
	std::cout << GREEN << "Character " << RESET << message << GREEN << idx << RESET << std::endl;

	return ;
}

/**
 * @brief Retourne le nom du personnage.
 *
 * Cette m�thode retourne une r�f�rence constante sur le nom du personnage, qui est une
 * cha�ne de caract�res repr�sentant l'identit� du personnage.
 *
 * @return Une r�f�rence constante sur le nom du personnage.
 */
std::string const& Character::getName() const
{
	return this->_name;
}

/**
 * @brief Utilise un objet de la liste d'inventaire du personnage sur une cible.
 *
 * Cette m�thode v�rifie si l'objet � l'indice donn� existe dans l'inventaire du
 * personnage. Si c'est le cas, elle appelle la m�thode `use` de l'objet pour
 * l'utiliser sur la cible sp�cifi�e. Si l'indice est invalide ou si l'objet � cet
 * indice n'est pas d�fini, un message d'erreur est affich�.
 *
 * @param idx L'indice de l'objet dans l'inventaire � utiliser.
 * @param target La cible sur laquelle l'objet sera utilis�.
 */
void Character::use(int idx, ICharacter &target)
{
	if (idx < 0 || idx >= SLOT)
	{
		std::string message = (LANG == LANG_FR) ? FRMATSLOT5 : ENGMATSLOT5;
		std::cout << GREEN << "Character" << RESET << message << std::endl;

		return ;
	}

	if (!this->_inv[idx])
	{
		std::string message = (LANG == LANG_FR) ? FRMATSLOT6 : ENGMATSLOT6;
		std::cout << GREEN << "Character " << RESET << message << std::endl;

		return ;
	}

	this->_inv[idx]->use(target);

	return ;
}

/**
 * @brief Affiche les objets d�s�quip�s du personnage.
 *
 * Cette m�thode parcourt la liste des objets qui ont �t� d�s�quip�s par le
 * personnage et affiche un message pour chaque objet, en indiquant son type et
 * le nom du personnage. Le message affich� est dans la langue choisie par
 * l'utilisateur (fran�ais ou anglais).
 */
void Character::getUnequip()
{
	for (int i = 0; i < TRASHSIZE; i++)
	{
		std::string message = (LANG == LANG_FR) ? FRMATSLOT8 : ENGMATSLOT8;
		std::string messageuser = (LANG == LANG_FR) ? FRMATSLOT9 : ENGMATSLOT9;
		std::cout << GREEN << "Character " << RESET << message << GREEN << this->_floor[i]->getType() << RESET << messageuser  << GREEN << this->getName() << RESET << std::endl;
	}
}