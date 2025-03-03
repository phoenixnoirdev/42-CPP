/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phkevin <phkevin@42luxembourg.lu>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 10:23:43 by phkevin           #+#    #+#             */
/*   Updated: 2025/03/03 14:36:00 by phkevin          ###   Luxembour.lu      */
/*                                                                            */
/* ************************************************************************** */

#include "header.hpp"

PhoneBook Book;

/**
 * @brief Vérifie si une chaîne ne contient que des chiffres, '+' ou des espaces.
 *
 * Cette fonction analyse la chaîne donnée et retourne vrai si elle ne contient 
 * que des chiffres (0-9), le caractère '+' ou des espaces. Sinon, elle retourne faux.
 * 
 * @param str La chaîne de caractères à vérifier.
 * @return true Si la chaîne ne contient que des chiffres, '+' ou des espaces.
 * @return false Sinon.
 */
bool isNumbers(const std::string& str)
{
    return str.find_first_not_of("0123456789+ ") == std::string::npos;
}

/**
 * @brief Vérifie si une chaîne contient un caractère spécial.
 * 
 * Parcourt la chaîne et retourne true dès qu'un caractère
 * non alphanumérique et non espace est détecté.
 * 
 * @param c La chaîne à analyser.
 * @return true si un caractère spécial est trouvé, sinon false.
 */
bool isSpecialChar(std::string c) 
{
    bool res = false;

    for (std::string::size_type i = 0; i < c.length(); i++)
	{
        if (isalnum(c[i]) == 0 && isspace(c[i]) == 0)
        {
            res = true;
            return (res);
        } 
    }
    return (res);
}

/**
 * @brief Point d'entrée principal du programme de gestion d'un carnet de contacts.
 *
 * Cette fonction permet à l'utilisateur d'interagir avec le carnet de contacts
 * via une boucle principale. Elle prend en charge les commandes suivantes :
 * - "ADD" : Ajouter un nouveau contact avec un prénom, nom, surnom, numéro
 *   de téléphone et un secret.
 * - "SEARCH" : Rechercher et afficher les informations d'un contact existant
 *   en fonction d'un index.
 * - "EXIT" : Quitter le programme.
 *
 * @return int Code de retour du programme (0 si le programme s'exécute correctement).
 */
int main()
{
    std::cout << "Welcome to your phonebook!\n";

    while (1)
    {
        std::string buff;

        std::cout << "> ";
        std::cin >> buff;

        if (buff == "ADD")
        {
            std::string fname, lname, nname, num, dark;
            
            std::cin.ignore();
            do
            {
                std::cout << "Enter first name\n";
                std::getline(std::cin, fname);
                if (fname.empty())
                    std::cout << "This field is empty\n";
                if (isSpecialChar(fname))
                {
                    std::cout << "This field contains special characters\n";
                    fname = "";
                }
            } while (fname.empty());
            
            do
            {
                std::cout << "Enter last name\n";
                std::getline(std::cin, lname);
                if (lname.empty())
                    std::cout << "This field is empty\n";
                if (isSpecialChar(lname))
                {
                    std::cout << "This field contains special characters\n";
                    lname = "";
                }
            } while (lname.empty());

            do
            {
                std::cout << "Enter nickname\n";
                std::getline(std::cin, nname);
                if (nname.empty())
                    std::cout << "This field is empty\n";
                if (isSpecialChar(nname))
                {
                    std::cout << "This field contains special characters\n";
                    nname = "";
                }
            } while (nname.empty());

            do
            {
                std::cout << "Enter phone number\n";
                std::getline(std::cin, num);
                if (num.empty())
                    std::cout << "This field is empty\n";
                if (isNumbers(num) == false)
                {
                    std::cout << "Error: Please enter a valid phone number.\n";
                    num = "";
                }
                if (isSpecialChar(num))
                {
                    std::cout << "This field contains special characters\n";
                    num = "";
                }  
            } while (num.empty());

            do
            {
                std::cout << "Enter darkest secret\n";
                std::getline(std::cin, dark);
                if (dark.empty())
                    std::cout << "This field is empty\n";
                if (isSpecialChar(dark))
                {
                    std::cout << "This field contains special characters\n";
                    dark = ""; 
                }
            } while (dark.empty());

            Book.AddPhoneBook(fname, lname, nname, num, dark);

            std::cout << "New enter = " << fname << "| " << lname << "| " << nname << "| " << num << "| " << dark << "|\n";
        }
        else if (buff == "SEARCH")
        {
            std::string numt = "";
            Book.GetAll();

            std::cout << "Enter the contact reference\n";
            std::cin.ignore();
            std::getline(std::cin, numt);

            if(isNumbers(numt) == true)
            {
                Book.GetIndex(std::atoi(numt.c_str()));
            }
            else
            {
                std::cout << "Error: Invalid string" << "\n";
            }
        }
        else if (buff == "EXIT")
            break;
        else
            std::cout << "Invalid command!\n";
    }
    return 0;
}
