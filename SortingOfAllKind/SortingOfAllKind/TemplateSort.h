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


// сортировка пузырьком для любого числового вектора
template <typename T>
void bubbleSort(std::vector<T>& input)
{
    //проходим по всему массиву в квадрате и на каждый проход меняем местами соседние элементы, удовлетворяющие условие
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



// сортировка выбором для любого числового вектора
template <typename T>
void selectionSort(std::vector<T>& input)
{
    // за каждую итерацию первого цикла находится самый левый элемент, 
    // и затем сортируется уже меньший массив (j = i) во втором цикле
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



//сортировка вставкой для любого числового вектора
template <typename T>
void insertSort(std::vector<T>& input)
{
    // идея в том, чтобы из входного массива вытаскивать элементы в новый, сразу в упорядоченном виде

    //забираем первый элемент
    std::vector<T> tmp;
    tmp.push_back(input[0]);
    input.erase(input.begin());

    //идем по входному массиву, пока он не кончится
    int i = 0;
    while (!input.empty())
    {
        //особая ситуация для первого сравнения (похоже на костыль)
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
            // если следующий элемент на добавление больше крайнего правого в отсортированном массиве - просто вставляем его
            tmp.push_back(input[0]);
        }
        else
        {
            // иначе ищем ему место
            while (i >= 0 && input[0] < tmp[i])
            {
                --i;
            }

            tmp.insert(tmp.begin() + (i + 1), input[0]);
        }

        //удаляем отработанный элемент
        input.erase(input.begin());
        //=)
        i = tmp.size() - 1;
    }

    // в возвращаемый массив перекладываем упорядоченный (мб имеет смысл уточнить как работает оператор = у векторов)
    input = tmp;

}



// рекурсивная сортировка слиянием для любого числового вектора
template <typename T>
void mergeSort(std::vector<T>& input)
{
    // идея в том, чтобы разбить массивы на половинки и отсортировать их в меньшем размере,
    // и затем изза того что они уже частично упорядоченны из них быстрее собирается большой массив

    //условие выхода из рекурсии
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
    
    
    //пока хотя бы один не опустеет
    while (!l.empty() && !r.empty())
    {
        // что меньше забиваем в результат
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

    // что осталось то, уже упорядочено, просто забиваем до конца (возможна потеря скорости изза постоянного переписывания вектора)
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
    //результат на выход
    input = result;
}



// перевод интерфейса для тестовой системы, этот нужен тесту, а тот для выполнения функции 
template <typename T>
void quickSort(std::vector<T>& inputV)
{
    int size = inputV.size();
    T* input = &inputV[0];
    quickSort(input, size);

}



// рекурсивная быстрая сортировка для любого числового вектора
template <typename T>
void quickSort(T* input, int size)
{
    // идея в том, чтобы найти узел, который уже на своем месте и расставить другие элементы так, 
    //чтобы они оказались по ту сторону от него, в которой они будут в итоге
    
    // первый элемент берется случайно в середине массива
    int pivotIndex = size / 2;
    int endIndex = size - 1;
    if (size > 2)
    {
        // находим узел
        T l, m, r;
        l = input[0];
        r = input[endIndex];
        m = input[pivotIndex];
        input[0] = std::min(l, std::min(r, m));
        input[endIndex] = std::max(l, std::max(r, m));
        // (x + y + z) - z - y = x
        input[pivotIndex] = l + r + m - (input[0] + input[endIndex]);
        if (size == 3)
        {
            //идея в том, что предыдущий код выполняет сортировку для трех элементов и из рекурсии можно выходить уже тут
            return;
        }
    }
    else
    {
        if (size == 1)
        {
            //выходим из рекурсии
            return;
        }
        if (size == 2)
        {
            //сортируем и выходим из рекурсии
            T max = std::max(input[0], input[1]);
            T min = std::min(input[0], input[1]);
            input[0] = min;
            input[1] = max;
            return;

        }

    }

    /* 
        думаю стоит пояснить про магию.
        endIndex - индекс последнего элемента, получается в начале
        pivotIndex - так же соответственно
        pivotFinalPosition - память под финальный индекс узла (который не будет менятся до конца сортировки)

        в самом конце массива (чтобы не мешал) лежит наш узел

        мы по очереди ищем элементы от начала массива больше узла
        и справа - меньше узла
        и меняем их местами
        как только индекс смещения справа меньше индекса слева это и есть искомый финальный индекс узла

        после этого остается только отсортировать части справа и слева от узла
    */


    //do pivot magic 
    //move pivot to the right corner 
    std::swap(input[pivotIndex], input[endIndex]);
    int pivotFinalPosition;

    while (true)
    {
        int i = 0;
        int j = endIndex - 1;
        // find left greater

        // идем слева (см комент выше со звездочкой)
        while (input[i] <= input[endIndex] && i < endIndex)
        {
            ++i;
        }


        // find right smaller
        // идем справа (см комент выше со звездочкой)
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
    if (size - pivotFinalPosition - 1 > 0)
    {
        quickSort(&input[pivotFinalPosition + 1], size - pivotFinalPosition - 1);

    }


}




//debug
//вспомогательная отладочная функция, проверяет действительно ли узел на нужном месте
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



