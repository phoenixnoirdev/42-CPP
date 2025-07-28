/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phkevin <phkevin@42luxembourg.lu>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 12:07:40 by phkevin           #+#    #+#             */
/*   Updated: 2025/03/28 12:07:40 by phkevin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <fstream>
#include "AForm.hpp"

//==============================
// LOGO IN LOG
//==============================
#define LOGOSHRUB "ShrubberyCreationForm: "

class ShrubberyCreationForm : public Form
{

	private:
		std::string _target;


	public:
		//==============================
		// CONSTRUCTEUR
		//==============================

		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(ShrubberyCreationForm& obj);
		ShrubberyCreationForm& operator=(ShrubberyCreationForm& obj);
		~ShrubberyCreationForm();



		//==============================
		// FONCTION
		//==============================

	void Execut() const;
};

#endif //SHRUBBERYCREATIONFORM_HPP