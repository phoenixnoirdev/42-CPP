/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phkevin <phkevin@42luxembourg.lu>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 11:47:29 by phkevin           #+#    #+#             */
/*   Updated: 2025/03/15 11:47:29 by phkevin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../inc/Cat.hpp"
#include "../inc/Dog.hpp"
#include "../inc/WrongCat.hpp"

/**
 * @brief Affiche plusieurs lignes vides dans la console.
 *
 * @param nb Nombre de lignes vides � afficher.
 */
void lBreak(int nb)
{
    for (int i = 0; i < nb; ++i)
        std::cout << std::endl;
}

/**
 * @brief Affiche un s�parateur format� avec un titre centr�.
 *
 * @param str Texte � afficher au centre du s�parateur.
 */
void separator(std::string str)
{
    lBreak(2);
    std::cout << YELLOW << "------------------------------------" << RESET << std::endl;
    std::cout << YELLOW << str << RESET << std::endl;
    std::cout << YELLOW << "------------------------------------" << RESET << std::endl;
    lBreak(2);
}

int main()
{
    separator("ANIMAL TEST");

    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    lBreak(1);

    std::cout << "I am a type animal: " << GREEN << meta->getType() << RESET << std::endl;
    std::cout << "I am a type animal: " << GREEN << i->getType() << RESET << std::endl;
    std::cout << "I am a type animal: " << GREEN << j->getType() << RESET << std::endl;

    lBreak(1);

    i->makeSound();
    j->makeSound();
    meta->makeSound();

    lBreak(1);


    delete meta;
    delete j;
    delete i;


    separator("WRONGANIMAL TEST");


    const WrongAnimal* meta2 = new WrongAnimal();
    const WrongAnimal* ii = new WrongCat();

    lBreak(1);

    std::cout << "I am a type animal: " << GREEN << meta2->getType() << RESET << std::endl;
    std::cout << "I am a type animal: " << GREEN << ii->getType() << RESET << std::endl;

    lBreak(1);

    ii->makeSound();
    meta2->makeSound();

    lBreak(1);


    delete meta2;
    delete ii;

    return 0;
}
