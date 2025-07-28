/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phkevin <phkevin@42luxembourg.lu>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 09:40:07 by phkevin           #+#    #+#             */
/*   Updated: 2025/03/21 09:40:07 by phkevin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
#define CURE_HPP

#include "../inc/Param.hpp"
#include "../inc/AMateria.hpp"

class Cure : public AMateria
{
	public:
		//==============================
		// CONSTRUCTEUR
		//==============================
		Cure();
		Cure(const Cure &obj);
		Cure& operator=(const Cure& obj);
		virtual ~Cure();

		//==============================
		// FONCTION
		//==============================
		virtual AMateria* clone() const;
		virtual void use(ICharacter& target);
};
#endif // CURE_HPP