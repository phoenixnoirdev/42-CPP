
#include "../inc/Brain.hpp"

//==============================
// Consturcteur
//==============================

/**
 * @brief Constructeur par d�faut de la classe Brain.
 *
 * Ce constructeur initialise un objet de type `Brain` en affichant un message de
 * d�bogage pour indiquer que le constructeur par d�faut de la classe `Brain` a �t� appel�.
 */
Brain::Brain()
{
	std::cout << GREEN << "BRAIN" << RESET << " Default constructor called" << std::endl;
}

/**
 * @brief Constructeur de copie de la classe Brain.
 *
 * Ce constructeur cr�e une copie d'un objet `Brain` en dupliquant les id�es
 * contenues dans l'objet source. Il utilise l'op�rateur d'assignation pour
 * effectuer la copie et initialise chaque �l�ment du tableau `_idea` avec les
 * valeurs correspondantes de l'objet source.
 *
 * @param obj L'objet `Brain` � copier.
 */
Brain::Brain(const Brain& obj)
{
	*this = obj;
	for (int i = 0; i < IDEANB; i++)
		this->_idea[i] = obj._idea[i];

	std::cout << GREEN << "BRAIN" << RESET << " Copy constructor called" << std::endl;
}

/**
 * @brief Op�rateur d'assignation de la classe Brain.
 *
 * Cet op�rateur assigne les valeurs d'un autre objet `Brain` � l'objet
 * courant. Si l'objet source n'est pas l'objet courant, il duplique les
 * valeurs contenues dans `_idea` et effectue une copie compl�te de l'objet
 * source dans l'objet actuel.
 *
 * @param obj L'objet `Brain` � copier dans l'objet courant.
 * @return L'objet courant apr�s l'assignation.
 */
Brain& Brain::operator=(const Brain& obj)
{
	std::cout << GREEN << "BRAIN" << RESET << " Operator constructor call." << std::endl;
	if (this != &obj)
	{
		for (int i = 0; i < IDEANB; i++)
			this->_idea[i] = obj._idea[i];
	}
	return *this;
}

/**
 * @brief Destructeur de la classe Brain.
 *
 * Affiche un message lorsque l'objet Brain est d�truit.
 */
Brain::~Brain()
{
	std::cout << GREEN << "BRAIN" << RESET << " Destructor called." << std::endl;
}

//==============================
// Fonction
//==============================

/**
 * @brief D�finit une id�e dans le cerveau � un index sp�cifique.
 *
 * Cette fonction assigne une id�e (une cha�ne de caract�res) � une position
 * sp�cifique dans le tableau `_idea`. Elle utilise l'index `ref` pour
 * placer l'id�e dans la bonne case du tableau.
 *
 * De plus, elle initialise le g�n�rateur de nombres al�atoires en fonction
 * de l'heure actuelle pour garantir que la g�n�ration de nombres al�atoires
 * est unique � chaque ex�cution.
 *
 * @param str La cha�ne de caract�res repr�sentant l'id�e � stocker.
 * @param ref L'index dans le tableau `_idea` o� l'id�e sera enregistr�e.
 */
void Brain::SetIdea(std::string str, int ref)
{
	_idea[ref] = str;
	
	std::srand(static_cast<unsigned int>(std::time(0)));
}

/**
 * @brief Affiche la liste des id�es stock�es dans le cerveau.
 *
 * Cette fonction parcourt le tableau `_idea` et affiche chaque id�e avec son
 * index correspondant dans la sortie standard. Chaque id�e est pr�fix�e par
 * un message indiquant son index et son contenu, en utilisant une coloration
 * sp�cifique pour chaque partie du message.
 *
 * Cette m�thode est principalement utilis�e pour d�boguer et v�rifier les
 * id�es stock�es dans le cerveau.
 */
void Brain::GetListeIdea()
{
	for (int i = 0; i < IDEANB; i++)
		std::cout << GREEN << "BRAIN" << RESET << " idea  " << GREEN << i << RESET << " set: " << YELLOW << _idea[i] << RESET << std::endl;
}

/**
 * @brief Affiche une id�e al�atoire du cerveau selon le type d'animal.
 *
 * Cette fonction s�lectionne un index al�atoire dans le tableau `_idea` et affiche
 * l'id�e correspondante � cet index. Le message affich� inclut le type d'animal
 * ainsi que l'index de l'id�e et son contenu. L'index est g�n�r� de mani�re al�atoire
 * � chaque appel de la fonction.
 *
 * @param type Type d'animal (par exemple, "Cat" ou "Dog") qui est affich� dans le message.
 */
void Brain::GetIdea(std::string type)
{
	int randomIndex = rand() % (sizeof(_idea) / sizeof(_idea[0]));

	std::cout << GREEN << type << RESET << " idea = " GREEN << randomIndex  << RESET << " - " << YELLOW << _idea[randomIndex] << RESET << std::endl;
}