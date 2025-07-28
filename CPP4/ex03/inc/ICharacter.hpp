/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phkevin <phkevin@42luxembourg.lu>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 09:40:05 by phkevin           #+#    #+#             */
/*   Updated: 2025/03/21 09:40:05 by phkevin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICHARACTER_HPP
#define ICHARACTER_HPP

#include "../inc/Param.hpp"
#include "../inc/AMateria.hpp"

class AMateria;

class ICharacter
{
	public:
		//==============================
		// CONSTRUCTEUR
		//==============================
		virtual ~ICharacter() {}

		//==============================
		// FONCTION
		//==============================
		virtual std::string const& getName() const = 0;
		virtual void equip(AMateria* m) = 0;
		virtual void unequip(int idx) = 0;
		virtual void use(int idx, ICharacter &target) = 0;

};
#endif // ICHARACTER_HPP