/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phkevin <phkevin@42luxembourg.lu>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 09:26:54 by phkevin           #+#    #+#             */
/*   Updated: 2025/04/14 11:15:07 by phkevin          ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>
#include <iostream>

#define RESET   "\033[0;39m"
#define RED     "\033[0;31m"
#define GREEN   "\033[0;92m"
#define YELLOW  "\033[0;93m"
#define BLUE    "\033[0;34m"
#define MAGENTA "\033[0;35m"
#define CYAN    "\033[0;36m"
#define WHITE   "\033[0;37m"

class ClapTrap
{
	private:
		std::string name;
		int hit_points;			//HP
		int energy_points;		//MP
		int attack_damage;		//ATK

		//==============================
		// GETTER AND SETTER
		//==============================
		void setName(std::string nam);
		void setEnergyPoints(int i);
		void setHitPoints(int i);
	
	public:
		//==============================
		// CONSTRUCTEUR
		//==============================
		ClapTrap();
		ClapTrap(const std::string str);
		ClapTrap(const ClapTrap &other);
		ClapTrap& operator=(const ClapTrap &other);
		~ClapTrap();

		//==============================
		// FONCTION
		//==============================
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);

		//==============================
		// GETTER AND SETTER
		//==============================
		std::string getName() const;
		int	getHitPoints() const;
		int	getEnergyPoints() const;
		void setAtkDamagePoints(int i);
		unsigned int getAtkDamagePoints() const;
};
#endif // CLAPTRAP_HPP