/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phkevin <phkevin@42luxembourg.lu>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 13:32:05 by phkevin           #+#    #+#             */
/*   Updated: 2025/07/07 13:32:05 by phkevin          ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

/**
 * @brief Constructeur par défaut de la classe MutantStack.
 *
 * Initialise une pile vide. Si le mode DEBUG est activé, un message de
 * confirmation coloré est affiché sur la sortie standard.
 *
 * @tparam T Type des éléments stockés dans la pile.
 * @tparam C Type du conteneur sous-jacent (par défaut std::deque<T>).
 */
template <typename T, typename C> 
MutantStack<T, C>::MutantStack()
{
	if (DEBUG == true)
		std::cout << GREEN << LOGO << RESET << "Default constructor called" << RESET << std::endl;
}


/**
 * @brief Constructeur de copie de MutantStack.
 *
 * Initialise une pile en copiant une autre. Affiche un message si DEBUG est actif.
 *
 * @param other Référence constante vers la pile à copier.
 *
 * @tparam T Type des éléments stockés.
 * @tparam C Type du conteneur sous-jacent (par défaut std::deque<T>).
 */
template <typename T, typename C> 
MutantStack<T, C>::MutantStack(const MutantStack<T, C> &other)
{
	if (DEBUG == true)
		std::cout << GREEN << LOGO << RESET << "Copy constructor called" << RESET << std::endl;

	*this = other;
}


/**
 * @brief Surcharge de l'opérateur d'affectation pour MutantStack.
 *
 * Permet de copier le contenu d'une autre pile MutantStack dans l'objet courant.
 * Appelle explicitement l'opérateur d'affectation de la classe std::stack.
 * Si le mode DEBUG est activé, un message est affiché.
 *
 * @param other Référence constante vers la pile à copier.
 * @return Référence vers l'objet courant après l'affectation.
 *
 * @tparam T Type des éléments stockés.
 * @tparam C Type du conteneur sous-jacent (par défaut std::deque<T>).
 */
template <typename T, typename C> 
MutantStack<T, C> &MutantStack<T, C>::operator=(const MutantStack &other)
{
	if (DEBUG == true)
		std::cout << GREEN << LOGO << RESET << "Operator constructor called" << RESET << std::endl;

	if(this != &other)
		std::stack<T, C>::operator=(other);
	
	return (*this);
}


/**
 * @brief Destructeur de la classe MutantStack.
 *
 * Libère les ressources associées à l'objet courant. Comme std::stack
 * ne gère que des conteneurs standard (par défaut un std::deque), 
 * aucune libération manuelle n'est nécessaire.
 * Affiche un message si le mode DEBUG est activé.
 *
 * @tparam T Type des éléments stockés.
 * @tparam C Type du conteneur sous-jacent (par défaut std::deque<T>).
 */
template <typename T, typename C> 
MutantStack<T, C> ::~MutantStack()
{
	if (DEBUG == true)
		std::cout << GREEN << LOGO << RESET << "Destructor called!" << RESET << std::endl;
}
