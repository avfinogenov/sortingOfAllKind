#include <iostream>
#include <vector>
#include <list>
#include "arrays.h"

void bubbleSort(std::vector<int>& input);
void selectionSort(std::vector<int>& input);
void insertSort(std::vector<int>& input);
void mergeSort(std::vector<int>& input);
void quickSort(int* input, int size);

int main()
{
    std::vector<int> forSort[16]{ arr1, arr2, arr3, arr4, arr5, arr6, arr7, arr8, arr9, arr10, arr11, arr12, arr13, arr14, arr15, arr16 };

    for (int i = 0; i < 16; ++i)
    {
        std::vector<int> asd(forSort[i]);
        asd = forSort[i];
        for (int j = 0; j < forSort[i].size(); ++j)
        {
            std::cout << forSort[i][j] << " ";
        }
        std::cout << std::endl;
        //bubbleSort(forSort[i]);
        //selectionSort(forSort[i]);
        //insertSort(forSort[i]);
        //mergeSort(forSort[i]);
        quickSort(&forSort[i][0], forSort[i].size());
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

void insertSort(std::vector<int>& input)
{
    std::vector<int> tmp;
    tmp.push_back(input[0]);
    input.erase(input.begin());
  
    int i = 0;
    while (!input.empty())
    {
        if (i == 0)
        {
            if (input[0] < tmp[i])
            {
                tmp.insert(tmp.begin(), input[0]);
                input.erase(input.begin());
                ++i;
                continue;
            }
        }
   
    
        if (input[0] > tmp[i])
        {
            tmp.push_back(input[0]);
        }
        else
        {
            while (i >= 0 && input[0] < tmp[i])
            {
                --i;
            }

            tmp.insert(tmp.begin() + (i + 1), input[0]);
        }
            

        input.erase(input.begin());
        i = tmp.size() - 1;
    }

    input = tmp;

}



void mergeSort(std::vector<int>& input)
{
    if (input.size() == 1)
    {
        return;
    }
    //забить в них по пол массива
    std::vector<int> l(input.begin(), input.begin() + input.size() / 2);
    std::vector<int> r(input.begin() + input.size() / 2, input.end());
    mergeSort(l);
    mergeSort(r);
    std::vector<int> result;
    while (!l.empty() && !r.empty())
    {
        if (l[0] > r[0])
        {
            result.push_back(r[0]);
            r.erase(r.begin());
        }
        else
        {
            result.push_back(l[0]);
            l.erase(l.begin());
        }
    }
    while (!l.empty())
    {
        result.push_back(l[0]);
        l.erase(l.begin());

    }
    while (!r.empty())
    {
        result.push_back(r[0]);
        r.erase(r.begin());

    }
    input = result;
}


void quickSort(int* input, int size)
{
    //find a pivot
    int pivotIndex = size / 2;
    int endIndex = size - 1;
    if (size > 2)
    {
        int l, m, r;
        l = input[0];
        r = input[endIndex];
        m = input[pivotIndex];
        input[0] = std::min(l, std::min(r, m));
        input[endIndex] = std::max(l, std::max(r, m));
        input[pivotIndex] = l + r + m - (input[0] + input[endIndex]);
    }
    else
    {
        return;
    }
    //do pivot magic
    //move pivot to the right corner
    std::swap(input[pivotIndex], input[endIndex]);
    int pivotFinalPosition;
    
    while (true)
    {
        int i = 0;
        int j = endIndex - 1;
        // find left greater
        
        while (input[i] <= input[endIndex] && i < endIndex)
        {
            ++i;
        }


        // find right smaller
        
        while (input[j] > input[endIndex] && j > 0)
        {
            j--;
        }
        if (i > j)
        {
            // return pivot
            pivotFinalPosition = i;
            std::swap(input[i], input[endIndex]);
            break;
        }
        std::swap(input[i], input[j]);


    }
    
    //split array by pivot
    
    quickSort(&input[0], pivotFinalPosition);
    quickSort(&input[pivotFinalPosition + 1], size - pivotFinalPosition - 1);

}