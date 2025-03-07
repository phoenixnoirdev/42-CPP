/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phkevin <phkevin@42luxembourg.lu>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 12:56:07 by phkevin           #+#    #+#             */
/*   Updated: 2025/03/07 01:52:29 by phkevin          ###   Luxembourg.lu     */
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
Fixed::Fixed(const Fixed& fix)
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
Fixed::Fixed(const float i)
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
Fixed& Fixed::operator=(const Fixed& other)
{
	std::cout << "Copy assignment operator called\n";
	if (this != &other) {
		this->nb = other.getRawBits();
	}
	return *this;
}

/**
 * @brief Compare si l'objet courant est inférieur à un autre Fixed.
 *
 * Cette surcharge de l'opérateur < permet de comparer deux objets Fixed
 * en fonction de leur valeur interne stockée.
 *
 * @param other L'objet Fixed à comparer.
 * @return true Si l'objet courant est inférieur à other.
 * @return false Sinon.
 */

bool Fixed::operator<(const Fixed& other) const
{
	return this->nb < other.nb;
}

/**
 * @brief Compare si l'objet courant est supérieur à un autre Fixed.
 *
 * Cette surcharge de l'opérateur > permet de comparer deux objets Fixed
 * en fonction de leur valeur interne stockée.
 *
 * @param other L'objet Fixed à comparer.
 * @return true Si l'objet courant est supérieur à other.
 * @return false Sinon.
 */
bool Fixed::operator>(const Fixed& other) const
{
	return this->nb > other.nb;
}

/**
 * @brief Vérifie si l'objet courant est strictement supérieur à un autre Fixed.
 *
 * Compare les valeurs internes des objets Fixed et retourne vrai si
 * l'objet actuel a une valeur plus grande que l'objet other.
 *
 * @param other L'objet Fixed à comparer.
 * @return true Si l'objet courant est supérieur à other.
 * @return false Sinon.
 */
bool Fixed::operator<=(const Fixed& other) const
{
	return this->nb <= other.nb;
}

/**
 * @brief Vérifie si l'objet courant est supérieur ou égal à un autre Fixed.
 *
 * Compare les valeurs internes des objets Fixed et retourne vrai si
 * l'objet actuel est plus grand ou égal à l'objet other.
 *
 * @param other L'objet Fixed à comparer.
 * @return true Si l'objet courant est supérieur ou égal à other.
 * @return false Sinon.
 */
bool Fixed::operator>=(const Fixed& other) const
{
	return this->nb >= other.nb;
}

/**
 * @brief Vérifie si deux objets Fixed sont égaux.
 *
 * Compare les valeurs internes des objets Fixed et retourne vrai si
 * elles sont identiques.
 *
 * @param other L'objet Fixed à comparer.
 * @return true Si les deux objets sont égaux.
 * @return false Sinon.
 */
bool Fixed::operator==(const Fixed& other) const
{
	return this->nb == other.nb;
}

/**
 * @brief Vérifie si deux objets Fixed sont différents.
 *
 * Compare les valeurs internes des objets Fixed et retourne vrai si
 * elles sont différentes.
 *
 * @param other L'objet Fixed à comparer.
 * @return true Si les deux objets sont différents.
 * @return false Sinon.
 */
bool Fixed::operator!=(const Fixed& other) const
{
	return this->nb != other.nb;
}

/**
 * @brief Ajoute un autre objet Fixed à l'objet actuel.
 *
 * Cette fonction additionne l'attribut `nb` de l'objet `other` à celui de l'objet
 * actuel et retourne un nouvel objet Fixed contenant le résultat de l'addition.
 *
 * @param other L'objet Fixed à ajouter à l'objet actuel.
 * @return Fixed Un nouvel objet Fixed contenant le résultat de l'addition.
 */
Fixed Fixed::operator+(const Fixed& other) const
{
	return Fixed(this->toFloat() + other.toFloat());
}

/**
 * @brief Soustrait un autre objet Fixed de l'objet actuel.
 *
 * Cette fonction soustrait l'attribut `nb` de l'objet `other` à celui de l'objet
 * actuel et retourne un nouvel objet Fixed contenant le résultat de la soustraction.
 *
 * @param other L'objet Fixed à soustraire de l'objet actuel.
 * @return Fixed Un nouvel objet Fixed contenant le résultat de la soustraction.
 */
