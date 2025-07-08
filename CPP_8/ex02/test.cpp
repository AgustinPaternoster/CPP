#include <iostream>
#include <deque>
int main(void)
{
	std::deque<int> test;

	test.push_front(10);
	test.push_front(12);
	test.push_front(14);

	int *i = &test.front();
	int *e = &test.back();


	for (int n = 0; n < 3 ; n++)
	{
		std::cout << "primer valor " << *i << std::endl;
		i++;
	}
	return (0);
	
}