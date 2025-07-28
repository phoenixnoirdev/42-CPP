/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phkevin <phkevin@42luxembourg.lu>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 01:38:14 by phkevin           #+#    #+#             */
/*   Updated: 2025/04/06 01:38:14 by phkevin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <cstddef>
#include <iostream>

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
#define LOGO "Fonction: "

/**
 * @brief Applique une fonction a chaque element d'un tableau.
 *
 * Cette fonction parcourt le tableau d'entrees et applique la fonction
 * donnee a chaque element du tableau. Elle ne renvoie rien.
 *
 * @tparam T Type des elements du tableau.
 * @tparam F Type de la fonction a appliquer.
 * @param array Tableau d'element a traiter.
 * @param length Taille du tableau.
 * @param func Fonction a appliquer a chaque element du tableau.
 */
template <typename T, typename F>
void iter(T* array, int length, F func)
{
    for (int i = 0; i < length; ++i)
        func(array[i]);
}

/**
 * @brief Affiche une valeur dans la console avec une mise en forme.
 *
 * Affiche la valeur donnee en l'encadrant d'une couleur et d'un logo
 * defini, suivie d'un retour a la ligne.
 *
 * @tparam T Type de la valeur a afficher (doit etre compatible avec
 *           std::ostream).
 * @param str Valeur a afficher.
 */
template <typename T>
void print(T str)
{
    std::cout << GREEN << LOGO << RESET << str << std::endl;
}


#endif //ITER_HPP