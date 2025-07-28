/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phkevin <phkevin@42luxembourg.lu>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 12:07:23 by phkevin           #+#    #+#             */
/*   Updated: 2025/03/28 12:07:23 by phkevin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

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
    // TEST EXEMPLE EXO
    //==============================

    separator("TEST EXEMPLE EXO");

    try 
    {
        Intern someRandomIntern;
        Form* rrf;
        rrf = someRandomIntern.makeForm("robotomy request", "Bender");
        delete rrf;
    }
    catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    
    lBreak(3);


    //==============================
    // TEST EXEMPLE EXO ROBOTOMY REQUEST 15 EXE
    //==============================

    separator("TEST EXEMPLE EXO ROBOTOMY REQUEST 15 EXE");
    try {
        Bureaucrat Burd("other", 5);
        std::cout << Burd << std::endl;
        lBreak(1);
        Intern someRandomIntern;
        lBreak(1);
        Form* rrf;
        rrf = someRandomIntern.makeForm("robotomy request", "Bender");
        lBreak(1);
        rrf->beSigned(Burd);
        lBreak(2);
        for (int i = 0; i < 15; i++)
        {
            std::cout << YELLOW << i << RESET << " - ";
            rrf->Execute(Burd);
            lBreak(1);
        }
        lBreak(2);
        delete rrf;
    }
    catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    lBreak(3);


    //==============================
    // TEST EXEMPLE EXO PRESIDENTIAL PARDON REQUEST
    //==============================

    separator("TEST EXEMPLE EXO PRESIDENTIAL PARDON REQUEST");
    try {
        Bureaucrat Burd("other", 5);
        std::cout << Burd << std::endl;
        lBreak(1);
        Intern someRandomIntern;
        lBreak(1);
        Form* rrf;
        rrf = someRandomIntern.makeForm("presidential pardon request", "Bender");
        lBreak(1);
        rrf->beSigned(Burd);
        lBreak(2);
        rrf->Execute(Burd);
        lBreak(2);
        delete rrf;
    }
    catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    lBreak(3);


    //==============================
    // TEST EXEMPLE EXO SHRUBBERY CREATION REQUEST
    //==============================

    separator("TEST EXEMPLE EXO SHRUBBERY CREATION REQUEST");
    try {
        Bureaucrat Burd("other", 5);
        std::cout << Burd << std::endl;
        lBreak(1);
        Intern someRandomIntern;
        lBreak(1);
        Form* rrf;
        rrf = someRandomIntern.makeForm("shrubbery creation request", "Bender");
        lBreak(1);
        rrf->beSigned(Burd);
        lBreak(2);
        rrf->Execute(Burd);
        lBreak(2);
        delete rrf;
    }
    catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}
