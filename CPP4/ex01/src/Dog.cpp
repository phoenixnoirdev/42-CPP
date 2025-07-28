
#include "../inc/Dog.hpp"

//==============================
// Consturcteur
//==============================

/**
 * @brief Constructeur par d�faut pour l'objet `Dog`.
 *
 * Ce constructeur initialise l'objet `Dog` en appelant le constructeur
 * de la classe de base `Animal` avec le type "Dog". Ensuite, il alloue dynamiquement
 * de la m�moire pour l'attribut `_Brain` et initialise ses id�es en appelant
 * la m�thode `SetIdea()`. Un message est affich� indiquant que l'initialisation
 * du cerveau du chien s'est faite dans la langue sp�cifi�e par `LANG`.
 *
 * @note Cette m�thode initialise l'objet `Dog` et son cerveau avec des id�es
 *       sp�cifiques � la langue de l'application.
 */
Dog::Dog() : Animal("Dog")
{
	std::cout << GREEN << "DOG BRAIN" << RESET << " Initialization in " << LANG << std::endl;

	InitIdeaFr();
	InitIdeaEng();

	this->_Brain = new Brain();
	SetIdea();

	std::cout << GREEN << "DOG" << RESET << " Default constructor called" << std::endl;
}

/**
 * @brief Constructeur pour l'objet `Dog` avec un type personnalis�.
 *
 * Ce constructeur initialise l'objet `Dog` en appelant le constructeur de
 * la classe de base `Animal` avec un type sp�cifi� par la cha�ne de caract�res `str`.
 * Il alloue dynamiquement de la m�moire pour l'attribut `_Brain` et initialise ses id�es
 * en appelant la m�thode `SetIdea()`. Un message est affich� indiquant que l'initialisation
 * du cerveau du chien s'est faite dans la langue sp�cifi�e par `LANG`.
 *
 * @param str Le type de l'animal, pass� � la classe de base `Animal`.
 *
 * @note Cette m�thode permet d'initialiser un objet `Dog` avec un type sp�cifique et
 *       de d�finir un cerveau avec des id�es selon la langue de l'application.
 */
Dog::Dog(std::string str) : Animal(str)
{
	std::cout << GREEN << "DOG BRAIN" << RESET << " Initialization in " << LANG << std::endl;
	this->_Brain = new Brain();
	SetIdea();

	std::cout << GREEN << "DOG" << RESET << " Default constructor called" << std::endl;
}

/**
 * @brief Constructeur de copie pour l'objet `Dog`.
 *
 * Ce constructeur initialise un nouvel objet `Dog` en copiant les donn�es de l'objet `obj` pass�
 * en param�tre. Il copie le type de l'animal de `obj` et cr�e une nouvelle instance de `Brain`
 * en copiant celle de l'objet `obj`.
 * Un message est affich� pour indiquer que le constructeur de copie a �t� appel�.
 *
 * @param obj L'objet `Dog` � copier.
 *
 * @note Cette m�thode effectue une copie profonde du cerveau (`_Brain`) de l'objet `obj`.
 */
Dog::Dog(const Dog& obj)
{
	this->setType(obj.getType());

	this->_Brain = new Brain(*obj._Brain);

	std::cout << GREEN << "DOG" << RESET << " Copy constructor called" << std::endl;
}

/**
 * @brief Surcharge de l'op�rateur d'affectation pour l'objet `Dog`.
 *
 * Cette m�thode permet d'affecter les valeurs d'un autre objet `Dog` � l'objet courant.
 * Elle effectue une copie profonde des donn�es, en copiant le type de l'animal et en allouant
 * une nouvelle instance de `Brain` � partir de celle de l'objet `obj`.
 * Un message est affich� pour indiquer que l'op�rateur d'affectation a �t� appel�.
 *
 * @param obj L'objet `Dog` � affecter � l'objet courant.
 *
 * @return L'objet courant apr�s l'affectation.
 *
 * @note Cette m�thode effectue une copie profonde du cerveau (`_Brain`) de l'objet `obj`.
 */
Dog& Dog::operator=(const Dog& obj)
{
	std::cout << GREEN << "DOG" << RESET << " Operator constructor call." << std::endl;
	if (this != &obj)
	{
		this->setType(obj.getType());
		delete this->_Brain;

		this->_Brain = new Brain(*obj._Brain);
	}
	return *this;
}

