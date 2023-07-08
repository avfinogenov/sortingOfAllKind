﻿#include <iostream>
#include <vector>
#include "arrays.h"

void bubbleSort(std::vector<int>& input);
void selectionSort(std::vector<int>& input);

int main()
{
    std::vector<int> forSort[15]{ arr1, arr2, arr3, arr4, arr5, arr6, arr7, arr8, arr9, arr10, arr11, arr12, arr13, arr14, arr15 };

    for (int i = 0; i < 15; ++i)
    {
        std::vector<int> asd(forSort[i]);
        asd = forSort[i];
        for (int j = 0; j < forSort[i].size(); ++j)
        {
            std::cout << forSort[i][j] << " ";
        }
        std::cout << std::endl;
        //bubbleSort(forSort[i]);
        selectionSort(forSort[i]);
        for (int j = 0; j < forSort[i].size(); ++j)
        {
            std::cout << forSort[i][j] << " ";
        }
        std::cout << std::endl;
    }


    for (int i = 0; i < 15; ++i)
    {
        for (int j = 0; j < forSort[i].size() - 1; ++j)
        {
            if (forSort[i][j] > forSort[i][j + 1])
            {
                std::cout << "wrong at " << i << " element " << j << std::endl;
                return 0;
            }
        }
    }
    std::cout << "test succes\n";


    std::cout << "Hello world!" << std::endl;
    return 0;
}


void bubbleSort(std::vector<int>& input)
{
    for (int i = 0; i < input.size(); ++i)
    {
        for (int j = 0; j < input.size() - 1; ++j)
        {
            if (input[j] > input[j + 1])
            {
                int tmp = input[j];
                input[j] = input[j + 1];
                input[j + 1] = tmp;
            }

        }
    }


}

void selectionSort(std::vector<int>& input)
{
    for (int i = 0; i < input.size(); ++i)
    {
        int min = input[i];
        for (int j = i; j < input.size(); ++j)
        {
            if (input[j] < min)
            {
                min = input[j];
            }

        }
        input[i] = min;
    }





}