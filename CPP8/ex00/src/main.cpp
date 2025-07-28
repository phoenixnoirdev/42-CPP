/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phkevin <phkevin@42luxembourg.lu>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 00:53:42 by phkevin           #+#    #+#             */
/*   Updated: 2025/04/12 00:53:42 by phkevin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Easyfind.hpp"

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
	std::vector<int> vec;
	std::list<int>   lst;
	std::deque<int>  deq;

	//==============================
	// TEST VECTEUR
	//==============================
	separator("TEST ARRAY");

	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	vec.push_back(4);
	vec.push_back(5);

	try 
	{
		easyfind(vec, 5);	// OK
		easyfind(vec, 10);	// EXCEPTION
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}


	//==============================
	// TEST LIST
	//==============================
	separator("TEST LIST");

	lst.push_back(10);
	lst.push_back(20);
	lst.push_back(30);
	lst.push_back(40);
	lst.push_back(50);

	try
	{
		easyfind(lst, 20);	// OK
		easyfind(lst, 5);	// EXCEPTION
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	//==============================
	// TEST DEQUE
	//==============================
	separator("TEST DEQUE");

	deq.push_back(100);
	deq.push_back(200);
	deq.push_back(300);
	deq.push_back(400);
	deq.push_back(500);

	try
	{
		easyfind(deq, 300);	// OK
		easyfind(deq, 900);	// EXCEPTION
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
}
