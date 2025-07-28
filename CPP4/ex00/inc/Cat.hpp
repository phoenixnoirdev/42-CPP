/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phkevin <phkevin@42luxembourg.lu>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 11:47:58 by phkevin           #+#    #+#             */
/*   Updated: 2025/04/15 15:58:31 by phkevin          ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "../inc/Animal.hpp"

class Cat : public Animal
{
	public:
		Cat();
		Cat(std::string str);
		Cat(const Cat& obj);
		Cat& operator=(const Cat& other);
		virtual ~Cat();
		virtual void makeSound() const;
};
#endif // CAT_HPP