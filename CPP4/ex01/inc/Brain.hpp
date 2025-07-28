
#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>
#include <iostream>
#include <cstdlib>
#include <ctime>

#define RESET   "\033[0;39m"
#define RED     "\033[0;31m"
#define GREEN   "\033[0;92m"
#define YELLOW  "\033[0;93m"
#define BLUE    "\033[0;34m"
#define MAGENTA "\033[0;35m"
#define CYAN    "\033[0;36m"
#define WHITE   "\033[0;37m"

#define	IDEANB 100

class Brain
{
	private:
		std::string	_idea[IDEANB];

	public:
		Brain();
		Brain(const Brain& obj);
		Brain& operator=(const Brain& other);
		~Brain();
		void GetIdea(std::string type);
		void SetIdea(std::string str, int ref);
		void GetListeIdea();
};
#endif // BRAIN_HPP