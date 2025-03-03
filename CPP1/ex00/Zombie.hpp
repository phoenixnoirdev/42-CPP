/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phkevin <phkevin@42luxembourg.lu>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 10:17:58 by phkevin           #+#    #+#             */
/*   Updated: 2025/02/03 10:17:58 by phkevin          ###   Luxembour.lu      */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie
{
private:
	std::string name;

public:
	void	Announce(void) const;

	Zombie(const std::string& nam);
};

void randomChump(std::string name);

Zombie *newZombie(std::string name);

#endif // ZOMBIE_HPP