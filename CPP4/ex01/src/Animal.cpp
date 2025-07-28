
#include "../inc/Animal.hpp"

//==============================
// Consturcteur
//==============================

/**
 * @brief Constructeur par d�faut de la classe Animal.
 *
 * Initialise le type par d�faut � "Animal" et affiche un message de cr�ation.
 */
Animal::Animal()
{
	this->type = "Animal";

	std::cout << GREEN << "ANIMAL" << RESET << " Default constructor called" << std::endl;
}

/**
 * @brief Constructeur param�tr� de la classe Animal.
 *
 * @param str Type de l'animal.
 * Initialise le type de l'animal avec la valeur fournie et affiche un message de cr�ation.
 */
Animal::Animal(std::string str)
{
	this->setType(str);

	std::cout << GREEN << "ANIMAL" << RESET << " Default constructor called for Type " << GREEN << this->getType() << RESET << std::endl;
}

/**
 * @brief Constructeur de copie de la classe Animal.
 *
 * @param obj Objet Animal � copier.
 * Copie le type de l'animal donn� en param�tre et affiche un message de copie.
 */
Animal::Animal(const Animal& obj)
{
	this->setType(obj.type);

	std::cout << GREEN << "ANIMAL" << RESET << " Copy constructor called" << std::endl;
}

/**
 * @brief Surcharge de l'op�rateur d'affectation pour la classe Animal.
 *
 * @param obj Objet Animal � copier.
 * @return R�f�rence vers l'objet Animal assign�.
 * V�rifie l'auto-affectation, copie le type et affiche un message de confirmation.
 */
Animal& Animal::operator=(const Animal& obj)
{
	std::cout << GREEN << "ANIMAL" << RESET << " Operator constructor call." << std::endl;
	if (this != &obj)
		this->setType(obj.type);
	return *this;
}

/**
 * @brief Destructeur de la classe Animal.
 *
 * Affiche un message lorsque l'objet Animal est d�truit.
 */
Animal::~Animal()
{
	std::cout << GREEN << "ANIMAL" << RESET << " Destructor called." << std::endl;
}

//==============================
// Fonction
//==============================

/**
 * @brief D�finit le type de l'animal.
 *
 * @param str Le type � attribuer � l'animal.
 */
void Animal::setType(std::string str)
{
	this->type = str;
}

/**
 * @brief R�cup�re le type de l'animal.
 *
 * @return std::string Le type de l'animal.
 */
std::string  Animal::getType() const
{
	return this->type;
}

/**
 * @brief Fait le son de l'animal.
 *
 * Cette fonction affiche un message indiquant que l'animal est un animal g�n�rique.
 */
void Animal::makeSound() const
{
	std::cout << GREEN << "ANIMAL" << RESET << " I am an animal." << std::endl;
}

/**
 * @brief Affiche une id�e g�n�rale de l'animal.
 *
 * Cette m�thode affiche un message indiquant une pens�e abstraite d'un animal.
 */
void Animal::Idea() const
{
	std::cout << GREEN << "ANIMAL" << RESET << " I am an animal idea." << std::endl;
}