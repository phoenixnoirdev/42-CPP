/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phkevin <phkevin@42luxembourg.lu>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 09:40:06 by phkevin           #+#    #+#             */
/*   Updated: 2025/03/21 09:40:06 by phkevin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
#define ICE_HPP

#include "../inc/Param.hpp"
#include "../inc/AMateria.hpp"

class Ice : public AMateria
{
	public:
		//==============================
		// CONSTRUCTEUR
		//==============================
		Ice();
		Ice(const Ice& obj);
		Ice& operator=(const Ice& obj);
		virtual ~Ice();

		//==============================
		// FONCTION
		//==============================
		virtual AMateria* clone() const;
		virtual void use(ICharacter& target);
};
#endif // ICE_HPP