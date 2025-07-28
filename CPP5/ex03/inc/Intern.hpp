/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phkevin <phkevin@42luxembourg.lu>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 12:07:46 by phkevin           #+#    #+#             */
/*   Updated: 2025/03/28 12:07:46 by phkevin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

//==============================
// LOGO IN LOG
//==============================
#define LOGOINT "Intern: "

class Form;
class PresidentialPardonForm;
class RobitomyResquestForm;
class ShrubberyCreationForm;

class Intern
{

private:
	std::string _form[3];


public:
	//==============================
	// CONSTRUCTEUR
	//==============================

	Intern();
	Intern(Intern& obj);
	Intern& operator=(Intern& obj);
	~Intern();

	


	//==============================
	// FONCTION
	//==============================
	 
	Form* makeForm(std::string nameform, std::string target);
};

#endif //INTERN_HPP