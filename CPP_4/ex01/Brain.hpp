#ifndef __BRAIN_H__
#define __BRAIN_H__
#include <string>

class Brain
{
	public:
		Brain(void);
		Brain(const Brain& rsc);
		~Brain(void);

		Brain& operator=(const Brain& rsc);
		std::string getIdea(int ideaNb);
		void setIdea(std::string idea);		
		
		private:
			enum {NB_IDEAS = 100 };
			std::string _ideas[NB_IDEAS];
			int _getNbIdeas(void);
};

#endif