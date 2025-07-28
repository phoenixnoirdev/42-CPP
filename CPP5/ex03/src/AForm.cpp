/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phkevin <phkevin@42luxembourg.lu>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 12:07:31 by phkevin           #+#    #+#             */
/*   Updated: 2025/03/28 12:07:31 by phkevin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

//==============================
// CONSTRUCTEUR
//==============================
/**
 * @brief Constructeur par d�faut de la classe Form.
 *
 * Ce constructeur initialise les attributs de l'objet Form avec des valeurs par d�faut :
 * - Le nom du formulaire est d�fini sur "FormDefault".
 * - Le formulaire n'est pas sign� par d�faut (_sign = false).
 * - Le grade n�cessaire pour signer et ex�cuter est d�fini � 1.
 *
 * Il affiche �galement un message indiquant que le constructeur par d�faut a �t� appel�.
 */
Form::Form() : _name("FormDefault"), _sign(false), _gradeToSign(1), _gradeToExe(1)
{
	std::cout << GREEN << "Form: " << RESET << "Default constructor called" << std::endl;
}

/**
 * @brief Constructeur param�tr� de la classe Form.
 *
 * Ce constructeur initialise un objet Form avec des valeurs personnalis�es pour le nom, le grade requis pour signer et ex�cuter :
 * - Le nom du formulaire est d�fini par le param�tre `name`.
 * - Le formulaire n'est pas sign� par d�faut (_sign = false).
 * - Le grade n�cessaire pour signer est d�fini par `gradeSign`.
 * - Le grade n�cessaire pour ex�cuter est d�fini par `gradeExe`.
 *
 * Avant de finaliser la cr�ation de l'objet, il v�rifie si les grades fournis pour la signature et l'ex�cution sont valides en appelant la fonction `IsLimitGrade` pour chaque grade.
 *
 * Il affiche �galement un message indiquant que le constructeur param�tr� a �t� appel�.
 *
 * @param name Le nom du formulaire.
 * @param gradeSign Le grade requis pour signer le formulaire.
 * @param gradeExe Le grade requis pour ex�cuter le formulaire.
 */
Form::Form(std::string name, int gradeSign, int gradeExe) : _name(name), _sign(false), _gradeToSign(gradeSign), _gradeToExe(gradeExe)
{
	IsLimitGradeInit(name, "signer", gradeSign);
	IsLimitGradeInit(name, "executer", gradeExe);

	std::cout << GREEN << "Form: " << RESET << "Default constructor called" << std::endl;
}

/**
 * @brief Constructeur de copie de la classe Form.
 *
 * Ce constructeur cr�e une copie d'un objet Form existant. Les valeurs de l'objet source `obj` sont copi�es dans le nouvel objet :
 * - Le nom est copi� via `obj.GetName()`.
 * - L'�tat de signature est copi� via `obj.IsSigned()`.
 * - Le grade requis pour signer est copi� via `obj.GetGradeSigne()`.
 * - Le grade requis pour ex�cuter est copi� via `obj.GetGradeExec()`.
 *
 * Un message indiquant que le constructeur de copie a �t� appel� est �galement affich�.
 *
 * @param obj L'objet Form � copier.
 */
Form::Form(Form& obj) : _name(obj.GetName()), _sign(obj.IsSigned()), _gradeToSign(obj.GetGradeSigne()), _gradeToExe(obj.GetGradeExec())
{
	std::cout << GREEN << "Form: " << RESET << "Copy constructor called" << std::endl;
}

/**
 * @brief Surcharge de l'op�rateur d'assignation pour la classe Form.
 *
 * Cette m�thode permet de copier les donn�es d'un objet Form dans un autre objet Form.
 * Elle v�rifie d'abord que l'objet � affecter n'est pas lui-m�me (pour �viter une auto-affectation),
 * puis affecte les valeurs des attributs membres de l'objet source � l'objet courant.
 * Elle affiche un message indiquant que l'op�rateur d'assignation a �t� appel�.
 *
 * @param obj L'objet Form � copier.
 * @return Form& L'objet courant apr�s l'affectation.
 */
Form& Form::operator=(Form& obj)
{
	if (this != &obj)
		*this = obj;

	std::cout << GREEN << "Form: " << RESET << "Operator constructor called" << std::endl;

	return *this;
}

/**
 * @brief Destructeur de la classe Form.
 *
 * Le destructeur est appel� lorsque l'objet Form est d�truit. Il affiche un message indiquant
 * que le destructeur a �t� appel� pour l'objet, mais n'effectue aucune autre action sp�cifique
 * de nettoyage, car aucun tableau dynamique ou ressource sp�cifique n'est allou� pour cet objet.
 */
Form::~Form()
{
	std::cout << GREEN << "Form: " << RESET << "Destructor called" << std::endl;
}



//==============================
// FONCTION
//==============================
/**
 * @brief Accesseur pour le nom de la Form.
 *
 * Cette m�thode retourne le nom de la Form.
 *
 * @return std::string Le nom de la Form.
 */
std::string Form::GetName() const
{
	return this->_name;
}

/**
 * @brief V�rifie si la Form est sign�e.
 *
 * Cette m�thode retourne un bool�en indiquant si la Form est sign�e ou non.
 *
 * @return bool true si la Form est sign�e, false sinon.
 */
