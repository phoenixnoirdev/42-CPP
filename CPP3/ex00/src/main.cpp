/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phkevin <phkevin@42luxembourg.lu>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 09:26:29 by phkevin           #+#    #+#             */
/*   Updated: 2025/03/31 11:10:22 by phkevin          ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"

int main(void)
{
	std::cout << YELLOW << "------------------------------------" << RESET << std::endl;
	std::cout << YELLOW << "CLAPTRAP EX00" << RESET << std::endl;
	std::cout << YELLOW << "------------------------------------" << RESET << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;

	
	ClapTrap a ("Toto");
	ClapTrap b ("Tata");

	std::cout << std::endl;
	
	a.setAtkDamagePoints(5);
	while (a.getEnergyPoints() > 0)
	{
		a.attack(b.getName());
		b.takeDamage(a.getAtkDamagePoints());
		b.beRepaired(4);
	}
	
	
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << YELLOW << "------------------------------------" << RESET << std::endl;
	std::cout << YELLOW << "DESTRUCTION" << RESET << std::endl;
	std::cout << YELLOW << "------------------------------------" << RESET << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;

	return 0;
}