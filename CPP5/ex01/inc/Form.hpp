/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phkevin <phkevin@42luxembourg.lu>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 02:37:23 by phkevin           #+#    #+#             */
/*   Updated: 2025/03/25 02:37:23 by phkevin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include "../inc/Bureaucrat.hpp"

class Bureaucrat;

class Form
{

private:
	const std::string _name;
	bool _sign;
	const int _gradeToSign;
	const int _gradeToExe;


	void IsLimitGradeInit(std::string name, std::string type, int grade);



public:
	//==============================
	// CONSTRUCTEUR
	//==============================
	Form();
	Form(std::string name, int gradeSign, int gradeExe);
	Form(Form& obj);
	Form& operator=(Form& obj);
	~Form();



	//==============================
	// FONCTION
	//==============================
	std::string GetName();

	bool IsSigned();
	void beSigned(Bureaucrat &obj);

	int GetGradeSigne();

	int GetGradeExec();


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

std::ostream& operator<<(std::ostream& os, Form& obj);

#endif // FORM_HPP