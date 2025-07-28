/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phkevin <phkevin@42luxembourg.lu>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 12:07:42 by phkevin           #+#    #+#             */
/*   Updated: 2025/03/28 12:07:42 by phkevin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include <ctime>
#include <cstdlib>
#include "AForm.hpp"

//==============================
// LOGO IN LOG
//==============================
#define LOGOROB "Robotomy: "

class RobotomyRequestForm : public Form
{

	private:
		std::string _target;


	public:
		//==============================
		// CONSTRUCTEUR
		//==============================

		RobotomyRequestForm();
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(RobotomyRequestForm& obj);
		RobotomyRequestForm& operator=(RobotomyRequestForm& obj);
		~RobotomyRequestForm();



		//==============================
		// FONCTION
		//==============================

		void Execut() const;
};

#endif //ROBOTOMYREQUESTFORM_HPP