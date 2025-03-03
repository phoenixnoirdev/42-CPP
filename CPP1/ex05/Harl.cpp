/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phkevin <phkevin@42luxembourg.lu>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 10:29:27 by phkevin           #+#    #+#             */
/*   Updated: 2025/03/03 10:35:05 by phkevin          ###   Luxembour.lu      */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

/**
 * @brief Affiche un message de débogage concernant un burger.
 *
 * Cette méthode imprime un message sur l'amour pour un burger spécifique avec des
 * ajouts comme du bacon et des condiments spéciaux.
 */
void	Harl::debug()
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger.I really do!" << std::endl;
}

/**
 * @brief Affiche un message d'information concernant le bacon dans un burger.
 *
 * Cette méthode imprime un message sur le mécontentement lié au coût supplémentaire du bacon
 * et à l'insuffisance de bacon dans le burger.
 */
void	Harl::info()
{
	std::cout << "I cannot believe adding extra bacon costs more money. You didnt put enough bacon in my burger!If you did, I wouldnt be asking for more!" << std::endl;
}

/**
 * @brief Affiche un message d'avertissement concernant l'ajout de bacon gratuit.
 *
 * Cette méthode imprime un message exprimant un sentiment de mécontentement
 * et une demande d'ajout gratuit de bacon en raison de la fidélité du client.
 */
void	Harl::warning()
{
	std::cout << "I think I deserve to have some extra bacon for free. Ive been coming for years whereas you started working here since last month." << std::endl;
}

/**
 * @brief Affiche un message d'erreur exprimant une insatisfaction extrême.
 *
 * Cette méthode imprime un message indiquant que la situation est inacceptable
 * et que l'utilisateur souhaite parler immédiatement au responsable.
 */
void	Harl::error()
{
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

/**
 * @brief Appelle une méthode spécifique en fonction du niveau de plainte donné.
 *
 * Cette méthode utilise un tableau de pointeurs de fonction pour appeler la méthode
 * correspondante (debug, info, warning, error) selon la valeur du niveau passé en argument.
 * Si l'indice du niveau est invalide, un message d'erreur est affiché.
 *
 * @param level Le niveau de la plainte, sous forme de chaîne de caractères.
 */
void	Harl::complain(std::string level)
{
	int val = std::atoi(level.c_str());
	void (Harl:: *functions[4])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error };
	
	if (val >= 0 && val <= 3)
	{
		(this->*functions[val])();
	}
	else
		std::cout << "Invalid function index!" << std::endl;
}