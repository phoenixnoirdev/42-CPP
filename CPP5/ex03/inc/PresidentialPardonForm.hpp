/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phkevin <phkevin@42luxembourg.lu>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 12:07:44 by phkevin           #+#    #+#             */
/*   Updated: 2025/03/28 12:07:44 by phkevin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

//==============================
// LOGO IN LOG
//==============================
#define LOGOPRE "PresidentialPardon: "


class PresidentialPardonForm : public Form
{

	private:
		std::string _target;


	public:
		//==============================
		// CONSTRUCTEUR
		//==============================

		PresidentialPardonForm();
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(PresidentialPardonForm& obj);
		PresidentialPardonForm& operator=(PresidentialPardonForm& obj);
		~PresidentialPardonForm();


		//==============================
		// FONCTION
		//==============================

		void Execut() const;
};

#endif //PRESIDENTIALPARDONFORM_HPP