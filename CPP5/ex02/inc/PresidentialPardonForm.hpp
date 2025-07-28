#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "../inc/AForm.hpp"

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