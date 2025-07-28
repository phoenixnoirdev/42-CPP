
#ifndef DOG_HPP
#define DOG_HPP

#include "../inc/Animal.hpp"
#include "../inc/Brain.hpp"

class Dog : public Animal
{
    private:
		std::string _FrDogActions[IDEANB];
		std::string _EngDogActions[IDEANB];
		Brain* _Brain;
		void SetIdea();
		void InitIdeaFr();
		void InitIdeaEng();

	public:
		Dog();
		Dog(std::string str);
		Dog(const Dog& obj);
		Dog& operator=(const Dog& other);
		virtual ~Dog();
		virtual void makeSound() const;
		virtual void Idea() const;

};
#endif // DOG_HPP