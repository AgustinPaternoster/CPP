#include <vector>
#include <string>
class PmergeMe
{
	public:
		void addSequece(char** argv);
		void createPairs(void);
		void orderNumbers(char** av);
	//////
		void print(void);
	
	///////
	class NumberException: public std::exception
	{
		public:
			NumberException(std::string msg);
			virtual ~NumberException(void)throw();
			const char* what() const throw();

		private:
			std::string _errMsg;
	};
	
	private:
		int _struggler;
		std::vector<std::pair<int,int> > _vecPair;
		std::vector<int> _sequence;
		std::vector<int> _mainSequence;
		std::vector<int> _pendSequence;
		std::vector<std::pair<int,int> > _recursiveOrder(std::vector<std::pair<int,int> > vecPair);
		std::vector<std::pair<int,int> > _merge(std::vector<std::pair<int,int> > first, std::vector<std::pair<int,int> > second); 
		void splitPairs(void);
};

