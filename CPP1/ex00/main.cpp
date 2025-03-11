/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phkevin <phkevin@42luxembourg.lu>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 10:17:45 by phkevin           #+#    #+#             */
/*   Updated: 2025/02/03 10:17:45 by phkevin          ###   Luxembour.lu      */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Zombie.hpp"

int main()
{
    Zombie *z = newZombie("test");
    z->Announce();
    delete(z);
    randomChump("BOO");
    
    return 0;
}