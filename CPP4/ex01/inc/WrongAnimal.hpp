
#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

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

class WrongAnimal
{
	protected:
		std::string type;
		void setType(std::string str);


	public:
		WrongAnimal();
		WrongAnimal(std::string str);
		WrongAnimal(const WrongAnimal& obj);
		WrongAnimal& operator=(const WrongAnimal& other);
		virtual ~WrongAnimal();
		virtual std::string getType() const;
		virtual void makeSound() const;
};
#endif // WRONGANIMAL_HPP