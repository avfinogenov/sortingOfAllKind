#include <iostream>
#include <vector>
#include <list>
#include <map>
#include "arrayFilling.h"
#include "arrays.h"
#include "TemplateSort.h"



//debug

void radixSort(std::vector<T>& input);
typedef void (*funcInt_t)(std::vector<int>& input);
typedef void (*funcFloat_t)(std::vector<float>& input);

int main()
{



    //std::vector<int> forSort[16]{ arr1, arr2, arr3, arr4, arr5, arr6, arr7, arr8, arr9, arr10, arr11, arr12, arr13, arr14, arr15, arr16 };

    std::vector<float> forSort;


    std::vector<funcFloat_t> funcs;
    std::vector<std::string> prints;
    prints.push_back("bubble sort\n");
    prints.push_back("selection sort\n");
    prints.push_back("insert sort\n");
    prints.push_back("merge sort\n");
    prints.push_back("quick sort\n");
    //prints.push_back("radix sort\n");
    
    funcs.push_back(&bubbleSort);
    funcs.push_back(&selectionSort);
    funcs.push_back(&insertSort);
    funcs.push_back(&mergeSort);
    funcs.push_back(&quickSort);
    //funcs.push_back(&radixSort);
    
    for (int funcsIndex = 0; funcsIndex < funcs.size(); ++funcsIndex)
    {



        //bubble sort
        std::cout << prints[funcsIndex];
        for (int i = 0; i < 10; ++i)
        {
            std::cout << i << " test\n";
            fillArrayRand(forSort, 10000);
            /*for (int j = 0; j < forSort.size(); ++j)
            {
                std::cout << forSort[j] << " ";
            }
            std::cout << std::endl;*/
            funcs[funcsIndex](forSort);

            /*for (int j = 0; j < forSort.size(); ++j)
            {
                std::cout << forSort[j] << " ";
            }
            std::cout << std::endl;*/
            for (int j = 0; j < forSort.size() - 1; ++j)
            {
                if (forSort[j] > forSort[j + 1])
                {
                    std::cout << "wrong at " << i << " element " << j << std::endl;
                    return 0;
                }
            }
        }
       
        
    }
   

   
    std::cout << "test succes\n";


    
    return 0;
}


void radixSort(std::vector<int>& input)
{
    //array for each digit

    int exponent = 0;//not shure about translation, counter of digits in maximum
    int maximum = input[0];
    bool negative = false;
    for (int i = 0; i < input.size(); ++i)
    {
        maximum = std::max(input[i], maximum);
        if (input[i] < 0)
        {
            negative = true;
        }
    }
    while (maximum > 0)
    {
        maximum = maximum / 10;
        exponent++;
    }
    //iterations for the maximum number of digits in array
    for (int i = 1; i <= exponent; ++i)
    {
        std::vector<int> tmp[10];
        int digitFinder = std::pow(10, i);
        for (int j = 0; j < input.size(); ++j)
        {
            tmp[(std::abs(input[j]) % digitFinder) / (digitFinder / 10)].push_back(input[j]);
        }
        input.erase(input.begin(), input.end());
        //for each digit
        for (int j = 0; j < 10; ++j)
        {
            for (int k = 0; k < tmp[j].size(); ++k)
            {
                input.push_back(tmp[j][k]);
            }
        }


    }
    std::vector<int> forSignSort[2];
    for (int j = 0; j < input.size(); ++j)
    {
        forSignSort[input[j] >= 0].push_back(input[j]);
    }
    input.erase(input.begin(), input.end());

    for (int i = forSignSort[0].size() - 1; i > 0; i--)
    {
        input.push_back(forSignSort[0][i]);
    }
    for (int i = 0; i < forSignSort[1].size(); i++)
    {
        input.push_back(forSignSort[1][i]);
    }



}