/**
 * @brief Destructeur de la classe `Dog`.
 *
 * Cette m�thode est appel�e lorsque l'objet `Dog` est d�truit. Elle lib�re la m�moire
 * allou�e pour le cerveau (`_Brain`) de l'objet afin d'�viter les fuites de m�moire.
 * Un message est affich� pour indiquer que le destructeur de l'objet `Dog` a �t� appel�.
 */
Dog::~Dog()
{
	delete this->_Brain;



	std::cout << GREEN << "DOG" << RESET << " Destructor called." << std::endl;
}

//==============================
// Fonction
//==============================

/**
 * @brief Fait le bruit caract�ristique d'un chien.
 *
 * Cette m�thode affiche un message simulant le bruit d'un chien : "Wouf Wouf".
 * Elle est appel�e lorsque l'on souhaite que l'objet Dog fasse un bruit sp�cifique.
 */
void Dog::makeSound() const
{
	std::cout << GREEN << "DOG" << RESET << " Wouf Wouf." << std::endl;
}

/**
 * @brief D�finit les id�es pour le chien dans le cerveau.
 *
 * Cette m�thode initialise les id�es du chien en fonction de la langue d�finie dans
 * la variable `LANG`. Si la langue est le fran�ais, elle utilise le tableau d'actions
 * en fran�ais `_FrDogActions`, sinon elle utilise le tableau d'actions en anglais
 * `_EngDogActions`. Chaque id�e est assign�e � une position dans le cerveau du chien.
 */
void Dog::SetIdea()
{
	for (int i = 0; i <= 99; i++)
	{
		if (LANG == LANG_FR)
			this->_Brain->SetIdea(_FrDogActions[i], i);

		if (LANG == LANG_ENG)
			this->_Brain->SetIdea(_EngDogActions[i], i);
	}
}

/**
 * @brief Affiche l'id�e du chien � partir de son cerveau.
 *
 * Cette m�thode r�cup�re et affiche l'id�e associ�e au type du chien en appelant
 * la m�thode `GetIdea` du cerveau (`_Brain`) du chien, en utilisant le type du chien
 * comme param�tre.
 */
void Dog::Idea() const
{
	this->_Brain->GetIdea(this->getType());
}

/**
 * @brief Initialise les actions typiques d'un chien en français.
 * 
 * Cette fonction remplit le tableau `_FrDogActions` avec des comportements ou actions courants
 * que pourrait réaliser un chien, exprimés sous forme de phrases en français. Ces actions incluent
 * des comportements de jeu, de recherche de nourriture, de sommeil, de communication, et d'interaction
 * avec son propriétaire et son environnement.
 * 
 * @note Cette méthode est spécifiquement destinée à initialiser le tableau d'actions pour les chiens
 * avec des descriptions ludiques et adaptées à l'humour typique des comportements canins.
 */
