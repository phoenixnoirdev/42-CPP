
#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>
#include <iostream>

#define RESET   "\033[0;39m"
#define RED     "\033[0;31m"
#define GREEN   "\033[0;92m"
#define YELLOW  "\033[0;93m"
#define BLUE    "\033[0;34m"
#define MAGENTA "\033[0;35m"
#define CYAN    "\033[0;36m"
#define WHITE   "\033[0;37m"

#define	LANG 		1 //Para disponible ENG / FR
#define	LANG_FR 	1 //FR
#define	LANG_ENG 	2 //ENG

class Animal
{
	protected:
		std::string type;
		void setType(std::string str);
		Animal();
		Animal(std::string str);


	public:
		Animal(const Animal& obj);
		Animal& operator=(const Animal& other);
		virtual ~Animal();
		virtual std::string getType() const;
		virtual void makeSound() const = 0;
		virtual void Idea() const = 0;
};
#endif // ANIMAL_HPP