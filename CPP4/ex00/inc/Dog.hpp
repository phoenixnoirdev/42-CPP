/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phkevin <phkevin@42luxembourg.lu>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 11:47:54 by phkevin           #+#    #+#             */
/*   Updated: 2025/04/15 15:58:34 by phkevin          ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "../inc/Animal.hpp"

class Dog : public Animal
{
	public:
		Dog();
		Dog(std::string str);
		Dog(const Dog& obj);
		Dog& operator=(const Dog& other);
		virtual ~Dog();
		virtual void makeSound() const;
};
#endif // DOG_HPP