#pragma once

#include <iostream>
#include <vector>
#include <list>
#include <map>
#include "arrayFilling.h"
#include "arrays.h"
template <typename T>
void bubbleSort(std::vector<T>& input);
template <typename T>
void selectionSort(std::vector<T>& input);
template <typename T>
void insertSort(std::vector<T>& input);
template <typename T>
void mergeSort(std::vector<T>& input);
template <typename T>
void quickSort(std::vector<T>& inputV);
template <typename T>
void quickSort(T* input, int size);
template <typename T>
bool checkPivot(T* input, int pivotPosition, int size);





template <typename T>
void bubbleSort(std::vector<T>& input)
{
    for (int i = 0; i < input.size(); ++i)
    {
        for (int j = 0; j < input.size() - 1; ++j)
        {
            if (input[j] > input[j + 1])
            {
                T tmp = input[j];
                input[j] = input[j + 1];
                input[j + 1] = tmp;
            }

        }
    }


}
template <typename T>
void selectionSort(std::vector<T>& input)
{



    for (int i = 0; i < input.size(); ++i)
    {
        T min = input[i];
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


template <typename T>
void insertSort(std::vector<T>& input)
{
    std::vector<T> tmp;
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


template <typename T>
void mergeSort(std::vector<T>& input)
{
    if (input.size() == 1)
    {
        return;
    }
    //забить в них по пол массива
    std::vector<T> l(input.begin(), input.begin() + input.size() / 2);
    std::vector<T> r(input.begin() + input.size() / 2, input.end());
    mergeSort(l);
    mergeSort(r);
    std::vector<T> result;
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


template <typename T>
void quickSort(std::vector<T>& inputV)
{
    int size = inputV.size();
    T* input = &inputV[0];
    quickSort(input, size);

}

template <typename T>
void quickSort(T* input, int size)
{

    //find a pivot
    int pivotIndex = size / 2;
    int endIndex = size - 1;
    if (size > 2)
    {
        T l, m, r;
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
            T max = std::max(input[0], input[1]);
            T min = std::min(input[0], input[1]);
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

template <typename T>
bool checkPivot(T* input, int pivotPosition, int size)
{
    T pivot = input[pivotPosition];
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



