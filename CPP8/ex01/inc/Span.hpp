/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phkevin <phkevin@42luxembourg.lu>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 14:20:06 by phkevin           #+#    #+#             */
/*   Updated: 2025/04/13 14:20:06 by phkevin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <exception>
#include <vector>
#include <algorithm>

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
#define LOGO "Span: "
#define LOGOEXCE "Exception: "


//==============================
// DEBUG ACTIF
//==============================
#define DEBUG false // Permet d'afficher les DEBUG si TRUE et FALSE pour desactiver
#define LANG "ENG" // Permet d'afficher les ERROR en anglais ou francais, set a ENG ou FR

class Span
{
	private:
		unsigned int _sizelist;
		std::vector<int> _store;

		//==============================
		// Consturcteur
		//=============================
		Span();
	

	public:
		//==============================
		// Consturcteur
		//=============================
		Span(unsigned int val);
		Span(const Span& obj);
		Span& operator=(const Span& obj);
		~Span();

		//==============================
		// Fonction
		//==============================
		void addNumber(int val);
		int shortestSpan();
		int longestSpan();
		void addRandNumber(int qNb);
		void storePrint();
};

class ExcepSize : public std::exception
{
	virtual const char* what() const throw();
};

class ExcepDist : public std::exception
{
	virtual const char* what() const throw();
};

#endif //SPAN_HPP
