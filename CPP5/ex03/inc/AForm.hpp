/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phkevin <phkevin@42luxembourg.lu>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 12:07:49 by phkevin           #+#    #+#             */
/*   Updated: 2025/03/28 12:07:49 by phkevin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <string>
#include "Bureaucrat.hpp"

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
	virtual ~Form() = 0;



	//==============================
	// FONCTION
	//==============================
	std::string GetName() const;

	bool IsSigned() const;
	void beSigned(Bureaucrat& obj);

	int GetGradeSigne() const;

	int GetGradeExec() const;

	void Execute(Bureaucrat const& obj) const;
	virtual void Execut() const = 0;




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

#endif // AFORM_HPP