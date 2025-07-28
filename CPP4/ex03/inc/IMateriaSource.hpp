/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phkevin <phkevin@42luxembourg.lu>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 09:40:03 by phkevin           #+#    #+#             */
/*   Updated: 2025/03/21 09:40:03 by phkevin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMATERIASOURCE_HPP
#define IMATERIASOURCE_HPP

#include "../inc/Param.hpp"
#include "../inc/AMateria.hpp"

class AMateria;

class IMateriaSource
{
	public:
		//==============================
		// CONSTRUCTEUR
		//==============================
		virtual ~IMateriaSource() {}

		//==============================
		// FONCTION
		//==============================
		virtual void learnMateria(AMateria*) = 0;
		virtual AMateria* createMateria(std::string const& type) = 0;
};
#endif // IMATERIASOURCE_HPP