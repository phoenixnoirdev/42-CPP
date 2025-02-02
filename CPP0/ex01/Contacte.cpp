/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contacte.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phkevin <phkevin@42luxembourg.lu>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 10:25:15 by phkevin           #+#    #+#             */
/*   Updated: 2025/01/24 13:44:24 by phkevin          ###   Luxembour.lu      */
/*                                                                            */
/* ************************************************************************** */

#include "contact.hpp"

/**
 * @brief Initialise un nouveau contact avec les informations fournies.
 *
 * Cette méthode met à jour les données d'un contact en attribuant les valeurs
 * des paramètres passés à ses attributs.
 *
 * @param fname Prénom du contact.
 * @param lname Nom de famille du contact.
 * @param nname Surnom du contact.
 * @param num Numéro de téléphone du contact.
 * @param darksecret Secret le plus sombre du contact.
 */
void	Contact::NewContacte(const std::string& fname, const std::string& lname, const std::string& nname, const std::string& num, const std::string& darksecret)
{
	FName = fname;
	LName = lname;
	NName = nname;
	Num = num;
	Dark = darksecret;
}

/**
 * @brief Récupère le prénom du contact.
 *
 * @return String Prénom du contact.
 */
std::string	Contact::GetFName() const
{
	return FName;
}

/**
 * @brief Récupère le nom de famille du contact.
 *
 * @return String Nom de famille du contact.
 */
std::string	Contact::GetLName() const
{
	return LName;
}

/**
 * @brief Récupère le surnom du contact.
 *
 * @return String Surnom du contact.
 */
std::string	Contact::GetNName() const
{
	return NName;
}

/**
 * @brief Récupère le numéro de téléphone du contact.
 *
 * @return String Numéro de téléphone du contact.
 */
std::string	Contact::GetNum() const
{
	return Num;
}

/**
 * @brief Récupère le secret le plus sombre du contact.
 *
 * @return String Secret le plus sombre du contact.
 */
std::string	Contact::GetDark() const
{
	return Dark;
}