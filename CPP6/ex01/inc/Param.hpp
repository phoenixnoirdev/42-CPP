/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Param.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phkevin <phkevin@42luxembourg.lu>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 08:34:02 by phkevin           #+#    #+#             */
/*   Updated: 2025/03/31 08:34:02 by phkevin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARAM_HPP
#define PARAM_HPP

#include <iostream>
#include <string>
#include <stdint.h>

//==============================
// FORMAT TEXTE
//==============================
#define RESET   "\033[0;39m"
#define RED     "\033[0;31m"
#define GREEN   "\033[0;92m"
#define YELLOW  "\033[0;93m"
#define BLUE    "\033[0;34m"
#define MAGENTA "\033[0;35m"
#define CYAN    "\033[0;36m"
#define WHITE   "\033[0;37m"



//==============================
// STRUCTURE
//==============================

/**
 * @brief Structure repr�sentant des donn�es avec un nom et une valeur.
 *
 * Cette structure contient un nom sous forme de cha�ne de caract�res
 * et une valeur enti�re associ�e.
 */
struct Data
{
    std::string name;
    int value;
};

#endif //PARAM_HPP