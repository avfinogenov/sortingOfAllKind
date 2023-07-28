#ifndef ARRAY_FILLING
#define ARRAY_FILLING

#include <iostream>
#include <vector>
#include <random>

template <typename T>
void fillArrayRand(std::vector<T>& input, int size);
template <typename T>
void fillArrayCont(std::vector<T>& input, int size);


//заполняет массив последовательными значениями, если массив не пуст, очищает его
template <typename T>
void fillArrayCont(std::vector<T>& input, int size)
{
	if (!input.empty())
	{
		input.erase(input.begin(), input.end());
	}
	for (int i = 0; i < size; ++i)
	{
		input.push_back((T)i);
	}
}


//заполняет массив случайными значениями, если массив не пуст, очищает его
template <typename T>
void fillArrayRand(std::vector<T>& input, int size)
{
	srand(time(0));
	if (!input.empty())
	{
		input.erase(input.begin(), input.end());
	}
	for (int i = 0; i < size; ++i)
	{
		input.push_back((T)((rand() % 1000) - 500));
	}
}
#endif // !ARRAY_FILLING
