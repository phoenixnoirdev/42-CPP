
#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "../inc/WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
	public:
		WrongCat();
		WrongCat(std::string str);
		WrongCat(const WrongCat& obj);
		WrongCat& operator=(const WrongCat& obj);
		virtual ~WrongCat();
		virtual void makeSound() const;
};
#endif // WRONGCAT_HPP