Fixed Fixed::operator-(const Fixed& other) const
{
	return Fixed(this->toFloat() - other.toFloat());
}

/**
 * @brief Multiplie l'objet Fixed par un autre objet Fixed.
 *
 * Cette fonction multiplie l'attribut `nb` de l'objet actuel par celui
 * de l'objet `other` et retourne un nouvel objet Fixed contenant
 * le résultat de la multiplication.
 *
 * @param other L'objet Fixed avec lequel multiplier l'objet actuel.
 * @return Fixed Un nouvel objet Fixed contenant le résultat de la multiplication.
 */
Fixed Fixed::operator*(const Fixed& other) const
{
	return Fixed(this->toFloat() * other.toFloat());
}

/**
 * @brief Divise l'objet Fixed par un autre objet Fixed.
 *
 * Cette fonction divise l'attribut `nb` de l'objet actuel par celui
 * de l'objet `other` et retourne un nouvel objet Fixed contenant
 * le résultat de la division.
 *
 * @param other L'objet Fixed avec lequel diviser l'objet actuel.
 * @return Fixed Un nouvel objet Fixed contenant le résultat de la division.
 */
Fixed Fixed::operator/(const Fixed& other) const
{
	if (other.nb == 0)
		return Fixed();
	return Fixed(this->toFloat() / other.toFloat());
}

/**
 * @brief Incrémente la valeur de l'objet Fixed.
 *
 * Effectue l'incrémentation de la valeur interne de l'objet Fixed
 * et retourne l'objet mis à jour.
 *
 * @return Fixed& Référence à l'objet Fixed mis à jour.
 */
Fixed Fixed::operator++()
{
	nb += 1;
	return *this;
}

/**
 * @brief Incrémente la valeur de l'objet Fixed (suffixe).
 *
 * Cette fonction crée une copie temporaire de l'objet, incrémente
 * la valeur de l'attribut `nb`, puis retourne la copie temporaire
 * de l'objet avant l'incrémentation.
 *
 * @param i Un paramètre inutilisé, nécessaire pour la surcharge de l'opérateur.
 * @return Fixed& Référence à l'objet avant l'incrémentation.
 */
Fixed Fixed::operator++(int)
{
	Fixed tmp(*this);
	nb += 1;
	return tmp;
}

/**
 * @brief Décrémente la valeur de l'objet Fixed (préfixe).
 *
 * Cette fonction décrémente la valeur de l'attribut `nb` de l'objet
 * Fixed et retourne une référence à l'objet modifié.
 *
 * @return Fixed& Référence à l'objet après la décrémentation.
 */
Fixed Fixed::operator--()
{
	nb -= 1;
	return *this;
}

/**
 * @brief Décrémente la valeur de l'objet Fixed (postfixe).
 *
 * Effectue la décrémentation de la valeur interne de l'objet Fixed,
 * mais retourne d'abord une copie de l'objet avant la décrémentation.
 *
 * @param i Paramètre fictif nécessaire pour la surcharge postfixe.
 * @return Fixed& Référence à une copie de l'objet avant la décrémentation.
 */
Fixed Fixed::operator--(int)
{
	Fixed tmp = *this;
	nb -= 1;
	return tmp;
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
 * @brief Retourne la plus grande des deux valeurs de type Fixed (modifiable).
 *
 * Cette fonction compare deux objets `Fixed` et retourne le plus grand d'entre eux.
 * Les deux paramètres sont passés par référence, permettant de modifier directement
 * les objets.
 *
 * @param a Première valeur à comparer.
 * @param b Seconde valeur à comparer.
 * @return La plus grande des deux valeurs `Fixed`.
 */
Fixed& Fixed::max(Fixed& a, Fixed& b)
{
	if (a > b)
		return a;
	return b;
}

/**
 * @brief Retourne la plus grande des deux valeurs de type Fixed.
 *
 * Cette fonction compare deux objets `Fixed` et retourne le plus grand d'entre eux.
 *
 * @param a Première valeur à comparer.
 * @param b Seconde valeur à comparer.
 * @return La plus grande des deux valeurs `Fixed`.
 */
const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
	if (a > b)
		return a;
	return b;
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