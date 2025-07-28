/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phkevin <phkevin@42luxembourg.lu>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 00:06:06 by phkevin           #+#    #+#             */
/*   Updated: 2025/04/06 00:06:06 by phkevin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../inc/whatever.hpp"


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

    int a = 2;
    int b = 3;

    std::cout << GREEN << LOGO << RESET << "a = " << YELLOW << a << RESET << ", b = " << YELLOW << b << RESET << std::endl;
    ::swap(a, b);
    std::cout << GREEN << LOGO << RESET << "a = " << YELLOW << a << RESET << ", b = " << YELLOW << b << RESET << std::endl;
    std::cout << GREEN << LOGO << RESET << "min(a, b) = " << YELLOW << ::min(a, b) << RESET << std::endl;
    std::cout << GREEN << LOGO << RESET << "max(a, b) = " << YELLOW << ::max(a, b) << RESET << std::endl;

    lBreak(2);



    //==============================
    // TEST TYPE STRING
    //==============================
    separator("TEST TYPE STRING");

    std::string c = "chaine 1";
    std::string d = "chaine 2";

    std::cout << GREEN << LOGO << RESET << "c = " << YELLOW << c << RESET << ", d = " << YELLOW << d << RESET << std::endl;
    ::swap(c, d);
    std::cout << GREEN << LOGO << RESET << "c = " << YELLOW << c << RESET << ", d = " << YELLOW << d << RESET << std::endl;
    std::cout << GREEN << LOGO << RESET << "min(c, d) = " << YELLOW << ::min(c, d) << RESET << std::endl;
    std::cout << GREEN << LOGO << RESET << "max(c, d) = " << YELLOW << ::max(c, d) << RESET << std::endl;


    lBreak(2);



    //==============================
    // TEST TYPE FLOAT
    //==============================
    separator("TEST TYPE FLOAT");

    float e = 0.5f;
    float f = 0.10f;

    std::cout << GREEN << LOGO << RESET << "e = " << YELLOW << e << RESET << ", f = " << YELLOW << f << RESET << std::endl;
    ::swap(e, f);
    std::cout << GREEN << LOGO << RESET << "e = " << YELLOW << e << RESET << ", f = " << YELLOW << f << RESET << std::endl;
    std::cout << GREEN << LOGO << RESET << "min(e, f) = " << YELLOW << ::min(e, f) << RESET << std::endl;
    std::cout << GREEN << LOGO << RESET << "max(e, f) = " << YELLOW << ::max(e, f) << RESET << std::endl;

    return 0;
}
    