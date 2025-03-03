/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phkevin <phkevin@42luxembourg.lu>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 10:25:01 by phkevin           #+#    #+#             */
/*   Updated: 2025/03/03 10:25:07 by phkevin          ###   Luxembour.lu      */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

/**
 * @brief Copie un fichier en remplaçant toutes les occurrences d'une chaîne donnée.
 *
 * Cette fonction lit un fichier source en mode binaire, remplace toutes les
 * occurrences de la chaîne `s1` par `s2`, puis écrit le résultat dans un
 * nouveau fichier nommé "copy.txt".
 *
 * @param ficsour Nom du fichier source à lire.
 * @param s1 Chaîne à rechercher dans le fichier source.
 * @param s2 Chaîne de remplacement pour chaque occurrence de `s1`.
 */
void    cpyReplace(const std::string& ficsour, const std::string& s1, const std::string& s2)
{
    std::ifstream fics(ficsour.c_str(), std::ios::binary);
    std::ofstream ficd("copy.txt", std::ios::binary);
    std::string line;


    if (!fics)
    {
        std::cout << "error: unable to open file." << std::endl;
        return;
    }

    if (!ficd)
    {
        std::cout << "error: unable to create copy." << std::endl;
        return;
    }


    while (std::getline(fics, line))
    {
        size_t pos = 0;
        while ((pos = line.find(s1, pos)) != std::string::npos)
        {
            line.replace(pos, s1.length(), s2);
            pos += s2.length();
        }
        ficd << line << "\n";
    }

    fics.close();
    ficd.close();
}

int main(int argc, char **argv)
{
    if (argc != 4)
    {
        std::cout << "error: please enter the name of the file, source term, term to replace." << std::endl;
        return 1;
    }

    cpyReplace(argv[1], argv[2], argv[3]);

    return 0;
}