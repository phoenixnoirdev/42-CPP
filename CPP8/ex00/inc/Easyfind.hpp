/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phkevin <phkevin@42luxembourg.lu>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 00:53:29 by phkevin           #+#    #+#             */
/*   Updated: 2025/04/12 00:53:29 by phkevin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <exception>
#include <iostream>
#include <vector>
#include <list>
#include <deque>

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
// LOGO IN LOG
//==============================
#define LOGO "Easyfind: "
#define LOGOEXCE "Exception: "

//==============================
// DEBUG ACTIF
//==============================
#define DEBUG false // Permet d'afficher les DEBUG si TRUE et FALSE pour desactiver
#define LANG "ENG" // Permet d'afficher les ERROR en anglais ou francais, set a ENG ou FR


template <typename T>
void easyfind(T& cont, int val);


class ExcepValue : public std::exception
{
	virtual const char* what() const throw();
};


#include "Easyfind.tpp"

#endif //EASYFIND_HPP