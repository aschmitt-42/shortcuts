#include "ss.hpp"

ss::ss()
{
	std::cout << "Default constructor called" << std::endl;
}
ss::~ss()
{
	std::cout << "Destructor called" << std::endl;
}
ss::ss(const ss&other)
{
	std::cout << "Recopy constructor called" << std::endl;
}
ss& ss::operator=(const ss &other)
{
	std::cout << "Assignment operator called" << std::endl;
}
