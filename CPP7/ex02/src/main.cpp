/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phkevin <phkevin@42luxembourg.lu>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 23:41:10 by phkevin           #+#    #+#             */
/*   Updated: 2025/04/09 23:41:10 by phkevin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Array.hpp"

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
    // TEST ARRAY
    //==============================
    separator("TEST ARRAY");

    Array<int> arr1(5);
    for (unsigned int i = 0; i < arr1.size(); ++i)
        arr1[i] = i * 10;

    Array<int> arr2 = arr1;
    arr2[0] = 999;

    std::cout << GREEN << LOGO << RESET << "arr1[0] = " << YELLOW << arr1[0] << RESET << std::endl; // Retourn 0
    std::cout << GREEN << LOGO << RESET << "arr2[0] = " << YELLOW << arr2[0] << RESET << std::endl; // Retourn 999


    //==============================
    // TEST EXCEPTION
    //==============================
    separator("TEST EXCEPTION");

    try {
        std::cout << GREEN << LOGO << RESET << arr1[10] << std::endl;
    }
    catch (const std::exception& e) {
        std::cout << GREEN << LOGO << RESET << "Exception: " << RED << e.what() << RESET << std::endl;
    }
}
