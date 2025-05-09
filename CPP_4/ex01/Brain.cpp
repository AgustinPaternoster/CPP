#include "Brain.hpp"
#include <iostream>

Brain::Brain(void)
{
	std::cout << "Brain is created" << std::endl;
}

Brain::Brain(const Brain& rsc)
{
	*this = rsc;
}

Brain::~Brain(void)
{
	std::cout << "Brain is destroyed" << std::endl;	
}

Brain& Brain::operator=(const Brain& rsc)
{
	if (this != &rsc)
	{
		for (int i = 0 ; i < NB_IDEAS ; i++)
		{
			this->_ideas[i] = rsc._ideas[i];
		}
	}
	return(*this);
}


std::string Brain::getIdea(int ideaNb)
{
	if (_getNbIdeas() == 0 && ideaNb > 0 )
		return ("no ideas created");
	if (ideaNb > _getNbIdeas())
		return ("no idea with this number");
	if (ideaNb <= 0)
		return ("wrong number" );
	return(_ideas[ideaNb - 1]);
}

void Brain::setIdea(std::string idea)
{
	int nb = _getNbIdeas();
	if ( nb == NB_IDEAS)
		std::cout << "no more space for idea: " << idea << std::endl;
	else
		_ideas[nb] = idea;
}

int Brain::_getNbIdeas(void)
{
	int i = 0;
	while(!_ideas[i].empty() && i < NB_IDEAS)
		i++;
	return (i);
}

