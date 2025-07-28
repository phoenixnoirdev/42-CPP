
#include "../inc/Cat.hpp"

//==============================
// Consturcteur
//==============================

/**
 * @brief Constructeur par d�faut pour un objet Cat.
 *
 * Ce constructeur initialise un objet Cat en appelant le constructeur de la classe
 * de base Animal avec le type "Cat". Il cr�e �galement un objet Brain, lui attribue
 * des id�es � l'aide de la m�thode SetIdea(), et affiche des informations sur l'initialisation
 * du cerveau du chat en fonction de la langue d�finie.
 *
 * @note Le cerveau du chat (_Brain) est allou� dynamiquement, assurez-vous de lib�rer la m�moire
 *       dans le destructeur de la classe Cat pour �viter les fuites de m�moire.
 *
 * @see SetIdea()
 */
 Cat::Cat() : Animal("Cat")
 {
	 std::cout << GREEN << "CAT BRAIN" << RESET << " Initialization in " << LANG  << std::endl;
 
	 InitIdeaFr();
	 InitIdeaEng();
 
	 this->_Brain = new Brain();
	 SetIdea();
 
	 std::cout << GREEN << "CAT" << RESET << " Default constructor called" << std::endl;
 }


/**
 * @brief Constructeur par d�faut d'un objet `Cat` avec un nom sp�cifique.
 *
 * Ce constructeur initialise un objet `Cat` avec un nom pass� en param�tre.
 * Il appelle le constructeur de la classe de base `Animal` pour initialiser
 * le type de l'animal, puis cr�e un objet `Brain` pour ce chat. Apr�s
 * l'initialisation du cerveau, la m�thode `SetIdea()` est appel�e pour
 * d�finir les id�es du chat en fonction de la langue d�finie par la macro
 * `LANG`.
 *
 * @param str Le nom du chat � initialiser.
 *
 * @note Cette fonction affiche un message indiquant l'initialisation du
 *       cerveau du chat, en fonction de la langue (utilisation de la
 *       macro `LANG`), ainsi qu'un message de confirmation du constructeur
 *       par d�faut de `Cat`.
 */
Cat::Cat(std::string str) : Animal(str)
{
	std::cout << GREEN << "CAT BRAIN" << RESET << " Initialization in " << LANG << std::endl;
	this->_Brain = new Brain();
	SetIdea();

	std::cout << GREEN << "CAT" << RESET << " Default constructor called" << std::endl;
}

/**
 * @brief Constructeur de copie pour un objet `Cat`.
 *
 * Ce constructeur de copie initialise un nouvel objet `Cat` en copiant les
 * propri�t�s de l'objet `obj` pass� en param�tre. Le type de l'animal est
 * copi� depuis l'objet source, puis l'objet `Brain` est �galement copi�
 * de mani�re dynamique afin d'assurer une gestion correcte de la m�moire.
 * Avant d'effectuer la copie, l'ancien objet `Brain` est lib�r� pour �viter
 * les fuites de m�moire.
 *
 * @param obj L'objet `Cat` � copier.
 *
 * @note Cette fonction affiche un message indiquant l'appel du constructeur
 *       de copie pour un objet `Cat`.
 */

Cat::Cat(const Cat& obj)
{
	this->setType(obj.getType());
	
	this->_Brain = new Brain(*obj._Brain);

	std::cout << GREEN << "CAT" << RESET << " Copy constructor called" << std::endl;
}

/**
 * @brief Op�rateur d'assignation pour un objet `Cat`.
 *
 * Cet op�rateur permet d'assigner les valeurs d'un autre objet `Cat` � l'objet
 * courant. Si l'objet source n'est pas le m�me que l'objet courant, les
 * attributs `type` et `_Brain` sont copi�s. Avant la copie de `_Brain`, l'ancien
 * objet `Brain` est supprim� pour �viter les fuites de m�moire.
 *
 * @param obj L'objet `Cat` � copier dans l'objet courant.
 * @return L'objet courant apr�s l'assignation.
 *
 * @note Cette fonction affiche un message indiquant l'appel de l'op�rateur
 *       d'assignation pour un objet `Cat`.
 */
Cat& Cat::operator=(const Cat& obj)
{
	std::cout << GREEN << "CAT" << RESET << " Operator constructor call." << std::endl;
	if (this != &obj)
	{
		this->setType(obj.getType());
		delete this->_Brain;

		this->_Brain = new Brain(*obj._Brain);
	}
	return *this;
}

