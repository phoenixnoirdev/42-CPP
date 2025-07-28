/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phkevin <phkevin@42luxembourg.lu>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 23:41:15 by phkevin           #+#    #+#             */
/*   Updated: 2025/04/09 23:41:15 by phkevin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

//==============================
// FORMAT TEXTE
//==============================
#define RESET   "\033[0;39m"
#define RED     "\033[0;31m"
#define GREEN   "\033[0;92m"
#define YELLOW  "\033[0;93m"
#define BLUE    "\033[0;34m"
#define MAGENTA "\033[0;35m"
#define CYAN    "\033[0;36m"
#define WHITE   "\033[0;37m"


//==============================
// LOGO IN LOG
//==============================
#define LOGO "Array: "

//==============================
// LOG ACTIF
//==============================
#define LOG false // Permet d'afficher les log si TRUE et FALSE pour desactiver

template <class T> class Array 
{
private:
    T* _array;
    unsigned int _size;

public:
    //==============================
    // CONSTRUCTEUR
    //==============================
    Array();
    Array(unsigned int n);
    Array(const Array& other);
    Array& operator=(const Array& other);
    T& operator[](unsigned int index);
    ~Array();

    //==============================
    // FONCTION
    //==============================
    unsigned int size() const;

};

#include "Array.tpp"

#endif //ARRAY_HPP