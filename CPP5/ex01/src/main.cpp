/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phkevin <phkevin@42luxembourg.lu>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 02:37:08 by phkevin           #+#    #+#             */
/*   Updated: 2025/03/25 02:37:08 by phkevin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"

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
    // INIT GRADE TOO BIG
    //==============================

    separator("INIT GRADE TOO BIG");

    try
    {
        Bureaucrat BurA("Toto", 151);
    }
    catch (std::exception& e)
    {
        std::cout << "Exception : \n" << e.what() << std::endl;
    }

    lBreak(3);



    //==============================
    // INIT GRADE TOO SMALL
    //==============================

    separator("INIT GRADE TOO SMALL");

    try
    {
        Bureaucrat BurB("Tata", 0);
    }
    catch (std::exception& e)
    {
        std::cout << "Exception : \n" << e.what() << std::endl;
    }

    lBreak(3);



    //==============================
    // INCREMENTE GRADE ET AND DECREMENT
    //==============================

    separator("INCREMENT GRADE ET AND DECREMENT");

    try
    {
        Bureaucrat Burc("Titi", 56);
        Burc.IncreGrade();
        Burc.IncreGrade();
        Burc.IncreGrade();
        Burc.DecreGrade();
    }
    catch (std::exception& e)
    {
        std::cout << "Exception : \n" << e.what() << std::endl;
    }

    lBreak(3);



    //==============================
    // INCREMENTE GRADE ET AND DECREMENT TOO SMALL
    //==============================

    separator("INCREMENT GRADE ET AND DECREMENT TOO SMALL");

    try
    {
        Bureaucrat Burd("Tete", 1);
        std::cout << Burd << std::endl;
        Burd.IncreGrade(); //OK
        std::cout << Burd << std::endl;
        Burd.DecreGrade(); //OK
        std::cout << Burd << std::endl;
        Burd.DecreGrade(); //EXCEPTION
        std::cout << Burd << std::endl;
        Burd.DecreGrade(); //NO EXECUTE
        std::cout << Burd << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Exception : \n" << e.what() << std::endl;
    }

    lBreak(3);



    //==============================
    // INCREMENTE GRADE ET AND DECREMENT TOO BIG
    //==============================

    separator("INCREMENT GRADE ET AND DECREMENT TOO BIG");

    try
    {
        Bureaucrat Bure("Tristant", 150);
        std::cout << Bure << std::endl;
        Bure.DecreGrade(); //OK
        std::cout << Bure << std::endl;
        Bure.IncreGrade(); //OK
        std::cout << Bure << std::endl;
        Bure.IncreGrade(); //EXCEPTION
        std::cout << Bure << std::endl;
        Bure.IncreGrade(); //NO EXECUTE
        std::cout << Bure << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << "Exception : \n" << e.what() << std::endl;
    }

    lBreak(3);



    //==============================
    // FORM TEST SIGN AND RESIGN
    //==============================

    separator("FORM TEST SIGN AND RESIGN");

    try 
    {
        Bureaucrat BurA("other", 121);
        std::cout << BurA << std::endl;

        Form FormA("Form A", 124, 128);
        std::cout << FormA << std::endl;
        FormA.beSigned(BurA);
        std::cout << FormA << std::endl;
        FormA.beSigned(BurA);//EXCEPTION DEJA SIGNER
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }


    //==============================
    // FORM TEST CREATE ERROR GRADE
    //==============================

    separator("FORM TEST CREATE ERROR GRADE");

    try
    {
        Form FormB("Form B", 160, 128);
        std::cout << FormB << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    try
    {
        Form FormC("Form C", 120, 160);
        std::cout << FormC << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    return 0;
}
