#include "arrayFilling.h"


void fillArrayCont(std::vector<int>& input, int size)
{
	for (int i = 0; i < size; ++i)
	{
		input.push_back(i);
	}

}

void fillArrayRand(std::vector<int>& input, int size)
{
	srand(time(0));
	if (!input.empty())
	{
		input.erase(input.begin(), input.end());
	}
	for (int i = 0; i < size; ++i)
	{
		input.push_back((rand() % 1000) - 500);
	}
	
}