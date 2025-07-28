#include <iostream>
#include "../inc/Cat.hpp"
#include "../inc/Dog.hpp"
#include "../inc/WrongCat.hpp"

/**
 * @brief Affiche plusieurs lignes vides dans la console.
 *
 * @param nb Nombre de lignes vides à afficher.
 */
void lBreak(int nb)
{
    for (int i = 0; i < nb; ++i)
        std::cout << std::endl;
}

/**
 * @brief Affiche un séparateur formaté avec un titre centré.
 *
 * @param str Texte à afficher au centre du séparateur.
 */
void separator(std::string str)
{
    lBreak(2);
    std::cout << YELLOW << "------------------------------------" << RESET << std::endl;
    std::cout << YELLOW << str << RESET << std::endl;
    std::cout << YELLOW << "------------------------------------" << RESET << std::endl;
    lBreak(2);
}

int main()
{
    //==============================
    // ANIMAL TEST
    //==============================

    separator("ANIMAL TEST");

    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    lBreak(1);

    std::cout << "I am a type animal: " << GREEN << meta->getType() << RESET << std::endl;
    std::cout << "I am a type animal: " << GREEN << i->getType() << RESET << std::endl;
    std::cout << "I am a type animal: " << GREEN << j->getType() << RESET << std::endl;

    lBreak(1);

    i->makeSound();
    j->makeSound();
    meta->makeSound();

    lBreak(1);


    //==============================
    // TEST POLYMORPH LISTE
    //==============================

    separator("TEST POLYMORPH LISTE");

	Animal* animals[2];
	animals[0] = new Dog();
	animals[1] = new Cat();

	std::cout << "Animal[0] makeSound(): ";
	animals[0]->makeSound();
	std::cout << "Animal[1] makeSound(): ";
	animals[1]->makeSound();

    lBreak(1);



	delete animals[0];
	delete animals[1];
    delete meta;
    delete j;
    delete i;

    //==============================
    // WRONG TEST
    //==============================

    separator("WRONGANIMAL TEST");


    const WrongAnimal* meta2 = new WrongAnimal();
    const WrongAnimal* ii = new WrongCat();

    lBreak(1);

    std::cout << "I am a type animal: " << GREEN << meta2->getType() << RESET << std::endl;
    std::cout << "I am a type animal: " << GREEN << ii->getType() << RESET << std::endl;

    lBreak(1);

    ii->makeSound();
    meta2->makeSound();

    lBreak(1);


    delete meta2;
    delete ii;


    //==============================
    // BRAIN TEST
    //==============================

    separator("BRAIN TEST");

    const Animal* jbrain = new Dog();
    const Animal* ibrain = new Cat();

    lBreak(1);

    for (int i = 0; i < 10; i++)
        jbrain->Idea();


    lBreak(1);

    for (int i = 0; i < 10; i++)
        ibrain->Idea();

    lBreak(1);

    //==============================
    // TEST POLYMORPH BRAIN LISTE
    //==============================

    separator("TEST POLYMORPH BRAIN LISTE");

	Animal* animalss[2];
	animalss[0] = new Dog();
	animalss[1] = new Cat();

	std::cout << "Animal[0] idea): ";
	animalss[0]->Idea();
	std::cout << "Animal[1] idea: ";
	animalss[1]->Idea();

    lBreak(1);


    //==============================
    // TEST COPY DOG TO DOG AND CAT TO CAT
    //==============================

    separator("TEST COPY DOG TO DOG AND CAT TO CAT");
	
    Dog dog1;
    Dog dog2;
	dog2 = dog1;

	Cat cat1;
    Cat Cat2;
	Cat2 = cat1;

    lBreak(1);


    delete animalss[0];
	delete animalss[1];

    delete jbrain;
    delete ibrain;

    return 0;
}
