#include <iostream>
#include <deque>
#include <stack>
int main(void)
{
	// std::deque<int> test;

	// test.push_front(10);
	// test.push_front(12);
	// test.push_front(14);

	// int *i = &test.front();
	// int *e = &test.back();


	// for (int n = 0; n < 3 ; n++)
	// {
	// 	std::cout << "primer valor " << *i << std::endl;
	// 	i++;
	// }
	std::stack<int> test;
	test.push(2);
	test.push(3);
	std::cout << test.top() << std::endl;
	std::stack<int> tt(test);
	std::cout << tt.top() << std::endl;

	return (0);
	
}