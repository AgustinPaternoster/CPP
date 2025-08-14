#include <vector>
#include <iostream>
#include <cmath>

void binarySearch(void)
{
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
	else
		result.insert(result.begin() + indMax, value);
}



std::vector<int> jabobSeq(int size)
{
	std::vector<int> seq;
	int value;
	int i = 2;
	while (true)
	{
		value = (pow(2,i) - pow(-1,i))/3;
		if (value > size)
			break;
		seq.push_back(value);
		i++;
	}
	return seq;
}

void printVec(std::vector<int> vec)
{
	for (std::vector<int>::iterator it = vec.begin(); it!= vec.end(); it++)
	{
		std::cout << "-" << *it << std::endl;
	}
}
std::vector<int> createInsertionSeq(int init, int end , std::vector<int>& seq)
{
	std::vector<int> jSeq;
	std::vector<int> insertionOrder;
	jSeq = jabobSeq(end - init);
	for (std::vector<int>::iterator it = jSeq.begin(); it != jSeq.end(); it++)
		seq.push_back(*it);
	return(insertionOrder);
}

int main(int arc, char** argv)
{
	std::vector<int> seqJacob;
	seqJacob = jabobSeq(11);
	std::vector<int> finalSeq;
	for(std::vector<int>::iterator it = seqJacob.begin(); it != seqJacob.end(); it++)
	{
		if(it == seqJacob.begin())
		{	
			finalSeq.push_back(*it);
			continue;
		}
		if(*it - *(it -1) == 1)
		{
			finalSeq.push_back(*it);
			finalSeq.push_back(*it -1);
		}
		else
		{
			finalSeq.push_back(*it);
			for(int i = *it -1; i > *(it -1); i--)
			{
				finalSeq.push_back(i);
			}
		}
	}
	return(0);
}