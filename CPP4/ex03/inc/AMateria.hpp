/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phkevin <phkevin@42luxembourg.lu>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 09:40:10 by phkevin           #+#    #+#             */
/*   Updated: 2025/03/21 09:40:10 by phkevin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include "../inc/Param.hpp"
#include "../inc/ICharacter.hpp"

class ICharacter;

class AMateria
{
	protected:
		std::string _types;


	public:
		//==============================
		// CONSTRUCTEUR
		//==============================
		AMateria(std::string const &type);
		AMateria(AMateria const &obj);
		AMateria& operator=(AMateria const &obj);
		virtual ~AMateria();

		//==============================
		// FONCTION
		//==============================
		std::string const& getType() const; //Returns the materia type
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter &target);
};
#endif // AMATERIA_HPP