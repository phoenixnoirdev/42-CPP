/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phkevin <phkevin@42luxembourg.lu>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 10:01:02 by phkevin           #+#    #+#             */
/*   Updated: 2025/03/03 10:01:24 by phkevin          ###   Luxembour.lu      */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/**
 * @brief Crée une horde de zombies avec un nom donné.
 *
 * Cette fonction alloue dynamiquement un tableau de zombies et leur assigne
 * le même nom. Chaque zombie est initialisé via la méthode SetName().
 *
 * @param N Le nombre de zombies à créer.
 * @param name Le nom à attribuer à chaque zombie.
 * @return Zombie* Un pointeur vers le premier élément de la horde de zombies.
 */
Zombie* zombieHorde(int N, std::string name)
{
	Zombie* horde;
	horde = new Zombie[N];
	for (int i = 0; i < N; i++)
	{
		horde[i].SetName(name);
	}
	return horde;
}
