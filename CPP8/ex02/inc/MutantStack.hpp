/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phkevin <phkevin@42luxembourg.lu>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 13:32:20 by phkevin           #+#    #+#             */
/*   Updated: 2025/07/07 13:32:20 by phkevin          ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>
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
#define LOGO "MutantStack: "
#define LOGOEXCE "Exception: "


//==============================
// DEBUG ACTIF
//==============================
#define DEBUG false // Permet d'afficher les DEBUG si TRUE et FALSE pour desactiver
#define LANG "ENG" // Permet d'afficher les ERROR en anglais ou francais, set a ENG ou FR

/**
 * @brief Classe MutantStack permettant d'ajouter l'itérabilité à std::stack.
 *
 * Hérite de std::stack<T, C> et expose les itérateurs du conteneur sous-jacent.
 *
 * @tparam T Type des éléments stockés
 * @tparam C Conteneur sous-jacent (par défaut std::deque<T>)
 */
template <typename T, typename C = std::deque<T> >
class MutantStack : public std::stack<T,C>
{
	public:
		MutantStack();
		MutantStack(const MutantStack& obj);
		MutantStack& operator=(const MutantStack& obj);
		~MutantStack();


		/// Itérateur sur le conteneur sous-jacent
		typedef typename C::iterator iterator;

		/// Itérateur constant
		typedef typename C::const_iterator const_iterator;

		/**
		 * @brief Retourne un itérateur vers le début de la pile.
		 *
		 * Permet d'accéder à un itérateur pointant sur le premier élément
		 * du conteneur sous-jacent utilisé par la pile (par défaut un `std::deque`).
		 * Utile pour itérer sur les éléments de la pile comme avec un conteneur standard.
		 *
		 * @return Un itérateur vers le début du conteneur sous-jacent.
		 */
		iterator begin()
		{
			return this->c.begin();
		}
		/**
		 * @brief Retourne un itérateur vers la fin de la pile.
		 *
		 * Cet itérateur pointe vers l'élément suivant le dernier élément du conteneur
		 * sous-jacent utilisé par la pile (par défaut un `std::deque`). Il est utilisé
		 * pour marquer la fin d'une itération.
		 *
		 * @return Un itérateur vers la fin du conteneur sous-jacent.
		 */
		iterator end()
		{
			return this->c.end();
		}


		/**
		 * @brief Retourne un itérateur constant vers le début de la pile.
		 *
		 * Cet itérateur permet de lire les éléments de la pile sans possibilité de
		 * les modifier. Il pointe vers le premier élément du conteneur sous-jacent
		 * (par défaut un `std::deque`).
		 *
		 * @return Un itérateur constant vers le début du conteneur sous-jacent.
		 */
		const_iterator begin() const
		{
			return this->c.begin();
		}
		/**
		 * @brief Retourne un itérateur constant vers la fin de la pile.
		 *
		 * Cet itérateur permet de lire les éléments de la pile sans possibilité de
		 * les modifier. Il pointe juste après le dernier élément du conteneur
		 * sous-jacent (par défaut un `std::deque`), ce qui permet une itération
		 * classique de type `[begin(), end())`.
		 *
		 * @return Un itérateur constant vers la fin du conteneur sous-jacent.
		 */
		const_iterator end() const
		{
			return this->c.end();
		}
};

#include "MutantStack.tpp"

#endif // MUTANTSTACK_HPP
