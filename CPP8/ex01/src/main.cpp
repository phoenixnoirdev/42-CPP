/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phkevin <phkevin@42luxembourg.lu>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 14:20:09 by phkevin           #+#    #+#             */
/*   Updated: 2025/04/13 14:20:09 by phkevin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

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
 * @brief Affiche un separateur formate avec un titre centre.
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
    // TEST EXEMPLE EXERCICE
    //==============================
    separator("TEST EXEMPLE EXERCICE");
    
    int s0 = 5;
    std::cout << "Size vector: " << CYAN << s0 << RESET << std::endl;

    Span sp = Span(s0);

    try
    {
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);

        std::cout << "shortestSpan: " << CYAN << sp.shortestSpan() << RESET << std::endl;
        std::cout << "longestSpan: " << CYAN << sp.longestSpan() << RESET << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }


    //==============================
    // TEST EXCEPTION DEPASSEMENT
    //==============================
    separator("TEST EXCEPTION DEPASSEMENT");


    int s1 = 5;
    std::cout << "Size vector: " << CYAN << s1 << RESET << std::endl;

    Span sp0 = Span(s1);

    try
    {
        sp0.addNumber(6);
        sp0.addNumber(3);
        sp0.addNumber(17);
        sp0.addNumber(9);
        sp0.addNumber(11);
        sp0.addNumber(155); // EXCEPTION

        std::cout << "shortestSpan: " << CYAN << sp0.shortestSpan() << RESET << std::endl;
        std::cout << "longestSpan: " << CYAN << sp0.longestSpan() << RESET << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    

    //==============================
    // TEST EXCEPTION VECTOR SIZE
    //==============================
    separator("TEST EXCEPTION VECTOR SIZE");


    int s2 = 5;
    std::cout << "Size vector: " << CYAN << s2 << RESET << std::endl;

    Span sp1 = Span(s2);

    try
    {
        sp1.addNumber(6);

        std::cout << "shortestSpan: " << CYAN << sp1.shortestSpan() << RESET << std::endl;
        std::cout << "longestSpan: " << CYAN << sp1.longestSpan() << RESET << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }


    //==============================
    // TEST RANDOM NUMBER
    //==============================
    separator("TEST RANDOM NUMBER");


    int s3 = 25;
    std::cout << "Size vector: " << CYAN << s3 << RESET << std::endl;

    Span sp2 = Span(s3);

    try
    {
        sp2.addNumber(5);
        sp2.addRandNumber(24);

        sp2.storePrint();

        std::cout << "shortestSpan: " << CYAN << sp2.shortestSpan() << RESET << std::endl;
        std::cout << "longestSpan: " << CYAN << sp2.longestSpan() << RESET << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }


    //==============================
    // BIG TEST
    //==============================
    separator("BIG TEST");


    int s4 = 10000;
    std::cout << "Size vector: " << CYAN << s4 << RESET << std::endl;

    Span sp3 = Span(s4);

    try
    {
        sp3.addNumber(5);
        sp3.addRandNumber(9999);

        //sp3.storePrint();

        std::cout << "shortestSpan: " << CYAN << sp3.shortestSpan() << RESET << std::endl;
        std::cout << "longestSpan: " << CYAN << sp3.longestSpan() << RESET << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    lBreak(2);

    return 0;
}