/**
 * @brief Destructeur pour l'objet `Cat`.
 *
 * Le destructeur lib�re la m�moire allou�e pour l'objet `_Brain`. Apr�s la
 * suppression de `_Brain`, un message est affich� indiquant que le destructeur
 * de l'objet `Cat` a �t� appel�.
 *
 * @note Cette m�thode supprime dynamiquement la m�moire allou�e pour l'attribut
 *       `_Brain` afin d'�viter les fuites de m�moire.
 */
Cat::~Cat()
{
	delete this->_Brain;

	std::cout << GREEN << "CAT" << RESET << " Destructor called." << std::endl;
}

//==============================
// Fonction
//==============================

/**
 * @brief Fait le bruit caract�ristique d'un chat.
 *
 * Cette m�thode affiche un message simulant le bruit d'un chat : "Miaou miaou".
 * Elle est appel�e lorsque l'on souhaite que l'objet Cat fasse un bruit sp�cifique.
 */
void Cat::makeSound() const
{
	std::cout << GREEN << "CAT" << RESET << " Miaou miaou." << std::endl;
}

/**
 * @brief D�finit les id�es du chat.
 *
 * Cette fonction initialise les id�es du chat en fonction de la langue d�finie
 * (fran�aise ou anglaise). Elle parcourt un tableau d'actions et les attribue
 * � l'�l�ment correspondant dans le cerveau du chat (_Brain).
 *
 * Si la langue est d�finie sur "FR", les id�es sont issues du tableau _FrCatActions.
 * Si la langue est d�finie sur "ENG", les id�es sont issues du tableau _EngCatActions.
 *
 * @note Cette fonction suppose que le tableau d'id�es et le cerveau (_Brain) sont correctement initialis�s.
 */
 void Cat::SetIdea()
 {
	 for (int i = 0; i <= 99; i++)
	 {
		 if (LANG == LANG_FR)
			 this->_Brain->SetIdea(_FrCatActions[i], i);
 
		 if (LANG == LANG_ENG)
			 this->_Brain->SetIdea(_EngCatActions[i], i);
	 }
 }

/**
 * @brief Affiche l'id�e du chat.
 *
 * Cette fonction appelle la m�thode GetIdea du cerveau du chat (_Brain) et lui
 * transmet le type du chat pour r�cup�rer et afficher l'id�e correspondante.
 *
 * @note Cette fonction suppose que le cerveau du chat (_Brain) est correctement initialis�.
 */
void Cat::Idea() const
{
	this->_Brain->GetIdea(this->getType());
}

