/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ScalarConverter.cpp								:+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: phkevin <phkevin@42luxembourg.lu>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2025/03/31 07:58:16 by phkevin		   #+#	#+#			 */
/*   Updated: 2025/03/31 07:58:16 by phkevin		  ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "ScalarConverter.hpp"

//==============================
// CONSTRUCTEUR
//==============================

/**
 * @brief Constructeur par défaut de ScalarConverter.
 *
 * Affiche un message indiquant que le constructeur par défaut est appelé.
 */
ScalarConverter::ScalarConverter()
{
	std::cout << GREEN << LOGO << RESET << "Default constructor called" << std::endl;
}

/**
 * @brief Constructeur par copie de ScalarConverter.
 *
 * Copie les données de l'objet donné et affiche un message indiquant
 * que le constructeur par copie est appelé.
 *
 * @param obj Référence de l'objet à copier.
 */
ScalarConverter::ScalarConverter(const ScalarConverter& obj)
{
	*this = obj;

	std::cout << GREEN << LOGO << RESET << "Copy constructor called" << std::endl;
}

/**
 * @brief Opérateur d'affectation pour ScalarConverter.
 *
 * Vérifie l'auto-affectation et copie les données de l'objet donné.
 * Affiche un message indiquant que l'opérateur d'affectation est appelé.
 *
 * @param obj Référence de l'objet à copier.
 * @return Référence vers l'objet assigné.
 */
ScalarConverter& ScalarConverter::operator=(const ScalarConverter& obj)
{
	if (this != &obj)
		*this = obj;

	std::cout << GREEN << LOGO << RESET << "Operator constructor called" << std::endl;

	return *this;
}

/**
 * @brief Destructeur de ScalarConverter.
 *
 * Affiche un message indiquant que le destructeur est appelé.
 */
ScalarConverter::~ScalarConverter()
{
	std::cout << GREEN << LOGO << RESET << "Destructor called" << std::endl;
}



//==============================
// FONCTION
//==============================

/**
 * @brief Convertit une chaîne de caractères en différents types scalaires.
 *
 * Cette fonction tente de convertir une chaîne donnée en `char`, `int`, `float`, et `double`.
 * Si la chaîne est un caractère non numérique unique, elle est directement convertie.
 * Sinon, la chaîne est analysée comme un nombre à virgule flottante (`double`)
 * à l'aide de `std::strtod`, puis convertie vers les autres types à l'aide des
 * fonctions membres `ConvChar`, `ConvInt`, `ConvDouble` et `ConvFloat`.
 *
 * @param str La chaîne à convertir.
 */
void ScalarConverter::convert(const std::string str)
{
	char* endptr;
	const double value = std::strtod(str.c_str(), &endptr);

	if (str.length() == 1 && !std::isdigit(str[0])) {
		char c = str[0];
		std::cout << "char: '" << c << "'" << std::endl;
		std::cout << "int: " << static_cast<int>(c) << std::endl;
		std::cout << "float: " << std::fixed << std::showpoint << std::setprecision(1) << static_cast<float>(c) << "f" << std::endl;
		std::cout << "double: " << std::fixed << std::showpoint << std::setprecision(1) << static_cast<double>(c) << std::endl;
		return;
	}

	ConvChar(value);
	ConvInt(value);
	ConvDouble(value);
	ConvFloat(value);
}

/**
 * @brief Convertit une valeur double en caractère affichable.
 *
 * Vérifie si la valeur est un caractère imprimable (32-126),
 * sinon indique qu'il est non affichable ou impossible.
 *
 * @param value La valeur à convertir en char.
 */
void ScalarConverter::ConvChar(double value)
{
	if (value >= 32 && value <= 126)
		std::cout << "char: '" << (char)value << "'" << std::endl;
	else if (value >= 0 && value <= 255)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: impossible" << std::endl;

}

/**
 * @brief Convertit une valeur double en entier.
 *
 * Vérifie si la valeur est dans les limites de int.
 * Sinon, affiche "impossible".
 *
 * @param value La valeur à convertir en int.
 */
void ScalarConverter::ConvInt(double value)
{
	if (value >= INT_MIN && value <= INT_MAX)
		std::cout << "int: " << (int)value << std::endl;
	else
		std::cout << "int: impossible" << std::endl;
}

/**
 * @brief Convertit une valeur en double et l'affiche.
 *
 * Affiche la valeur en notation fixe avec une précision
 * d'un chiffre après la virgule.
 *
 * @param value La valeur à convertir en double.
 */
void ScalarConverter::ConvDouble(double value)
{
	std::cout << "double: " << std::fixed << std::showpoint << std::setprecision(1) << value << std::endl;
}

/**
 * @brief Convertit une valeur en float et l'affiche.
 *
 * Affiche la valeur en notation fixe avec une précision
 * d'un chiffre après la virgule, suivie de 'f'.
 *
 * @param value La valeur à convertir en float.
 */
void ScalarConverter::ConvFloat(double value)
{
	std::cout << "float: " << std::fixed << std::showpoint << std::setprecision(1) << static_cast<float>(value) << "f" << std::endl;
}