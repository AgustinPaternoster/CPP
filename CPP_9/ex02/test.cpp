#include <vector>
#include <iostream>

int main(int arc, char** argv)
{
	///////////////////////////0 -1 - 2 -3  - 4 - 5 - 6 - 7
	std::vector<int> result = {3, 7, 12, 18, 25, 31, 40 , 56};
	// std::vector<int> values = {8, 36 , 0};
	int value = 50;
	int indMin = 0;
	int indMax =  result.size() - 1;
	int middle;
	while(indMin != indMax)
	{
		middle = (indMin + indMax) / 2;
		if(value > result[middle])
			indMin = middle + 1;
		else
			indMax = middle - 1;
	}
	if (value <= result[indMax])
		result.insert(result.begin() + indMax, value);

	return (0);
}