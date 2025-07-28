/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phkevin <phkevin@42luxembourg.lu>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 09:40:02 by phkevin           #+#    #+#             */
/*   Updated: 2025/03/21 09:40:02 by phkevin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "../inc/Param.hpp"
#include "../inc/IMateriaSource.hpp"

#define SLOT 4

class IMateriaSource;

class MateriaSource : public IMateriaSource
{
	private:
		AMateria *_learn[SLOT];

	public:
		//==============================
		// CONSTRUCTEUR
		//==============================
		MateriaSource();
		MateriaSource(const MateriaSource &other);
		MateriaSource& operator=(const MateriaSource &other);
		virtual ~MateriaSource();

		//==============================
		// FONCTION
		//==============================
		virtual void learnMateria(AMateria *obj);
		virtual AMateria* createMateria(std::string const& type);
};
#endif // MATERIASOURCE_HPP