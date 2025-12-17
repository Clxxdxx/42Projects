#ifndef BRAIN_HPP
#define BRAIN_HPP
#include <iostream>
#include <string>
typedef std::string string;
using std::cout;
using std::endl;


class Brain {

protected:
    string ideas[100];
public:
    Brain(void);
	Brain(Brain const &copy);
	~Brain(void);
    Brain &operator=(Brain const &copy);
};




#endif