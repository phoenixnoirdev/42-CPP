
#ifndef CAT_HPP
#define CAT_HPP

#include "../inc/Animal.hpp"
#include "../inc/Brain.hpp"

class Cat : public Animal
{
	private:
		std::string _FrCatActions[IDEANB];
		std::string _EngCatActions[IDEANB];
		Brain* _Brain;
		void SetIdea();
		void InitIdeaFr();
		void InitIdeaEng();

	public:
		Cat();
		Cat(std::string str);
		Cat(const Cat& obj);
		Cat& operator=(const Cat& other);
		virtual ~Cat();
		virtual void makeSound() const;
		virtual void Idea() const;
};
#endif // CAT_HPP