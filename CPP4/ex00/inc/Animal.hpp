/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phkevin <phkevin@42luxembourg.lu>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 11:47:56 by phkevin           #+#    #+#             */
/*   Updated: 2025/03/16 10:46:43 by phkevin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>
#include <iostream>

#define RESET   "\033[0;39m"
#define RED     "\033[0;31m"
#define GREEN   "\033[0;92m"
#define YELLOW  "\033[0;93m"
#define BLUE    "\033[0;34m"
#define MAGENTA "\033[0;35m"
#define CYAN    "\033[0;36m"
#define WHITE   "\033[0;37m"

class Animal
{
	protected:
		std::string type;
		void setType(std::string str);
	

	public:
		Animal();
		Animal(std::string str);
		Animal(const Animal& obj);
		Animal& operator=(const Animal& other);
		virtual ~Animal();
		virtual std::string getType() const;
		virtual void makeSound() const;
};
#endif // ANIMAL_HPP