/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Param.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phkevin <phkevin@42luxembourg.lu>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 09:39:59 by phkevin           #+#    #+#             */
/*   Updated: 2025/03/21 09:39:59 by phkevin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARAM_HPP
#define PARAM_HPP

#include <string>
#include <iostream>

//==============================
// FORMAT TEXTE
//==============================
#define RESET   "\033[0;39m"
#define RED     "\033[0;31m"
#define GREEN   "\033[0;92m"
#define YELLOW  "\033[0;93m"
#define BLUE    "\033[0;34m"
#define MAGENTA "\033[0;35m"
#define CYAN    "\033[0;36m"
#define WHITE   "\033[0;37m"

//==============================
// LANGUE
//==============================
#define	LANG 		1 //Para disponible ENG / FR
#define	LANG_FR 	1 //FR
#define	LANG_ENG 	2 //ENG


//==============================
// MSG FR
//==============================
//Construteur
#define FRCONST ": Constructeur appel"
#define FRCPYCONST ": Constructeur de copy appel"
#define FROPCONST ": Constructeur operateur appel"
#define FRDESCONST ": Destructeur appele"
#define FRUSETARGET ": Inutilisable sur la cible "

//AMateria.cpp
#define FRINVAMAT ": Materiel invalide"

//Character.cpp
#define FRMATSLOT0 ": L'emplacement "
#define FRMATSLOT1 " de l'inventaire utilisateur "
#define FRMATSLOT2 " a ete attribue a un AMateria de type "
#define	FRMATSLOT3 ": L'invetaire de l'utilisateur "
#define	FRMATSLOT4 " est plein"
#define FRMATSLOT5 ": Inventaire: indice hors de plage"
#define FRMATSLOT6 ": Inventaire: Emplacement vide"
#define FRMATSLOT7 ": Inventaire: purge du slot "
#define FRMATSLOT8 ": Materia desequiper "
#define FRMATSLOT9 " - utilisateur "
#define FRMATSLOT10 ": Unequipe full, ecrassement de l'ancien objet pour le remplacer par le nouvel objet unequipe."

//MateriaSource.cpp
#define FRMATSRC0 ": Une nouvelle Materia de type "
#define FRMATSRC1 " a ete apprise"
#define FRMATSRC2 ": inventaire plein, impossible d'apprendre une nouvelle Materia"
#define FRMATSRC3 ": Ce type de Materia n'existe pas"

//==============================
// MSG ENG
//==============================
//Construteur
#define ENGCONST ": Call constructor"
#define ENGCPYCONST ": Copy constructor called"
#define ENGOPCONST ": Operator constructor called"
#define ENGDESCONST ": Destructor called"
#define ENGUSETARGET ": Unusable on target "

//AMateria.cpp
#define ENGINVAMAT ": Invalid material"

//Character.cpp
#define ENGMATSLOT0 ": Slot "
#define ENGMATSLOT1 " of the user inventory "
#define ENGMATSLOT2 " has been assigned to an AMateria of type "
#define	ENGMATSLOT3 ": User "
#define	ENGMATSLOT4 " 's inventory is full"
#define ENGMATSLOT5 ": Inventory: Index out of range"
#define ENGMATSLOT6 ": Inventory: Empty slot"
#define ENGMATSLOT7 ": Inventory: Purge the slot "
#define ENGMATSLOT8 ": Unequipped material "
#define ENGMATSLOT9 " - user "
#define ENGMATSLOT10 ": A full team, overwriting the old object to replace it with the new one team object."

//MateriaSource.cpp
#define ENGMATSRC0 ": A new "
#define ENGMATSRC1 "-type Materia has been learned"
#define ENGMATSRC2 ": Inventory full, unable to learn new Materia"
#define ENGMATSRC3 ": This type of Materia does not exist"



#endif // PARAM_HPP