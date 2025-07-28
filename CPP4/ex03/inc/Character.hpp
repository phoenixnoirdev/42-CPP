/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phkevin <phkevin@42luxembourg.lu>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 09:40:09 by phkevin           #+#    #+#             */
/*   Updated: 2025/03/21 09:40:09 by phkevin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "../inc/Param.hpp"
#include "../inc/ICharacter.hpp"
#include "../inc/AMateria.hpp"

#define SLOT 4
#define TRASHSIZE 1000

class Character : public ICharacter
{
	protected:
		std::string _name;
		int _idLaTras;
		AMateria* _inv[SLOT];
		AMateria* _floor[TRASHSIZE];

	public:
		//==============================
		// CONSTRUCTEUR
		//==============================
		Character(std::string const& name);
		Character(Character const& obj);
		Character& operator=(Character const& obj);
		virtual ~Character();

		//==============================
		// FONCTION
		//==============================
		virtual void equip(AMateria* obj);
		virtual std::string const& getName() const;
		virtual void unequip(int idx);
		virtual void use(int idx, ICharacter &target);
		virtual void getUnequip();
};
#endif //CHARACTER_HPP
