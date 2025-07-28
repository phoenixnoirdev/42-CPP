/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phkevin <phkevin@42luxembourg.lu>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 03:52:00 by phkevin           #+#    #+#             */
/*   Updated: 2025/04/04 03:52:00 by phkevin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"


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
    // TEST TYPE
	//==============================
	separator("TEST TYPE");

	std::srand(std::time(0));

	for (int i = 0; i < 10; i++)
	{
		Base* t = Generate();
		identify(t);
		identify(*t);
		delete t;
		lBreak(2);
	}

    return 0;
}