void Dog::InitIdeaFr()
{
	_FrDogActions[0] = "Remuer la queue frenetiquement";
	_FrDogActions[1] = "Creuser un trou dans le jardin";
	_FrDogActions[2] = "Courir apres sa propre queue";
	_FrDogActions[3] = "Aboyer sur le facteur";
	_FrDogActions[4] = "Faire les yeux doux pour avoir une friandise";
	_FrDogActions[5] = "Se rouler dans quelque chose de malodorant";
	_FrDogActions[6] = "Faire semblant de ne pas entendre son maitre";
	_FrDogActions[7] = "Sauter de joie en voyant son humain rentrer";
	_FrDogActions[8] = "Renifler tout ce qui passe";
	_FrDogActions[9] = "Enterrer un os et l'oublier";
	_FrDogActions[10] = "Courir apres une balle sans se fatiguer";
	_FrDogActions[11] = "Se coucher en travers du canape";
	_FrDogActions[12] = "Boire bruyamment";
	_FrDogActions[13] = "Manger trop vite puis regretter";
	_FrDogActions[14] = "Tirer sur la laisse lors de la promenade";
	_FrDogActions[15] = "Essayer de poursuivre une voiture";
	_FrDogActions[16] = "Jouer avec une vieille chaussette";
	_FrDogActions[17] = "Faire semblant de ne pas comprendre un ordre";
	_FrDogActions[18] = "Dormir dans la position la plus etrange";
	_FrDogActions[19] = "Rever en remuant les pattes";
	_FrDogActions[20] = "Lecher tout ce qui bouge";
	_FrDogActions[21] = "Faire une sieste au soleil";
	_FrDogActions[22] = "Se cacher derriere un meuble pendant un orage";
	_FrDogActions[23] = "Avoir peur de son propre reflet";
	_FrDogActions[24] = "Ramener un jouet encore et encore";
	_FrDogActions[25] = "Reclamer des calins a tout le monde";
	_FrDogActions[26] = "Courir partout apres le bain";
	_FrDogActions[27] = "Essayer de grimper sur les genoux de son humain";
	_FrDogActions[28] = "Faire semblant d'etre un chien de garde";
	_FrDogActions[29] = "S'asseoir sur les pieds de son humain";
	_FrDogActions[30] = "Se rouler dans l'herbe avec bonheur";
	_FrDogActions[31] = "Renverser son bol d'eau par accident";
	_FrDogActions[32] = "Faire une course folle dans la maison";
	_FrDogActions[33] = "Pousser son humain pour reclamer de l'attention";
	_FrDogActions[34] = "Mettre sa truffe partout";
	_FrDogActions[35] = "S'asseoir a cote de la table pendant un repas";
	_FrDogActions[36] = "Faire le mort pour obtenir une recompense";
	_FrDogActions[37] = "Aboyer sur un objet inanime";
	_FrDogActions[38] = "Tenter de voler de la nourriture discretement";
	_FrDogActions[39] = "Regarder son humain avec admiration";
	_FrDogActions[40] = "Pousser un autre animal pour avoir plus de place";
	_FrDogActions[41] = "Se rouler sur le dos pour demander des caresses";
	_FrDogActions[42] = "Montrer son ventre en signe de soumission";
	_FrDogActions[43] = "Essayer de parler en gemissant";
	_FrDogActions[44] = "Etre obsesse par une odeur sur le trottoir";
	_FrDogActions[45] = "Se coucher en plein milieu du passage";
	_FrDogActions[46] = "Chercher un baton plus grand que lui";
	_FrDogActions[47] = "Oublier pourquoi il a aboye";
	_FrDogActions[48] = "Se coller contre son humain en dormant";
	_FrDogActions[49] = "Sauter dans une flaque d'eau avec enthousiasme";
	_FrDogActions[50] = "Poursuivre un papillon sans jamais l'attraper";
	_FrDogActions[51] = "Se cacher sous une table quand il a fait une betise";
	_FrDogActions[52] = "Voler la place de son humain sur le canape";
	_FrDogActions[53] = "Faire la fete comme si chaque retour etait une eternite";
	_FrDogActions[54] = "Attraper une mouche au vol";
	_FrDogActions[55] = "Attendre devant la porte avant meme qu'elle ne s'ouvre";
	_FrDogActions[56] = "Se coucher en travers de l'entree";
	_FrDogActions[57] = "Donner un coup de patte pour attirer l'attention";
	_FrDogActions[58] = "Essayer d'attraper un poisson dans un aquarium";
	_FrDogActions[59] = "Regarder son humain avec insistance pour demander une friandise";
	_FrDogActions[60] = "Chasser une feuille morte comme si c'etait une proie";
	_FrDogActions[61] = "Se cacher sous un coussin en pensant etre invisible";
	_FrDogActions[62] = "S'endormir dans une position bizarre";
	_FrDogActions[63] = "Montrer une fidelite sans faille";
	_FrDogActions[64] = "Se precipiter pour dire bonjour a tout le monde";
	_FrDogActions[65] = "Lecher le visage de son humain avec exces";
	_FrDogActions[66] = "Tenter d'intimider un aspirateur";
	_FrDogActions[67] = "Se coller a la fenetre en attendant son humain";
	_FrDogActions[68] = "Refuser de bouger pendant la promenade";
	_FrDogActions[69] = "Apporter son jouet prefere en cadeau";
	_FrDogActions[70] = "Chasser sa propre ombre";
	_FrDogActions[71] = "Regarder fixement une porte en attendant qu'elle s'ouvre";
	_FrDogActions[72] = "Faire semblant d'etre triste pour obtenir plus d'attention";
	_FrDogActions[73] = "Jouer dans la boue sans le moindre remords";
	_FrDogActions[74] = "Secouer la tete avec ses oreilles qui volent";
	_FrDogActions[75] = "S'asseoir parfaitement droit pour paraitre sage";
	_FrDogActions[76] = "Faire une sieste en ronflant bruyamment";
	_FrDogActions[77] = "Ressortir la meme chaussette cachee trois jours plus tot";
	_FrDogActions[78] = "S'endormir sur son humain sans prevenir";
	_FrDogActions[79] = "Se cacher derriere son humain face a un danger inconnu";
	_FrDogActions[80] = "Renverser quelque chose avec sa queue sans s'en rendre compte";
	_FrDogActions[81] = "Boire a une flaque au lieu de son bol d'eau propre";
	_FrDogActions[82] = "Courir apres un autre chien en pensant etre plus rapide";
	_FrDogActions[83] = "Faire semblant de ne pas entendre son nom";
	_FrDogActions[84] = "Se faufiler sous une couverture pour dormir au chaud";
	_FrDogActions[85] = "Sauter sur son humain en oubliant sa taille";
	_FrDogActions[86] = "Chiper un coussin et le machouiller discretement";
	_FrDogActions[87] = "Fixer son humain jusqu'a obtenir un calin";
	_FrDogActions[88] = "Etre excite a l'idee d'aller a la plage";
	_FrDogActions[89] = "Se rouler dans le sable comme si c'etait le paradis";
	_FrDogActions[90] = "Rentrer dans une piece comme si c'etait une mission secrete";
	_FrDogActions[91] = "Marcher en zigzag pendant la promenade";
	_FrDogActions[92] = "Etre jaloux quand un autre animal est caline";
	_FrDogActions[93] = "Regarder la tele en semblant comprendre";
	_FrDogActions[94] = "Attraper une peluche et ne plus jamais la lacher";
	_FrDogActions[95] = "Agir comme un chiot meme en etant adulte";
	_FrDogActions[96] = "Etre toujours pret pour une aventure";
	_FrDogActions[97] = "Faire la tete quand il ne peut pas aller dehors";
	_FrDogActions[98] = "Renifler une borne a incendie";
	_FrDogActions[99] = "Chercher un os";
}

