/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phkevin <phkevin@42luxembourg.lu>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 08:34:07 by phkevin           #+#    #+#             */
/*   Updated: 2025/03/31 08:34:07 by phkevin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Param.hpp"
#include "Serializer.hpp"

/**
 * @brief Affiche plusieurs lignes vides dans la console.
 *
 * @param nb Nombre de lignes vides a afficher.
 */
void lBreak(int nb)
{
	for (int i = 0; i < nb; ++i)
		std::cout << std::endl;
}

/**
 * @brief Affiche un separateur formate avec un titre centr�.
 *
 * @param str Texte a afficher au centre du separateur.
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
	// INIT DATA
	//==============================
	Data data;
	data.name = "Toto";
	data.value = 42;


	//==============================
	// CONTROLE INIT DATA
	//==============================
	separator("CONTROLE INIT DATA");

	std::cout << YELLOW << "Nom : " << RESET << data.name << std::endl;
	std::cout << YELLOW << "Valeur: " << RESET << data.value << std::endl;

	lBreak(2);


	//==============================
	// SERIALIZE
	//==============================
	separator("SERIALIZE");

	uintptr_t raw = Serializer::Serialize(&data);
	std::cout << CYAN << "Serialize: " << RESET << "Adresse originale   : " << &data << std::endl;
	std::cout << CYAN << "Serialize: " << RESET << "Adresse serialisee  : " << raw << std::endl;

	lBreak(2);


	//==============================
	// DESERIALIZE
	//==============================
	separator("DESERIALIZE");

	Data* deserialized = Serializer::Deserialize(raw);
	std::cout << CYAN << "Deserialize: " << RESET << "Adresse deserialisee: " << deserialized << std::endl;

	lBreak(2);


	//==============================
	// CONTROL RES
	//==============================
	separator("CONTROL RES");

	if (deserialized == &data) {
		std::cout << GREEN << "La deserialisation est correcte !" << RESET << std::endl;
	}
	else {
		std::cout << RED << "Erreur lors de la deserialisation !" << RESET << std::endl;
	}

	lBreak(1);

	std::cout << YELLOW << "Nom : " << RESET << deserialized->name << std::endl;
	std::cout << YELLOW << "Valeur: " << RESET << deserialized->value << std::endl;

	lBreak(2);

	return 0;
}