/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phkevin <phkevin@42luxembourg.lu>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 09:39:33 by phkevin           #+#    #+#             */
/*   Updated: 2025/03/21 09:39:33 by phkevin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Param.hpp"
#include "../inc/Character.hpp"
#include "../inc/Cure.hpp"
#include "../inc/Ice.hpp"
#include "../inc/MateriaSource.hpp"

/**
 * @brief Affiche plusieurs lignes vides dans la console.
 *
 * @param nb Nombre de lignes vides � afficher.
 */
void lBreak(int nb)
{
    for (int i = 0; i < nb; ++i)
        std::cout << std::endl;
}

/**
 * @brief Affiche un s�parateur format� avec un titre centr�.
 *
 * @param str Texte � afficher au centre du s�parateur.
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
    // BASE TEST
    //==============================

    separator("BASE TEST");

    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    ICharacter* me = new Character("me");
    AMateria* tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);

    ICharacter* bob = new Character("bob");

    me->use(0, *bob);
    me->use(1, *bob);

    lBreak(3);

    delete bob;
    delete me;
    delete src;
    
    lBreak(3);


    //==============================
    // CUSTOM TEST
    //==============================

    separator("TEST: Creation de MateriaSource");
    MateriaSource	srcc;

    separator("TEST: Apprentissage de Materias");
    srcc.learnMateria(new Ice());
    srcc.learnMateria(new Cure());
    srcc.learnMateria(new Ice());
    srcc.learnMateria(new Cure());
    srcc.learnMateria(new Ice()); // Ne doit pas �tre appris (limite de 4)

    separator("TEST: Creation de personnages");
    Character	player("Toto");
    Character	bobs("Bob");

    separator("TEST: Creation et equipement de Materias");
    AMateria* m1 = srcc.createMateria("ice");
    AMateria* m2 = srcc.createMateria("cure");
    AMateria* m3 = srcc.createMateria("ice");
    AMateria* m4 = srcc.createMateria("cure");
    AMateria* m5 = srcc.createMateria("fire"); // Ne doit pas exister

    separator("TEST: equipement");
    player.equip(m1);
    player.equip(m2);
    player.equip(m3);
    player.equip(m4);
    player.equip(m5); //Materiel invalide
    //player.equip(new Ice()); // Ne doit pas �tre ajout� (inventaire plein)

    separator("TEST: Utilisation des Materias");
    player.use(0, bobs); // Ice
    player.use(1, bobs); // Cure
    player.use(2, bobs); // Ice
    player.use(3, bobs); // Cure
    player.use(4, bobs); // Ne doit pas fonctionner

    separator("TEST: Desequipement Materias");
    player.unequip(1); // Cure au sol
    player.unequip(2); // Ice au sol
    player.unequip(3); // Ice au sol
    player.unequip(1); // Cure au sol

    separator("TEST: Lecture liste des materia desequiper");
    player.getUnequip();

    separator("TEST: Verification du clonage (copie)");
    Character	playerCopy = player; // Copie de Player
    playerCopy.use(0, bobs); // Ice doit fonctionner
    playerCopy.use(1, bobs); // Ne doit pas fonctionner (d�s�quip� avant la copie)

    
    separator("TEST: Verification de l'assignation (operator=)");
    Character	newPlayer("NewPlayer");
    newPlayer = player; // Assignation
    newPlayer.use(0, bobs); // Ice doit fonctionner

    separator("TEST: Destruction des objets");

    return 0;
}