/**
 * @brief Initialise les actions typiques d'un chat en français.
 * 
 * Cette fonction remplit le tableau `_FrCatActions` avec des comportements ou actions courants
 * que pourrait réaliser un chien, exprimés sous forme de phrases en français. Ces actions incluent
 * des comportements de jeu, de recherche de nourriture, de sommeil, de communication, et d'interaction
 * avec son propriétaire et son environnement.
 * 
 * @note Cette méthode est spécifiquement destinée à initialiser le tableau d'actions pour les chiens
 * avec des descriptions ludiques et adaptées à l'humour typique des comportements canins.
 */
 void Cat::InitIdeaFr()
 {
	 _FrCatActions[0] = "Se comporter comme un roi";
	 _FrCatActions[1] = "Faire semblant d'ignorer les humains";
	 _FrCatActions[2] = "Dormir toute la journee";
	 _FrCatActions[3] = "Griffer les meubles";
	 _FrCatActions[4] = "Jouer avec une boule de papier";
	 _FrCatActions[5] = "Poursuivre une souris imaginaire";
	 _FrCatActions[6] = "Se cacher dans une boite";
	 _FrCatActions[7] = "Renverser un verre d'eau";
	 _FrCatActions[8] = "Fixer un mur sans raison";
	 _FrCatActions[9] = "Marcher sur le clavier";
	 _FrCatActions[10] = "Se rouler en boule";
	 _FrCatActions[11] = "Se toiletter pendant des heures";
	 _FrCatActions[12] = "Miauler pour de la nourriture";
	 _FrCatActions[13] = "Refuser de manger apres avoir demande a manger";
	 _FrCatActions[14] = "Sauter sur les meubles";
	 _FrCatActions[15] = "Chasser une ombre";
	 _FrCatActions[16] = "Observer les oiseaux par la fenetre";
	 _FrCatActions[17] = "Se frotter contre les jambes";
	 _FrCatActions[18] = "Voler la place sur le canape";
	 _FrCatActions[19] = "Grimper aux rideaux";
	 _FrCatActions[20] = "Jouer avec un bouchon";
	 _FrCatActions[21] = "Se battre avec sa propre queue";
	 _FrCatActions[22] = "S'etirer comme un acrobate";
	 _FrCatActions[23] = "Ronronner tres fort";
	 _FrCatActions[24] = "Faire tomber des objets juste pour voir";
	 _FrCatActions[25] = "Refuser d'obeir";
	 _FrCatActions[26] = "Se cacher sous un meuble";
	 _FrCatActions[27] = "Dormir dans l'endroit le plus inconfortable";
	 _FrCatActions[28] = "Ignorer un jouet couteux";
	 _FrCatActions[29] = "Voler un bout de nourriture";
	 _FrCatActions[30] = "Faire semblant d'etre en detresse";
	 _FrCatActions[31] = "Reagir au laser avec frenesie";
	 _FrCatActions[32] = "Se coucher sur un livre ouvert";
	 _FrCatActions[33] = "Faire une sieste au soleil";
	 _FrCatActions[34] = "Miauler pour sortir, puis refuser de sortir";
	 _FrCatActions[35] = "Observer les humains avec dedain";
	 _FrCatActions[36] = "Se rouler sur le dos";
	 _FrCatActions[37] = "Etirer les griffes sur le tapis";
	 _FrCatActions[38] = "Se glisser dans un sac";
	 _FrCatActions[39] = "Boire l'eau d'un verre";
	 _FrCatActions[40] = "Regarder fixement un mur vide";
	 _FrCatActions[41] = "Faire semblant de ne pas entendre";
	 _FrCatActions[42] = "Donner un coup de patte a un autre animal";
	 _FrCatActions[43] = "Faire une course folle dans la maison";
	 _FrCatActions[44] = "Ignorer les ordres";
	 _FrCatActions[45] = "Dormir dans un tiroir";
	 _FrCatActions[46] = "Marcher lentement et majestueusement";
	 _FrCatActions[47] = "Faire semblant de chasser un insecte invisible";
	 _FrCatActions[48] = "Se laver apres avoir mange";
	 _FrCatActions[49] = "S'asseoir sur un objet interdit";
	 _FrCatActions[50] = "Taper sur un jouet en feignant l'ennui";
	 _FrCatActions[51] = "S'etirer sur toute la longueur du canape";
	 _FrCatActions[52] = "Etre trop fier pour demander de l'aide";
	 _FrCatActions[53] = "Se cacher dans un placard";
	 _FrCatActions[54] = "Regarder fixement son humain jusqu'a ce qu'il reagisse";
	 _FrCatActions[55] = "Miauler sans raison apparente";
	 _FrCatActions[56] = "Faire semblant d'etre interesse par quelque chose";
	 _FrCatActions[57] = "Ignorer un appel";
	 _FrCatActions[58] = "Faire une grimace etrange";
	 _FrCatActions[59] = "S'allonger sur un tapis et le revendiquer";
	 _FrCatActions[60] = "Declencher une zoomie soudaine";
	 _FrCatActions[61] = "Se battre avec un coussin";
	 _FrCatActions[62] = "Prendre la meilleure place du lit";
	 _FrCatActions[63] = "Agir comme s'il possedait la maison";
	 _FrCatActions[64] = "Se coucher sur un ordinateur portable chaud";
	 _FrCatActions[65] = "Faire semblant d'etre effraye";
	 _FrCatActions[66] = "Jouer avec un objet interdit";
	 _FrCatActions[67] = "Faire tomber quelque chose avec desinvolture";
	 _FrCatActions[68] = "Refuser d'etre caresse";
	 _FrCatActions[69] = "Se cacher derriere un rideau";
	 _FrCatActions[70] = "Jouer avec un insecte mort";
	 _FrCatActions[71] = "Rejeter un jouet qu'il adorait hier";
	 _FrCatActions[72] = "Faire semblant d'etre un ninja";
	 _FrCatActions[73] = "S'installer sur les genoux et partir soudainement";
	 _FrCatActions[74] = "Se cacher sous une couverture";
	 _FrCatActions[75] = "Fixer un point au plafond";
	 _FrCatActions[76] = "Donner un coup de patte a un humain sans raison";
	 _FrCatActions[77] = "Se toiletter avec exageration";
	 _FrCatActions[78] = "Faire un saut spectaculaire pour attraper une mouche";
	 _FrCatActions[79] = "Dormir dans la position la plus etrange";
	 _FrCatActions[80] = "Marcher entre les jambes d'un humain";
	 _FrCatActions[81] = "Ignorer un autre animal";
	 _FrCatActions[82] = "Rendre fou son humain avec ses caprices";
	 _FrCatActions[83] = "Declencher une bataille avec un jouet";
	 _FrCatActions[84] = "S'asseoir sur un coussin moelleux et le petrir";
	 _FrCatActions[85] = "S'approprier un panier qui n'est pas a lui";
	 _FrCatActions[86] = "Tenter de rentrer dans une boite trop petite";
	 _FrCatActions[87] = "Jouer avec une boule de laine";
	 _FrCatActions[88] = "Voler un vetement et dormir dessus";
	 _FrCatActions[89] = "Monter sur un meuble et observer le monde d'en haut";
	 _FrCatActions[90] = "Se faufiler dans un endroit interdit";
	 _FrCatActions[91] = "Faire semblant d'etre en embuscade";
	 _FrCatActions[92] = "Fixer son humain avec intensite";
	 _FrCatActions[93] = "Mettre la queue sous le nez d'un humain";
	 _FrCatActions[94] = "S'allonger dans le lavabo";
	 _FrCatActions[95] = "Se cacher dans une armoire ouverte";
	 _FrCatActions[96] = "Faire semblant d'avoir vu quelque chose de terrifiant";
	 _FrCatActions[97] = "Se comporter en petit prince";
	 _FrCatActions[98] = "Se rouler dans une couverture";
	 _FrCatActions[99] = "Faire la tete pendant des heures";
 }
 
 /**
  * @brief Initialise les actions typiques d'un chat en français.
  * 
  * Cette fonction remplit le tableau `_FrCatActions` avec des comportements ou actions courants
  * que pourrait réaliser un chien, exprimés sous forme de phrases en français. Ces actions incluent
  * des comportements de jeu, de recherche de nourriture, de sommeil, de communication, et d'interaction
  * avec son propriétaire et son environnement.
  * 
  * @note Cette méthode est spécifiquement destinée à initialiser le tableau d'actions pour les chiens
  * avec des descriptions ludiques et adaptées à l'humour typique des comportements canins.
  */
 void Cat::InitIdeaEng()
 {
	 _EngCatActions[0] = "Act like a king";
	 _EngCatActions[1] = "Pretend to ignore humans";
	 _EngCatActions[2] = "Sleep all day";
	 _EngCatActions[3] = "Scratch the furniture";
	 _EngCatActions[4] = "Play with a paper ball";
	 _EngCatActions[5] = "Chase an imaginary mouse";
	 _EngCatActions[6] = "Hide in a box";
	 _EngCatActions[7] = "Knock over a glass of water";
	 _EngCatActions[8] = "Stare at a wall for no reason";
	 _EngCatActions[9] = "Walk on the keyboard";
	 _EngCatActions[10] = "Curl up in a ball";
	 _EngCatActions[11] = "Groom for hours";
	 _EngCatActions[12] = "Meow for food";
	 _EngCatActions[13] = "Refuse to eat after asking for food";
	 _EngCatActions[14] = "Jump on the furniture";
	 _EngCatActions[15] = "Chase a shadow";
	 _EngCatActions[16] = "Watch birds through the window";
	 _EngCatActions[17] = "Rub against legs";
	 _EngCatActions[18] = "Steal the couch spot";
	 _EngCatActions[19] = "Climb the curtains";
	 _EngCatActions[20] = "Play with a bottle cap";
	 _EngCatActions[21] = "Fight with their own tail";
	 _EngCatActions[22] = "Stretch like an acrobat";
	 _EngCatActions[23] = "Purr very loudly";
	 _EngCatActions[24] = "Knock objects over just to see";
	 _EngCatActions[25] = "Refuse to obey";
	 _EngCatActions[26] = "Hide under furniture";
	 _EngCatActions[27] = "Sleep in the most uncomfortable place";
	 _EngCatActions[28] = "Ignore an expensive toy";
	 _EngCatActions[29] = "Steal a piece of food";
	 _EngCatActions[30] = "Pretend to be in distress";
	 _EngCatActions[31] = "React to the laser with frenzy";
	 _EngCatActions[32] = "Lie down on an open book";
	 _EngCatActions[33] = "Nap in the sun";
	 _EngCatActions[34] = "Meow to go outside, then refuse to go out";
	 _EngCatActions[35] = "Watch humans with disdain";
	 _EngCatActions[36] = "Roll over on their back";
	 _EngCatActions[37] = "Stretch claws on the carpet";
	 _EngCatActions[38] = "Sneak into a bag";
	 _EngCatActions[39] = "Drink water from a glass";
	 _EngCatActions[40] = "Stare at a blank wall";
	 _EngCatActions[41] = "Pretend not to hear";
	 _EngCatActions[42] = "Swat at another animal";
	 _EngCatActions[43] = "Run wildly around the house";
	 _EngCatActions[44] = "Ignore commands";
	 _EngCatActions[45] = "Sleep in a drawer";
	 _EngCatActions[46] = "Walk slowly and majestically";
	 _EngCatActions[47] = "Pretend to hunt an invisible insect";
	 _EngCatActions[48] = "Clean themselves after eating";
	 _EngCatActions[49] = "Sit on a forbidden object";
	 _EngCatActions[50] = "Tap a toy while pretending to be bored";
	 _EngCatActions[51] = "Stretch across the entire couch";
	 _EngCatActions[52] = "Be too proud to ask for help";
	 _EngCatActions[53] = "Hide in a closet";
	 _EngCatActions[54] = "Stare at their human until they react";
	 _EngCatActions[55] = "Meow for no apparent reason";
	 _EngCatActions[56] = "Pretend to be interested in something";
	 _EngCatActions[57] = "Ignore a call";
	 _EngCatActions[58] = "Make a strange face";
	 _EngCatActions[59] = "Lie down on a rug and claim it";
	 _EngCatActions[60] = "Trigger a sudden zoomie";
	 _EngCatActions[61] = "Fight with a pillow";
	 _EngCatActions[62] = "Take the best spot on the bed";
	 _EngCatActions[63] = "Act like they own the house";
	 _EngCatActions[64] = "Lie down on a warm laptop";
	 _EngCatActions[65] = "Pretend to be scared";
	 _EngCatActions[66] = "Play with a forbidden object";
	 _EngCatActions[67] = "Casually knock something over";
	 _EngCatActions[68] = "Refuse to be petted";
	 _EngCatActions[69] = "Hide behind a curtain";
	 _EngCatActions[70] = "Play with a dead bug";
	 _EngCatActions[71] = "Reject a toy they loved yesterday";
	 _EngCatActions[72] = "Pretend to be a ninja";
	 _EngCatActions[73] = "Sit on a lap and suddenly leave";
	 _EngCatActions[74] = "Hide under a blanket";
	 _EngCatActions[75] = "Stare at a spot on the ceiling";
	 _EngCatActions[76] = "Swat at a human for no reason";
	 _EngCatActions[77] = "Groom excessively";
	 _EngCatActions[78] = "Make a spectacular leap to catch a fly";
	 _EngCatActions[79] = "Sleep in the strangest position";
	 _EngCatActions[80] = "Walk between a human's legs";
	 _EngCatActions[81] = "Ignore another animal";
	 _EngCatActions[82] = "Drive their human crazy with their whims";
	 _EngCatActions[83] = "Start a battle with a toy";
	 _EngCatActions[84] = "Sit on a soft cushion and knead it";
	 _EngCatActions[85] = "Claim a basket that isn’t theirs";
	 _EngCatActions[86] = "Try to fit into a box that’s too small";
	 _EngCatActions[87] = "Play with a ball of yarn";
	 _EngCatActions[88] = "Steal a piece of clothing and sleep on it";
	 _EngCatActions[89] = "Climb on furniture and observe the world from above";
	 _EngCatActions[90] = "Sneak into a forbidden place";
	 _EngCatActions[91] = "Pretend to be in ambush";
	 _EngCatActions[92] = "Stare at their human intensely";
	 _EngCatActions[93] = "Put their tail under a human’s nose";
	 _EngCatActions[94] = "Lie down in the sink";
	 _EngCatActions[95] = "Hide in an open wardrobe";
	 _EngCatActions[96] = "Pretend to have seen something terrifying";
	 _EngCatActions[97] = "Act like a little prince";
	 _EngCatActions[98] = "Roll up in a blanket";
	 _EngCatActions[99] = "Sulking for hours";
 }