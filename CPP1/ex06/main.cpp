/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phkevin <phkevin@42luxembourg.lu>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 10:36:24 by phkevin           #+#    #+#             */
/*   Updated: 2025/03/10 12:49:23 by phkevin          ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

/**
 * @brief Compare deux chaînes de caractères pour vérifier leur égalité.
 *
 * Cette fonction compare les deux chaînes `s1` et `s2` caractère par caractère 
 * jusqu'à la fin ou jusqu'à un saut de ligne. Si les chaînes sont identiques, 
 * la fonction retourne 0. Sinon, elle retourne 1.
 * 
 * @param s1 La première chaîne à comparer.
 * @param s2 La seconde chaîne à comparer.
 * @return 0 si les chaînes sont identiques, sinon 1.
 */
int equals(std::string s1, std::string s2)
{
    int i = 0;
    int ii = 0;

    while (s1[i] != '\n' && s1[i] != '\0')
        i++;
    while (s2[ii] != '\n' && s2[ii] != '\0')
        ii++;
    if (i != ii)
        return 1;
    for (int j = 0; j < i; j++)
    {
        if (s1[j] != s2[j])
            return 1;
    }

    return 0;
}

int main(int argc, char** argv)
{
    Harl harl;

    if (argc != 2)
    {
        std::cout << "error: Please enter the log level you would like to listen to: " << std::endl;
        std::cout << "DEBUG" << std::endl;
        std::cout << "INFO" << std::endl;
        std::cout << "WARNING" << std::endl;
        std::cout << "ERROR" << std::endl;

        return 1;
    }
    if (!equals(argv[1], "DEBUG"))
        harl.complain("0");
    else if (!equals(argv[1], "INFO"))
        harl.complain("1");
    else if (!equals(argv[1], "WARNING"))
        harl.complain("2");
    else if (!equals(argv[1], "ERROR"))
        harl.complain("3");
    else
        std::cout << "Probably complaining about insignificant problems" << std::endl;
    
    return 0;
}