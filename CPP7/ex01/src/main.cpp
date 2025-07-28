/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phkevin <phkevin@42luxembourg.lu>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 01:38:21 by phkevin           #+#    #+#             */
/*   Updated: 2025/04/06 01:38:21 by phkevin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Iter.hpp"

/**
 * @brief Affiche plusieurs lignes vides dans la console.
 *
 * @param nb Nombre de lignes vides a afficher.
 */
void lBreak(int nb)
{
    for (int i = 0; i < nb; ++i)
        std::cout << std::endl;
}

/**
 * @brief Affiche un separateur formate avec un titre centr�.
 *
 * @param str Texte a afficher au centre du separateur.
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
    //==============================
    // TEST TYPE INT
    //==============================
    separator("TEST TYPE INT");

    int arr[] = { 1, 2, 3, 4, 5 };

    iter(arr, 5, print<int>);
    

    //==============================
    // TEST TYPE STRING
    //==============================
    separator("TEST TYPE STRING");

    std::string words[] = { "Hello", "World", "Template", "Test" };

    iter(words, 4, print<std::string>);


    return 0;
}

