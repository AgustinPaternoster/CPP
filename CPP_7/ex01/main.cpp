#include "iter.hpp"

int main(void)
{
	std::string ar[4] = {"uno","dos","tres","cuatro"};
	iter<std::string,4>(ar,print<std::string>);
	int arr[6] = {1,2,3,4,5,6};
	iter<int,6>(arr,print<int>);
	return (0);
}