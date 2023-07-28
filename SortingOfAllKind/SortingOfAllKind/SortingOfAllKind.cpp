/**
    arrays.h список готовых массивов для тестирования. На данный момент не используется
    arrayFilling.h набор функций для заполнения массивов для тестирования
    TemplateSort.h набор реализаций сортировок
    todo.h + .cpp функция поразрядной сортировки, которая пока не переписана на шаблоны

    Программа представляет собой тестовый модуль к сортировкам. 
    Сортировки представленны ввиде заголовочного файла, который можно включать в другие проекты.

    Некоторые комментарии на английском. 
    Комментарии на английском - написаны в процессе разработки, на русском - на этапе полировки решения.
*/

#include <iostream>
#include <vector>
#include <list>
#include <map>

#include "arrayFilling.h"
#include "arrays.h"
#include "TemplateSort.h"

typedef void (*funcInt_t)(std::vector<int>& input);
typedef void (*funcFloat_t)(std::vector<float>& input);



int main()
{
    //инициализируем необходимые объекты
    std::vector<float> forSort;

    //массив функций сортировки
    std::vector<funcFloat_t> funcs;
    funcs.push_back(&bubbleSort);
    funcs.push_back(&selectionSort);
    funcs.push_back(&insertSort);
    funcs.push_back(&mergeSort);
    funcs.push_back(&quickSort);
    //funcs.push_back(&radixSort);

    //соответствующие им названия для вывода в консоль
    std::vector<std::string> prints;
    prints.push_back("bubble sort\n");
    prints.push_back("selection sort\n");
    prints.push_back("insert sort\n");
    prints.push_back("merge sort\n");
    prints.push_back("quick sort\n");
    //prints.push_back("radix sort\n");
    
    //тестирование
    for (int funcsIndex = 0; funcsIndex < funcs.size(); ++funcsIndex)
    {
        //выводим имя тестируемой сортировки
        std::cout << prints[funcsIndex];
        //10 итераций тестирования, хотя их можно сделать и больше
        for (int i = 0; i < 10; ++i)
        {
            std::cout << i << " test\n";
            //заполняем массив для тестирования на 10000 элементов
            fillArrayRand(forSort, 10000);
            //выполняем сортировку
            funcs[funcsIndex](forSort);

            //проверяем на условие отсортированного массива
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

