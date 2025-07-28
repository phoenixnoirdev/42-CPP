#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <fstream>
#include "../inc/AForm.hpp"

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