#include "Brain.hpp"
Brain::Brain()
{

}

Brain::~Brain()
{
    cout << "Brain have been destroyed" << endl;
}

Brain::Brain(Brain const &copy)
{
	cout << "Brain copy constructor called" << endl;
	*this = copy;
}

Brain	&Brain::operator=(const Brain &copy)
{
	cout << "Assignment operator for Brain called." << endl;
	int i = 0;
    while (i < 100)
    {
        this->ideas[i] = copy.ideas[i];
        i++;
    }
	return (*this);
}
