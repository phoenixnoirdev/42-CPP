/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phkevin <phkevin@42luxembourg.lu>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 00:06:15 by phkevin           #+#    #+#             */
/*   Updated: 2025/04/06 00:06:15 by phkevin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

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
 * @brief Echange les valeurs de deux variables.
 *
 * Cette fonction prend deux references et echange leurs contenus
 * en utilisant une variable temporaire.
 *
 * @tparam T Type des variables a echanger.
 * @param a Reference vers la premiere variable.
 * @param b Reference vers la seconde variable.
 */
template <typename T>
void swap(T &a, T &b)
{
    T tmp = a;
    a = b;
    b = tmp;
}

/**
 * @brief Retourne la plus petite des deux valeurs.
 *
 * Compare les deux valeurs donnees et retourne celle qui est inferieure ou
 * egale a l'autre.
 *
 * @tparam T Type des valeurs a comparer.
 * @param a Premiere valeur.
 * @param b Deuxieme valeur.
 * @return La valeur minimale entre a et b.
 */
template <typename T>
T min(const T &a, const T &b)
{
    if (a < b)
        return a;
    else
        return b;
}

/**
 * @brief Retourne la plus grande des deux valeurs.
 *
 * Compare les deux valeurs donnees et retourne celle qui est superieure ou
 * egale a l'autre.
 *
 * @tparam T Type des valeurs a comparer.
 * @param a Premiere valeur.
 * @param b Deuxieme valeur.
 * @return La valeur maximale entre a et b.
 */
template <typename T>
T max(const T& a, const T& b)
{
    if (a > b)
        return a;
    else
        return b;
}

#endif //WHATEVER_HPP