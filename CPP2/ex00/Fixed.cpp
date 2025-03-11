/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phkevin <phkevin@42luxembourg.lu>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 10:41:28 by phkevin           #+#    #+#             */
/*   Updated: 2025/03/03 10:53:08 by phkevin          ###   Luxembour.lu      */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/**
 * @brief Constructeur par défaut de la classe Fixed.
 * 
 * Initialise l'attribut `nb` à 0 et affiche un message indiquant 
 * l'appel du constructeur.
 */
Fixed::Fixed() : nb(0)
{
	std::cout << "Default constructor called\n";
}

/**
 * @brief Constructeur par copie de la classe Fixed.
 * 
 * Initialise l'attribut `nb` avec la valeur de `fix.nb` et affiche 
 * un message indiquant l'appel du constructeur de copie.
 * 
 * @param fix Référence vers l'objet Fixed à copier.
 */
Fixed::Fixed(Fixed &fix)
{
	nb = fix.nb;
	std::cout << "Copy constructor called\n";
}

/**
 * @brief Surcharge de l'opérateur d'affectation.
 * 
 * Copie la valeur de `other.nb` dans l'objet courant après vérification
 * qu'il ne s'agit pas d'une auto-affectation. Affiche un message indiquant
 * l'appel de l'opérateur d'affectation.
 * 
 * @param other Référence constante vers l'objet Fixed à copier.
 * @return Référence vers l'objet courant après l'affectation.
 */
Fixed &Fixed::operator=(const Fixed &other) {
	std::cout << "Copy assignment operator called\n";
	if (this != &other) {
		this->nb = other.nb;
	}
	return *this;
}

/**
 * @brief Retourne la valeur brute stockée.
 * 
 * Affiche un message indiquant l'appel de la fonction et retourne
 * la valeur entière stockée dans `nb`.
 * 
 * @return La valeur brute de l'objet.
 */
int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called\n";
	return nb;
}

/**
 * @brief Définit la valeur brute stockée.
 * 
 * Met à jour la valeur entière `nb` avec la valeur passée en argument.
 * 
 * @param raw La nouvelle valeur brute à stocker.
 */
void Fixed::setRawBits(int const raw)
{
	nb = raw;
}

/**
 * @brief Détruit l'objet Fixed.
 * 
 * Affiche un message indiquant que le destructeur est appelé
 * avant la destruction de l'instance.
 */
Fixed::~Fixed()
{
	std::cout << "Destructor called\n";
}