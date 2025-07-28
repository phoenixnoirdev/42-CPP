/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phkevin <phkevin@42luxembourg.lu>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 11:09:34 by phkevin           #+#    #+#             */
/*   Updated: 2025/03/27 11:09:34 by phkevin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"
#include "../inc/ShrubberyCreationForm.hpp"
#include "../inc/RobotomyRequestForm.hpp"
#include "../inc/PresidentialPardonForm.hpp"

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
    // TEST SHRUBBERYCREATIONFORM NO SIGN AND EXEC
    //==============================

    separator("TEST SHRUBBERYCREATIONFORM NO SIGN AND EXEC");

    try {
        Bureaucrat Burd("other", 150);
        //Bureaucrat Burd("other", 144);
        //Bureaucrat Burd("other", 100);
        std::cout << Burd << std::endl;
        ShrubberyCreationForm Formd("Shrub test");
        //Formd.Execute(Burd);
        std::cout << Formd << std::endl;
        Formd.beSigned(Burd);
        Formd.Execute(Burd);
        std::cout << Formd << std::endl;
    }
    catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    lBreak(3);

    //==============================
    // TEST SHRUBBERYCREATIONFORM NO EXEC
    //==============================

    separator("TEST SHRUBBERYCREATIONFORM NO EXEC");

    try {
        //Bureaucrat Burd("other", 150);
        Bureaucrat Burd("other", 144);
        //Bureaucrat Burd("other", 100);
        std::cout << Burd << std::endl;
        ShrubberyCreationForm Formd("Shrub test");
        Formd.Execute(Burd);
        std::cout << Formd << std::endl;
        Formd.beSigned(Burd);
        //Formd.Execute(Burd);
        std::cout << Formd << std::endl;
    }
    catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    lBreak(3);

    //==============================
    // TEST SHRUBBERYCREATIONFORM OK
    //==============================

    separator("TEST SHRUBBERYCREATIONFORM OK");

    try {
        //Bureaucrat Burd("other", 150);
        //Bureaucrat Burd("other", 144);
        Bureaucrat Burd("other", 100);
        std::cout << Burd << std::endl;
        ShrubberyCreationForm Formd("Shrub test");
        //Formd.Execute(Burd);
        std::cout << Formd << std::endl;
        Formd.beSigned(Burd);
        Formd.Execute(Burd);
        std::cout << Formd << std::endl;
    }
    catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    lBreak(3);





    //==============================
    // TEST ROBOTOMYREQUESTFORM NO SIGN AND EXEC
    //==============================

    separator("TEST ROBOTOMYREQUESTFORM NO SIGN AND EXEC");

    try {
        Bureaucrat Burd("other", 150);
        //Bureaucrat Burd("other", 144);
        //Bureaucrat Burd("other", 50);
        std::cout << Burd << std::endl;
        RobotomyRequestForm Formd("Robot test");
        for (int i = 0; i < 50; i++)
        {
            std::cout << YELLOW << i << RESET << " - ";
            Formd.Execute(Burd);
        }
        std::cout << Formd << std::endl;
        Formd.beSigned(Burd);
        std::cout << Formd << std::endl;
    }
    catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    lBreak(3);

    //==============================
    // TEST ROBOTOMYREQUESTFORM SIGN SIGN ERR LOW GRADE
    //==============================

    separator("TEST ROBOTOMYREQUESTFORM SIGN ERR LOW GRADE ");

    try {
        Bureaucrat Burd("other", 150);
        //Bureaucrat Burd("other", 144);
        //Bureaucrat Burd("other", 50);
        std::cout << Burd << std::endl;
        RobotomyRequestForm Formd("Robot test");
        std::cout << Formd << std::endl;
        Formd.beSigned(Burd);
        std::cout << Formd << std::endl;
        for (int i = 0; i < 50; i++)
        {
            std::cout << YELLOW << i << RESET << " - ";
            Formd.Execute(Burd);
        }
    }
    catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    lBreak(3);

    //==============================
    // TEST ROBOTOMYREQUESTFORM AND EXEC
    //==============================

    separator("TEST ROBOTOMYREQUESTFORM AND EXEC");

    try {
        //Bureaucrat Burd("other", 150);
        Bureaucrat Burd("other", 60);
        //Bureaucrat Burd("other", 50);
        std::cout << Burd << std::endl;
        RobotomyRequestForm Formd("Robot test");
        //Formd.Execute(Burd);
        std::cout << Formd << std::endl;
        Formd.beSigned(Burd);
        for (int i = 0; i < 50; i++)
        {
            std::cout << YELLOW << i << RESET << " - ";
            Formd.Execute(Burd);
        }
        std::cout << Formd << std::endl;
    }
    catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    lBreak(3);

    //==============================
    // TEST ROBOTOMYREQUESTFORM OK
    //==============================

    separator("TEST ROBOTOMYREQUESTFORM OK");

    try {
        //Bureaucrat Burd("other", 150);
        //Bureaucrat Burd("other", 144);
        Bureaucrat Burd("other", 45);
        std::cout << Burd << std::endl;
        RobotomyRequestForm Formd("Robot test");
        //Formd.Execute(Burd);
        std::cout << Formd << std::endl;
        Formd.beSigned(Burd);
        for (int i = 0; i < 50; i++)
        {
            std::cout << YELLOW << i << RESET << " - ";
            Formd.Execute(Burd);
        }
        std::cout << Formd << std::endl;
    }
    catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }




    //==============================
// TEST PRESIDENTIALQUESTFORM NO SIGN AND EXEC
//==============================

    separator("TEST PRESIDENTIALQUESTFORM NO SIGN AND EXEC");

    try {
        Bureaucrat Burd("other", 150);
        //Bureaucrat Burd("other", 144);
        //Bureaucrat Burd("other", 50);
        std::cout << Burd << std::endl;
        PresidentialPardonForm Formd(Burd.GetName());
        Formd.Execute(Burd);
        std::cout << Formd << std::endl;
        Formd.beSigned(Burd);
        std::cout << Formd << std::endl;
    }
    catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    lBreak(3);

    //==============================
    // TEST PRESIDENTIALQUESTFORM SIGN SIGN ERR LOW GRADE
    //==============================

    separator("TEST PRESIDENTIALQUESTFORM SIGN ERR LOW GRADE ");

    try {
        Bureaucrat Burd("other", 150);
        //Bureaucrat Burd("other", 144);
        //Bureaucrat Burd("other", 50);
        std::cout << Burd << std::endl;
        PresidentialPardonForm Formd(Burd.GetName());
        std::cout << Formd << std::endl;
        Formd.beSigned(Burd);
        std::cout << Formd << std::endl;
        Formd.Execute(Burd);
    }
    catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    lBreak(3);

    //==============================
    // TEST PRESIDENTIALQUESTFORM AND EXEC
    //==============================

    separator("TEST PRESIDENTIALQUESTFORM AND EXEC");

    try {
        //Bureaucrat Burd("other", 150);
        Bureaucrat Burd("other", 25);
        //Bureaucrat Burd("other", 50);
        std::cout << Burd << std::endl;
        PresidentialPardonForm Formd(Burd.GetName());
        //Formd.Execute(Burd);
        std::cout << Formd << std::endl;
        Formd.beSigned(Burd);
        Formd.Execute(Burd);
        std::cout << Formd << std::endl;
    }
    catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    lBreak(3);

    //==============================
    // TEST PRESIDENTIALQUESTFORM OK
    //==============================

    separator("TEST PRESIDENTIALQUESTFORM OK");

    try {
        //Bureaucrat Burd("other", 150);
        //Bureaucrat Burd("other", 144);
        Bureaucrat Burd("other", 1);
        std::cout << Burd << std::endl;
        PresidentialPardonForm Formd(Burd.GetName());
        //Formd.Execute(Burd);
        std::cout << Formd << std::endl;
        Formd.beSigned(Burd);
        Formd.Execute(Burd);
        std::cout << Formd << std::endl;
    }
    catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}