bool Form::IsSigned() const
{
	return this->_sign;
}

/**
 * @brief Tente de signer la Form avec un Bureaucrat.
 *
 * Cette m�thode permet � un Bureaucrat de signer la Form, � condition qu'il ait
 * un grade suffisant (inf�rieur ou �gal au grade requis pour signer la Form).
 * Si la Form est d�j� sign�e, un message l'indiquant est affich�. Si le Bureaucrat
 * ne poss�de pas le grade requis, un message d'erreur est affich�.
 *
 * @param obj Le Bureaucrat qui tente de signer la Form.
 */
void Form::beSigned(Bureaucrat& obj)
{
	if (obj.GetGrade() <= this->GetGradeSigne())
	{
		if (this->IsSigned() == true)
		{
			obj.signForm(this, "le document a deja ete signer.");

			return;
		}

		this->_sign = true;

		obj.signForm(this, "");

		return;
	}

	obj.signForm(this, "car il n'a pas le niveau requis.");
	throw GradeException("Form - <<" + this->GetName() + ">> ne peu etre signer par le bureaucrat <<" + obj.GetName() + ">> car il n'a pas le niveau requis.");

	return;
}

/**
 * @brief R�cup�re le grade n�cessaire pour signer la Form.
 *
 * Cette m�thode retourne le grade requis pour qu'un Bureaucrat puisse signer la Form.
 * Un Bureaucrat doit avoir un grade inf�rieur ou �gal � ce grade pour pouvoir signer.
 *
 * @return Le grade n�cessaire pour signer la Form.
 */
int Form::GetGradeSigne() const
{
	return this->_gradeToSign;
}

/**
 * @brief R�cup�re le grade n�cessaire pour ex�cuter la Form.
 *
 * Cette m�thode retourne le grade requis pour qu'un Bureaucrat puisse ex�cuter la Form.
 * Un Bureaucrat doit avoir un grade inf�rieur ou �gal � ce grade pour pouvoir ex�cuter.
 *
 * @return Le grade n�cessaire pour ex�cuter la Form.
 */
int Form::GetGradeExec() const
{
	return this->_gradeToExe;
}

/**
 * @brief V�rifie si le grade est dans les limites autoris�es pour une Form.
 *
 * Cette m�thode v�rifie que le grade fourni est dans les limites acceptables pour la Form.
 * Si le grade est inf�rieur au grade minimum ou sup�rieur au grade maximum, une exception est lanc�e.
 *
 * @param name Le nom de la Form (pour personnaliser l'erreur).
 * @param type Le type d'utilisateur (par exemple, "signer" ou "ex�cuter").
 * @param grade Le grade � v�rifier.
 *
 * @throws GradeException Si le grade est en dehors des limites autoris�es.
 */
void Form::IsLimitGradeInit(std::string name, std::string type, int grade)
{
	if (grade < GRADE_MIN)
		throw GradeException("Form - " + name + ": grade trop petit pour " + type);
	if (grade > GRADE_MAX)
		throw GradeException("Form - " + name + ": grade trop grand pour " + type);
}

/**
 * @brief Surcharge de l'op�rateur d'affichage pour la classe Form.
 *
 * Cette m�thode permet d'afficher les informations relatives � un objet Form. Elle affiche
 * le nom de la Form, son grade de signature et son grade d'ex�cution.
 *
 * @param os Le flux de sortie o� les informations seront affich�es.
 * @param obj L'objet Form � afficher.
 *
 * @return Le flux de sortie modifi�.
 */
std::ostream& operator<<(std::ostream& os, Form& obj)
{
	os << GREEN << "Form: " << RESET << "Form " << GREEN << obj.GetName() << RESET << ", grade de signature " << GREEN << obj.GetGradeSigne() << RESET << ", grade execution " << GREEN << obj.GetGradeExec() << RESET << " - etat signature: " << GREEN << obj.IsSigned() << RESET << std::endl;
	return os;
}

/**
 * @brief Ex�cute l'action associ�e au formulaire si les conditions sont remplies.
 *
 * Cette m�thode v�rifie d'abord si le formulaire a �t� sign�. Si ce n'est pas le cas,
 * une exception de type `GradeException` est lanc�e. Ensuite, elle v�rifie si le Bureaucrat
 * a un grade suffisamment �lev� pour ex�cuter le formulaire. Si ces deux conditions sont
 * remplies, l'action associ�e au formulaire est ex�cut�e.
 *
 * @param obj Le Bureaucrat tentant d'ex�cuter le formulaire.
 * @throws GradeException Si le formulaire n'est pas sign� ou si le grade du Bureaucrat
 *         est insuffisant pour l'ex�cution.
 */
void Form::Execute(Bureaucrat const& obj) const
{
	if (this->IsSigned() == false)
		throw GradeException("Form - <<" + this->GetName() + ">> n'est pas signer, une signature est requis.");
	if (this->GetGradeExec() < obj.GetGrade())
		throw GradeException("Form - <<" + this->GetName() + ">> votre grade n'a pas le niveau minimum requis pour l'execution.");

	this->Execut();
}
