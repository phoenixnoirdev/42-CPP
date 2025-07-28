
#include "../inc/WrongAnimal.hpp"

//==============================
// Consturcteur
//==============================

/**
 * @brief Constructeur par d�faut de la classe WrongAnimal.
 *
 * Ce constructeur appelle le constructeur par d�faut de la classe Animal en lui passant "WrongAnimal" comme type.
 * Affiche un message indiquant que le constructeur par d�faut de la classe WrongAnimal a �t� appel�.
 */
WrongAnimal::WrongAnimal()
{
	this->type = "WrongAnimal";

	std::cout << GREEN << "WRONG-ANIMAL" << RESET << " Default constructor called" << std::endl;
}

/**
 * @brief Constructeur de la classe WrongAnimal avec un type personnalis�.
 *
 * Ce constructeur appelle le constructeur de la classe Animal avec le type pass� en param�tre.
 * Affiche un message indiquant que le constructeur de la classe WrongAnimal a �t� appel�.
 *
 * @param str Le type de l'animal (en l'occurrence "WrongAnimal").
 */
WrongAnimal::WrongAnimal(std::string str)
{
	this->setType(str);

	std::cout << GREEN << "WRONG-ANIMAL" << RESET << " Default constructor called for Type " << GREEN << this->getType() << RESET << std::endl;
}

/**
 * @brief Constructeur de copie de la classe WrongAnimal.
 *
 * Ce constructeur cr�e un nouvel objet WrongAnimal en copiant les informations d'un autre objet WrongAnimal.
 * Il appelle la m�thode `setType` pour d�finir le type de l'animal.
 * Affiche un message indiquant que le constructeur de copie de la classe WrongAnimal a �t� appel�.
 *
 * @param obj L'objet WrongAnimal � copier.
 */
WrongAnimal::WrongAnimal(const WrongAnimal& obj)
{
	this->setType(obj.type);

	std::cout << GREEN << "WRONG-ANIMAL" << RESET << " Copy constructor called" << std::endl;
}

/**
 * @brief Surcharge de l'op�rateur d'affectation de la classe WrongAnimal.
 *
 * Cet op�rateur permet d'affecter un objet WrongAnimal � un autre objet WrongAnimal. Il copie les informations de l'objet source
 * dans l'objet actuel et v�rifie que l'objet � affecter n'est pas lui-m�me.
 * Affiche un message indiquant que l'op�rateur d'affectation de la classe WrongAnimal a �t� appel�.
 *
 * @param obj L'objet WrongAnimal � affecter � l'objet actuel.
 * @return Un objet WrongAnimal apr�s l'affectation.
 */
WrongAnimal& WrongAnimal::operator=(const WrongAnimal& obj)
{
	std::cout << GREEN << "WRONG-ANIMAL" << RESET << " Operator constructor call." << std::endl;
	if (this != &obj)
		this->setType(obj.type);
	return *this;
}

/**
 * @brief Destructeur de la classe WrongAnimal.
 *
 * Le destructeur est appel� lors de la destruction d'un objet de la classe WrongAnimal.
 * Il affiche un message indiquant que le destructeur de la classe WrongAnimal a �t� appel�.
 */

WrongAnimal::~WrongAnimal()
{
	std::cout << GREEN << "WRONG-ANIMAL" << RESET << " Destructor called." << std::endl;
}

//==============================
// Fonction
//==============================

/**
 * @brief D�finit le type de l'animal.
 *
 * Cette m�thode permet de modifier le type de l'animal en assignant une nouvelle valeur � l'attribut `type`.
 *
 * @param str La nouvelle valeur pour l'attribut `type` de l'animal.
 */
void WrongAnimal::setType(std::string str)
{
	this->type = str;
}

/**
 * @brief Obtient le type de l'animal.
 *
 * Cette m�thode retourne le type actuel de l'animal, qui est stock� dans l'attribut `type`.
 *
 * @return Le type de l'animal sous forme de cha�ne de caract�res.
 */
std::string  WrongAnimal::getType() const
{
	return this->type;
}

/**
 * @brief Produit le son d'un mauvais animal.
 *
 * Cette m�thode affiche un message indiquant que c'est un "Wrong-Animal" et qu'il fait un bruit g�n�rique.
 */
void WrongAnimal::makeSound() const
{
	std::cout << GREEN << "WRONG-ANIMAL" << RESET << " Je suis un Animal." << std::endl;
}