/**
 * @brief Initialise les actions typiques d'un chien en Anglais.
 * 
 * Cette fonction remplit le tableau `_EngDogActions` avec des comportements ou actions courants
 * que pourrait réaliser un chien, exprimés sous forme de phrases en français. Ces actions incluent
 * des comportements de jeu, de recherche de nourriture, de sommeil, de communication, et d'interaction
 * avec son propriétaire et son environnement.
 * 
 * @note Cette méthode est spécifiquement destinée à initialiser le tableau d'actions pour les chiens
 * avec des descriptions ludiques et adaptées à l'humour typique des comportements canins.
 */
void Dog::InitIdeaEng()
{
	_EngDogActions[0] = "Wagging the tail frantically";
	_EngDogActions[1] = "Digging a hole in the garden";
	_EngDogActions[2] = "Chasing its own tail";
	_EngDogActions[3] = "Barking at the mailman";
	_EngDogActions[4] = "Making puppy eyes to get a treat";
	_EngDogActions[5] = "Rolling in something smelly";
	_EngDogActions[6] = "Pretending not to hear its owner";
	_EngDogActions[7] = "Jumping for joy when its human comes home";
	_EngDogActions[8] = "Sniffing everything that passes by";
	_EngDogActions[9] = "Burying a bone and forgetting about it";
	_EngDogActions[10] = "Chasing a ball without getting tired";
	_EngDogActions[11] = "Lying across the couch";
	_EngDogActions[12] = "Drinking noisily";
	_EngDogActions[13] = "Eating too quickly then regretting it";
	_EngDogActions[14] = "Pulling on the leash during walks";
	_EngDogActions[15] = "Trying to chase a car";
	_EngDogActions[16] = "Playing with an old sock";
	_EngDogActions[17] = "Pretending not to understand a command";
	_EngDogActions[18] = "Sleeping in the strangest position";
	_EngDogActions[19] = "Dreaming while moving its paws";
	_EngDogActions[20] = "Licking everything that moves";
	_EngDogActions[21] = "Taking a nap in the sun";
	_EngDogActions[22] = "Hiding behind a piece of furniture during a storm";
	_EngDogActions[23] = "Being afraid of its own reflection";
	_EngDogActions[24] = "Bringing a toy back over and over";
	_EngDogActions[25] = "Demanding cuddles from everyone";
	_EngDogActions[26] = "Running around the house after a bath";
	_EngDogActions[27] = "Trying to climb onto its human’s lap";
	_EngDogActions[28] = "Pretending to be a guard dog";
	_EngDogActions[29] = "Sitting on its human’s feet";
	_EngDogActions[30] = "Rolling in the grass with joy";
	_EngDogActions[31] = "Knocking over its water bowl by accident";
	_EngDogActions[32] = "Having a crazy run around the house";
	_EngDogActions[33] = "Pushing its human to get attention";
	_EngDogActions[34] = "Putting its nose everywhere";
	_EngDogActions[35] = "Sitting next to the table during a meal";
	_EngDogActions[36] = "Playing dead to get a reward";
	_EngDogActions[37] = "Barking at an inanimate object";
	_EngDogActions[38] = "Trying to sneak food";
	_EngDogActions[39] = "Looking at its human with admiration";
	_EngDogActions[40] = "Pushing another animal for more space";
	_EngDogActions[41] = "Rolling on its back to ask for belly rubs";
	_EngDogActions[42] = "Showing its belly as a sign of submission";
	_EngDogActions[43] = "Trying to talk by whining";
	_EngDogActions[44] = "Being obsessed with a smell on the sidewalk";
	_EngDogActions[45] = "Lying in the middle of the way";
	_EngDogActions[46] = "Looking for a stick bigger than itself";
	_EngDogActions[47] = "Forgetting why it barked";
	_EngDogActions[48] = "Cuddling up to its human while sleeping";
	_EngDogActions[49] = "Jumping into a puddle with excitement";
	_EngDogActions[50] = "Chasing a butterfly without ever catching it";
	_EngDogActions[51] = "Hiding under a table when it’s done something wrong";
	_EngDogActions[52] = "Stealing its human’s spot on the couch";
	_EngDogActions[53] = "Celebrating like every return is an eternity";
	_EngDogActions[54] = "Catching a fly mid-air";
	_EngDogActions[55] = "Waiting at the door before it even opens";
	_EngDogActions[56] = "Lying across the doorway";
	_EngDogActions[57] = "Giving a paw to get attention";
	_EngDogActions[58] = "Trying to catch a fish in an aquarium";
	_EngDogActions[59] = "Staring at its human insistently to get a treat";
	_EngDogActions[60] = "Chasing a falling leaf like it’s prey";
	_EngDogActions[61] = "Hiding under a cushion thinking it’s invisible";
	_EngDogActions[62] = "Falling asleep in a weird position";
	_EngDogActions[63] = "Showing unwavering loyalty";
	_EngDogActions[64] = "Rushing to say hello to everyone";
	_EngDogActions[65] = "Licking its human’s face excessively";
	_EngDogActions[66] = "Trying to intimidate a vacuum cleaner";
	_EngDogActions[67] = "Pressing against the window waiting for its human";
	_EngDogActions[68] = "Refusing to move during a walk";
	_EngDogActions[69] = "Bringing its favorite toy as a gift";
	_EngDogActions[70] = "Chasing its own shadow";
	_EngDogActions[71] = "Staring at a door waiting for it to open";
	_EngDogActions[72] = "Pretending to be sad to get more attention";
	_EngDogActions[73] = "Playing in the mud without a care";
	_EngDogActions[74] = "Shaking its head with flying ears";
	_EngDogActions[75] = "Sitting perfectly straight to look wise";
	_EngDogActions[76] = "Taking a nap while snoring loudly";
	_EngDogActions[77] = "Bringing out the same sock hidden three days ago";
	_EngDogActions[78] = "Falling asleep on its human without warning";
	_EngDogActions[79] = "Hiding behind its human when facing an unknown danger";
	_EngDogActions[80] = "Knocking something over with its tail without realizing it";
	_EngDogActions[81] = "Drinking from a puddle instead of its clean water bowl";
	_EngDogActions[82] = "Chasing another dog thinking it’s faster";
	_EngDogActions[83] = "Pretending not to hear its name";
	_EngDogActions[84] = "Sneaking under a blanket to sleep warm";
	_EngDogActions[85] = "Jumping on its human forgetting its size";
	_EngDogActions[86] = "Snatching a cushion and chewing on it secretly";
	_EngDogActions[87] = "Staring at its human until it gets a cuddle";
	_EngDogActions[88] = "Being excited about going to the beach";
	_EngDogActions[89] = "Rolling in the sand like it’s paradise";
	_EngDogActions[90] = "Entering a room like it’s a secret mission";
	_EngDogActions[91] = "Walking in zigzags during walks";
	_EngDogActions[92] = "Getting jealous when another animal is getting cuddles";
	_EngDogActions[93] = "Watching TV as if it understands";
	_EngDogActions[94] = "Catching a plush toy and never letting go";
	_EngDogActions[95] = "Acting like a puppy even when grown up";
	_EngDogActions[96] = "Always ready for an adventure";
	_EngDogActions[97] = "Pouting when it can’t go outside";
	_EngDogActions[98] = "Sniffing a fire hydrant";
	_EngDogActions[99] = "Find a bone";
}