/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phkevin <phkevin@42luxembourg.lu>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 11:26:43 by phkevin           #+#    #+#             */
/*   Updated: 2025/03/05 14:57:55 by phkevin          ###   Luxembour.lu      */
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
Fixed::Fixed(const Fixed &fix)
{
	nb = fix.nb;
	std::cout << "Copy constructor called\n";
}

/**
 * @brief Constructeur de la classe Fixed à partir d'un entier.
 * 
 * Ce constructeur prend un entier et le convertit en une valeur fixe en 
 * décalant les bits de l'entier à gauche par un nombre de bits défini. Ce 
 * processus permet de représenter des nombres avec une partie fractionnaire.
 * 
 * @param i L'entier à convertir en valeur fixe.
 */
Fixed::Fixed(const int i)
{
	nb = i << bit;
	std::cout << "Int constructor called\n";
}

/**
 * @brief Constructeur de la classe Fixed à partir d'un flottant.
 * 
 * Ce constructeur prend un nombre flottant et le convertit en une valeur fixe
 * en multipliant le flottant par une puissance de 2 et en arrondissant le résultat. 
 * Cela permet de stocker les valeurs avec une précision fractionnaire fixe.
 * 
 * @param i Le nombre flottant à convertir en valeur fixe.
 */
Fixed::Fixed(const float i) : nb(i)	
{
	nb = roundf(i * (1 << bit));
	std::cout << "Float constructor called\n";
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
Fixed &Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignment operator called\n";
	if (this != &other) {
		this->nb = other.getRawBits();
	}
	return *this;
}

/**
 * @brief Surcharge de l'opérateur d'insertion dans un flux de sortie.
 * 
 * Cette fonction permet d'afficher un objet de type Fixed dans un flux de sortie
 * (comme std::cout). L'objet Fixed est converti en un nombre flottant via la méthode
 * toFloat() avant d'être affiché.
 * 
 * @param os Le flux de sortie dans lequel l'objet Fixed sera inséré.
 * @param other L'objet Fixed à afficher.
 * @return std::ostream& Le flux de sortie mis à jour.
 */
std::ostream& operator<<(std::ostream& os, const Fixed& other)
{
	os << other.toFloat();
	return os;
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
 * @brief Convertit la valeur de l'objet Fixed en un entier.
 * 
 * Cette fonction effectue une conversion de la valeur de l'objet Fixed (qui est
 * stockée sous forme de nombre entier avec une partie fractionnaire) en un entier
 * en décalant les bits de la partie fractionnaire.
 * 
 * @return int La valeur de l'objet Fixed convertie en entier.
 */
int	Fixed::toInt() const
{
	return nb >> bit;
}

/**
 * @brief Convertit la valeur de l'objet Fixed en un nombre flottant.
 * 
 * Cette fonction effectue une conversion de la valeur stockée de l'objet Fixed
 * (qui est en nombre entier avec une partie fractionnaire) en un nombre flottant.
 * La conversion est réalisée en divisant la valeur entière par le facteur
 * correspondant à la partie fractionnaire.
 * 
 * @return float La valeur de l'objet Fixed convertie en flottant.
 */
float Fixed::toFloat() const
{
	return (float)nb / (float)(1 << bit);
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