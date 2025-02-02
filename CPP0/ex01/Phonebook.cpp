/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phkevin <phkevin@42luxembourg.lu>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 10:27:24 by phkevin           #+#    #+#             */
/*   Updated: 2025/01/24 13:54:27 by phkevin          ###   Luxembour.lu      */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

int NexEnter = 0;

/**
 * @brief Ajoute un nouveau contact dans le carnet d'adresses.
 *
 * Cette méthode crée un nouveau contact à partir des informations fournies,
 * l'insère dans le carnet et remplace l'entrée la plus ancienne si la capacité
 * maximale est atteinte.
 *
 * @param fname Prénom du contact.
 * @param lname Nom de famille du contact.
 * @param nname Surnom du contact.
 * @param num Numéro de téléphone du contact.
 * @param darksecret Secret le plus sombre du contact.
 */
void PhoneBook::AddPhoneBook(const std::string& fname, const std::string& lname, const std::string& nname, const std::string& num, const std::string& darksecret)
{
	Contact newContacte;

	if (NexEnter >= MaxSize)
		NexEnter = 0;
	newContacte.NewContacte(fname, lname, nname, num, darksecret);
	book[NexEnter] = newContacte;
	NexEnter++;
}

/**
 * @brief Formate une chaîne de caractères pour respecter une taille maximale.
 *
 * Si la longueur de la chaîne dépasse la taille maximale définie, elle est
 * tronquée et un point final est ajouté pour indiquer le raccourcissement.
 *
 * @param e La chaîne de caractères à formater.
 * @return String La chaîne formatée, respectant la taille maximale.
 */
std::string Format(std::string e)
{
	if (e.length() > MaxCharSize)
	{
		e = e.substr(0, MaxCharSize - 1) + ".";
	}
	return e;
}

/**
 * @brief Affiche tous les contacts du carnet d'adresses.
 *
 * Cette méthode parcourt le carnet d'adresses et affiche chaque contact sous
 * forme tabulaire avec des colonnes formatées pour inclure un identifiant,
 * le prénom, le nom de famille et le surnom.
 *
 * Les noms sont tronqués si leur longueur dépasse une taille maximale prédéfinie.
 */
void PhoneBook::GetAll() const
{
	for (int i = 0; i < MaxSize; i++)
	{
		std::cout << "| " << std::setw(MaxCharSize) << std::right << i
			<< " | " << std::setw(MaxCharSize) << std::right << Format(book[i].GetFName())
			<< " | " << std::setw(MaxCharSize) << std::right << Format(book[i].GetLName())
			<< " | " << std::setw(MaxCharSize) << std::right << Format(book[i].GetNName()) << " |"
			<< std::endl;
	}
}

/**
 * @brief Affiche les détails d'un contact en fonction de son index.
 *
 * Cette méthode permet d'afficher les informations complètes d'un contact (prénom,
 * nom, surnom, numéro de téléphone et secret) en fonction de son index dans le carnet.
 * Si l'index fourni est invalide, un message d'erreur est affiché.
 *
 * @param i L'index du contact à afficher dans le carnet.
 */
void PhoneBook::GetIndex(int i) const
{
	if (i <= MaxSize - 1)
	{
		std::cout << "______________________________________________________" << "\n";
		std::cout << "First name: " << book[i].GetFName() << "\n";
		std::cout << "Last name: " << book[i].GetLName() << "\n";
		std::cout << "Nickname: " << book[i].GetNName() << "\n";
		std::cout << "Phone number: " << book[i].GetNum() << "\n";
		std::cout << "Darkest secret: " << book[i].GetDark() << "\n";
		std::cout << "______________________________________________________" << "\n";
	}
	else
	{
		std::cout << "Error: Index out of range" << "\n";
	}
}