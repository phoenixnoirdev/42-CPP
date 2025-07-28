/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phkevin <phkevin@42luxembourg.lu>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 02:37:27 by phkevin           #+#    #+#             */
/*   Updated: 2025/03/25 02:37:27 by phkevin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>
#include "../inc/Form.hpp"

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

#define GRADE_MIN 1
#define GRADE_MAX 150

class Form;

class Bureaucrat
{
	private:
		std::string _name;
		int _grade;

		void IsLimitGrade(std::string name, int grade);

	public:
		//==============================
		// CONSTRUCTEUR
		//==============================
		Bureaucrat();
		Bureaucrat(std::string name, int grade);
		Bureaucrat(Bureaucrat const& obj);
		Bureaucrat operator=(Bureaucrat const& obj);
		~Bureaucrat();

		//==============================
		// FONCTION
		//==============================
		int GetGrade() const;
		std::string GetName() const;
		void IncreGrade();
		void DecreGrade();
		void signForm(Form* signedForm, const std::string& reason);

	//==============================
	// EXCEPTION
	//==============================
	class GradeException : public std::exception 
	{
		private:
			std::string _message;

		public:
			explicit GradeException(const std::string& msg) : _message(msg) {}
			
			virtual ~GradeException() throw() {}

			virtual const char* what() const throw()
			{
				return _message.c_str();
			}
	};
	
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& obj);

#endif // BUREAUCRAT_HPP