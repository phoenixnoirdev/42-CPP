/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phkevin <phkevin@42luxembourg.lu>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 03:52:04 by phkevin           #+#    #+#             */
/*   Updated: 2025/04/04 03:52:04 by phkevin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

//==============================
// CONSTRUCTEUR
//==============================

/**
 * @brief Destructeur de la classe Base.
 *
 * Ce destructeur est appele lors de la destruction d'un objet de type `Base`
 * ou d'une classe derivee. Il affiche un message indiquant son appel.
 */
Base::~Base()
{
    std::cout << GREEN << LOGO << RESET << "Destructor called" << std::endl;
}


//==============================
// FONCTION
//==============================

/**
 * @brief Gen�re dynamiquement un objet d�riv� de Base et retourne son pointeur.
 *
 * Cette fonction s�lectionne al�atoirement une des classes d�riv�es (`A`, `B`,
 * `C` ou `D`) et cr�e un nouvel objet correspondant. L'allocation se fait sur
 * le tas et un message est affich� pour indiquer le type cr��.
 *
 * @return Base* Un pointeur vers un objet de type `A`, `B`, `C` ou `D`.
 */
Base* Generate()
{
    int r = std::rand() % 4;

    if (r == 0)
    {
        std::cout << GREEN << LOGO << RESET << "Creation pointeur " << GREEN << "A" << RESET << std::endl;
        return new A();
    }
    else if (r == 1)
    {
        std::cout << GREEN << LOGO << RESET << "Creation pointeur " << GREEN << "B" << RESET << std::endl;
        return new B();
    }
    else if (r == 2)
    {
        std::cout << GREEN << LOGO << RESET << "Creation pointeur " << GREEN << "C" << RESET << std::endl;
        return new C();
    }
    else
    {
        std::cout << GREEN << LOGO << RESET << "Creation pointeur " << GREEN << "D" << RESET << std::endl;
        return new D();
    }
}

/**
 * @brief Identifie dynamiquement le type d'un objet Base passe en pointeur.
 *
 * Cette fonction tente de caster l'objet `p` en `A`, `B` puis `C` a l'aide de
 * `dynamic_cast`. Si un cast reussit, elle affiche le type detecte et quitte.
 * Si aucun cast ne fonctionne, un message d'erreur est affiche.
 *
 * @param p Pointeur vers un objet de type `Base` a identifier.
 */
void identify(Base* p)
{
    if (dynamic_cast<A*>(p))
    {
        std::cout << CYAN << "A -> *" << RESET << std::endl;
        return;
    }

    if (dynamic_cast<B*>(p))
    {
        std::cout << CYAN << "B -> *" << RESET << std::endl;
        return;
    }

    if (dynamic_cast<C*>(p))
    {
        std::cout << CYAN << "C -> *" << RESET << std::endl;
        return;
    }

    std::cout << RED << "Type unknown -> *" << RESET << std::endl;
}

/**
 * @brief Identifie dynamiquement le type d'un objet Base pass� par r�f�rence.
 *
 * Cette fonction tente de caster l'objet `p` en `A`, `B` puis `C` en utilisant
 * `dynamic_cast`. Si l'un des casts r�ussit, elle affiche le type d�tect� et
 * retourne imm�diatement. Si aucun cast ne fonctionne, un message d'erreur est
 * affich�.
 *
 * @param p R�f�rence vers un objet de type `Base` � identifier.
 */
void identify(Base& p)
{
    try 
    {
        (void)dynamic_cast<A&>(p);
        std::cout << CYAN << "A -> &" << RESET << std::endl;
        return;
    }
    catch (const std::exception& e)
    {
    
    }

    try 
    {
        (void)dynamic_cast<B&>(p);
        std::cout << CYAN << "B -> &"  << RESET << std::endl;
        return;
    }
    catch (const std::exception& e) 
    {

    }

    try 
    {
        (void)dynamic_cast<C&>(p);
        std::cout << CYAN << "C -> &" << RESET << std::endl;
        return;
    }
    catch (const std::exception& e) 
    {

    }

    std::cout << RED << "Type unknown -> &" << RESET << std::endl;
}
