/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phkevin <phkevin@42luxembourg.lu>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 09:59:36 by phkevin           #+#    #+#             */
/*   Updated: 2025/03/03 10:02:03 by phkevin          ###   Luxembour.lu      */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Zombie.hpp"

int main()
{
    int nb = 5;
    int i = 0;

    Zombie* horde = zombieHorde(nb, "bozo");
    while (i < nb)
        horde[i++].Announce();
    delete[] horde;
    return 0;
}