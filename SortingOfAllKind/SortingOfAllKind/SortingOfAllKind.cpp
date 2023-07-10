#include <iostream>
#include <vector>
#include <list>
#include "arrayFilling.h"
#include "arrays.h"

void bubbleSort(std::vector<int>& input);
void selectionSort(std::vector<int>& input);
void insertSort(std::vector<int>& input);
void mergeSort(std::vector<int>& input);
void quickSort(int* input, int size);
void radixSort(std::vector<int>& input);

//debug
bool checkPivot(int* input, int pivotPosition, int size);

int main()
{
    //std::vector<int> forSort[16]{ arr1, arr2, arr3, arr4, arr5, arr6, arr7, arr8, arr9, arr10, arr11, arr12, arr13, arr14, arr15, arr16 };

    std::vector<int> forSort;
    

    //bubble sort
    std::cout << "bubble sort\n";
    for (int i = 0; i < 10; ++i)
    {
        std::cout << i << " test\n";
        fillArrayRand(forSort, 1000);
        /*for (int j = 0; j < forSort.size(); ++j)
        {
            std::cout << forSort[j] << " ";
        }
        std::cout << std::endl;*/
        bubbleSort(forSort);
        
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
    //selection sort
    std::cout << "selection sort\n";
    for (int i = 0; i < 10; ++i)
    {
        std::cout << i << " test\n";
        fillArrayRand(forSort, 1000);
        /*for (int j = 0; j < forSort.size(); ++j)
        {
            std::cout << forSort[j] << " ";
        }
        std::cout << std::endl;*/
        selectionSort(forSort);
        
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
    //insert sort
    std::cout << "insert sort\n";
    for (int i = 0; i < 10; ++i)
    {
        std::cout << i << " test\n";
        fillArrayRand(forSort, 1000);
        /*for (int j = 0; j < forSort.size(); ++j)
        {
            std::cout << forSort[j] << " ";
        }
        std::cout << std::endl;*/
        insertSort(forSort);
        
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
    //merge sort
    std::cout << "merge sort\n";
    for (int i = 0; i < 10; ++i)
    {
        std::cout << i << " test\n";
        fillArrayRand(forSort, 1000);
        /*for (int j = 0; j < forSort.size(); ++j)
        {
            std::cout << forSort[j] << " ";
        }
        std::cout << std::endl;*/
        mergeSort(forSort);
        
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
    //quick sort
    std::cout << "quick sort\n";
    for (int i = 0; i < 10; ++i)
    {
        std::cout << i << " test\n";
        fillArrayRand(forSort, 1000);
        /*for (int j = 0; j < forSort.size(); ++j)
        {
            std::cout << forSort[j] << " ";
        }
        std::cout << std::endl;*/
        quickSort(&forSort[0], forSort.size());
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
    //radix sort
    std::cout << "radix sort\n";
    for (int i = 0; i < 10; ++i)
    {
        std::cout << i << " test\n";
        fillArrayRand(forSort, 1000);
        /*for (int j = 0; j < forSort.size(); ++j)
        {
            std::cout << forSort[j] << " ";
        }
        std::cout << std::endl;*/
        
        radixSort(forSort);
       /* for (int j = 0; j < forSort.size(); ++j)
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


   
    std::cout << "test succes\n";


    
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
        if (size == 3)
        {
            return;
        }
    }
    else
    {
        if (size == 1)
        {
            return;
        }
        if (size == 2)
        {
            int max = std::max(input[0], input[1]);
            int min = std::min(input[0], input[1]);
            input[0] = min;
            input[1] = max;
            return;

        }
        
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
    
   /* bool tmp = checkPivot(&input[0], pivotFinalPosition, size - pivotFinalPosition - 1);

    if (!tmp)
    {
        std::cout << "find ya\n";
    }*/
    quickSort(&input[0], pivotFinalPosition);
    if (size - pivotFinalPosition - 1 > 0)
    {
        quickSort(&input[pivotFinalPosition + 1], size - pivotFinalPosition - 1);

    }
    

}
//debug
bool checkPivot(int* input, int pivotPosition, int size)
{
    int pivot = input[pivotPosition];
    for (int i = 0; i < pivotPosition; ++i)
    {
        if (input[i] > pivot)
        {
            return false;
        }
    }

    for (int i = pivotPosition + 1; i < pivotPosition + 1 + size; ++i)
    {
        if (pivot > input[i])
        {
            return false;
        }
    }
    return true;
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