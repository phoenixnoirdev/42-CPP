/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phkevin <phkevin@42luxembourg.lu>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 09:26:29 by phkevin           #+#    #+#             */
/*   Updated: 2025/03/12 14:32:51 by phkevin          ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(void)
{
	std::cout << YELLOW << "------------------------------------" << RESET << std::endl;
	std::cout << YELLOW << "CLAPTRAP EX00" << RESET << std::endl;
	std::cout << YELLOW << "------------------------------------" << RESET << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;

	
	ClapTrap a("Toto");
	ClapTrap b("Tata");

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
	std::cout << YELLOW << "SCAVTRAP EX01" << RESET << std::endl;
	std::cout << YELLOW << "------------------------------------" << RESET << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;


	ScavTrap sa("Scavosse");
	ClapTrap reb0("Rebelle_0");
	ClapTrap reb1("Rebelle_1");
	ClapTrap reb2("Rebelle_2");

	std::cout << std::endl;

	reb0.setAtkDamagePoints(2);
	reb1.setAtkDamagePoints(5);
	reb2.setAtkDamagePoints(4);

	sa.guardGate();

	while (sa.getHitPoints() > 0 && sa.getEnergyPoints() > 0)
	{
		if (reb0.getHitPoints() > 0 && reb0.getEnergyPoints() > 0)
		{
			reb0.attack(sa.getName());
			sa.takeDamage(reb0.getAtkDamagePoints());
		}

		if (reb1.getHitPoints() > 0 && reb1.getEnergyPoints() > 0)
		{
			reb1.attack(sa.getName());
			sa.takeDamage(reb1.getAtkDamagePoints());
		}

		if (reb2.getHitPoints() > 0 && reb2.getEnergyPoints() > 0)
		{
			reb2.attack(sa.getName());
			sa.takeDamage(reb1.getAtkDamagePoints());
		}

		sa.beRepaired(1);

		if (reb0.getHitPoints() > 0)
		{
			sa.attack(reb0.getName());
			reb0.takeDamage(sa.getAtkDamagePoints());
		}
		else if (reb1.getHitPoints() > 0)
		{
			sa.attack(reb1.getName());
			reb1.takeDamage(sa.getAtkDamagePoints());
		}
		else if (reb2.getHitPoints() > 0)
		{
			sa.attack(reb2.getName());
			reb2.takeDamage(sa.getAtkDamagePoints());
		}

		if (reb0.getHitPoints() <= 0 && reb1.getHitPoints() <= 0 && reb2.getHitPoints() <= 0)
			break;
	}


	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << YELLOW << "------------------------------------" << RESET << std::endl;
	std::cout << YELLOW << "FRAGTRAP EX02" << RESET << std::endl;
	std::cout << YELLOW << "------------------------------------" << RESET << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;


	FragTrap fa("Fragosse");
	ClapTrap fra("Fragui_0");

	fra.setAtkDamagePoints(2);

	fa.highFivesGuys();
	fra.attack(fa.getName());
	fa.takeDamage(fra.getAtkDamagePoints());


	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << YELLOW << "------------------------------------" << RESET << std::endl;
	std::cout << YELLOW << "DESTRUCTION" << RESET << std::endl;
	std::cout << YELLOW << "------------------------------------" << RESET << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;

	return 0;
}
