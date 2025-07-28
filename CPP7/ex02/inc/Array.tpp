/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phkevin <phkevin@42luxembourg.lu>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 23:41:19 by phkevin           #+#    #+#             */
/*   Updated: 2025/04/09 23:41:19 by phkevin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

//==============================
// CONSTRUCTEUR
//==============================

/**
 * @brief Constructeur par defaut de la classe Array.
 *
 * Initialise un tableau vide avec un pointeur nul et une taille de 0.
 * Affiche un message indiquant que le constructeur par defaut est appele.
 */
template < typename T >
Array<T>::Array() : _array(NULL), _size(0)
{
        if (LOG == true)
		    std::cout << GREEN << LOGO << RESET << "Default constructor called" << std::endl;
}

/**
 * @brief Constructeur avec taille de la classe Array.
 *
 * Cree un tableau de taille specifiee, initialise avec des valeurs par defaut.
 *
 * @param n Taille du tableau a creer.
 */
template <typename T>
Array<T>::Array(unsigned int n) : _array(new T[n]()), _size(n)
{
        if (LOG == true)
		    std::cout << GREEN << LOGO << RESET << "Default constructor called" << std::endl;
}

/**
 * @brief Constructeur par copie de la classe Array.
 *
 * Initialise une nouvelle instance d'Array en copiant les elements d'une
 * autre instance.
 *
 * @param other Instance de Array a copier.
 */
template <typename T>
Array<T>::Array(const Array<T>& other) : _array(NULL), _size(0)
{
    if (LOG == true)
	    std::cout << GREEN << LOGO << RESET << "Copy constructor called" << std::endl;

    *this = other;
}

/**
 * @brief Surcharge de l'operateur d'affectation pour la classe Array.
 *
 * Copie les elements de l'objet donne si ce n'est pas une auto-affectation.
 * L'ancien tableau est supprime et un nouveau est alloue avec les memes
 * elements que dans l'objet source.
 *
 * @param other Objet Array a copier.
 * @return Reference vers l'objet courant apres affectation.
 */
template <typename T>
Array<T>& Array<T>::operator=(const Array<T>& other)
{
    if (LOG == true)
	    std::cout << GREEN << LOGO << RESET << "Operator = constructor called" << std::endl;

    if (this != &other)
    {
        delete[] _array;

        this->_size = other._size;
        this->_array = new T[_size];

        for (unsigned int i = 0; i < this->_size; ++i)
            this->_array[i] = other._array[i];
    }

    return *this;
}

/**
 * @brief Destructeur de la classe Array.
 *
 * Libere la memoire allouee dynamiquement pour le tableau interne.
 */
template <typename T>
Array<T>::~Array() 
{
    if (LOG == true)
        std::cout << GREEN << LOGO << RESET << "Destructor called" << std::endl;

    delete[] _array;
}

/**
 * @brief Accede a l'element a l'index donne dans le tableau.
 *
 * @param index Index de l'element a acceder.
 * @return Reference vers l'element a l'index specifie.
 * @throws std::out_of_range si l'index est hors des limites.
 */
template <typename T>
T& Array<T>::operator[](unsigned int index) 
{
    if (LOG == true)
	    std::cout << GREEN << LOGO << RESET << "Operator [] constructor called" << std::endl;

    if (index >= _size)
        throw std::out_of_range("Index out of bounds");

    return _array[index];
}


//==============================
// FONCTION
//==============================

/**
 * @brief Retourne la taille actuelle du tableau.
 *
 * @return La taille (nombre d'elements) du tableau.
 */
template <typename T>
unsigned int Array<T>::size() const
{
    return _size;
}