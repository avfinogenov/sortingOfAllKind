#include "todo.h"


//поразрядная сортировка для вектора на интах
void radixSort(std::vector<int>& input)
{
    /*
        идея в том, чтобы вычислить максимальное количество разрядов, возможных в массиве
        затем по очереди разбивать на группы по текущему разряду(с младшего выглядит более разумно)
        в итоге при переходе к следующему разряду, элементы будут уже упорядочены по прошлому разряду
        в конце при соединении в один массив они будут упорядоченны по старшему
    
        в этой функции магическое число 10 - количество цифр в десятичной системе счисления
    */


    //array for each digit

    int exponent = 0;//not shure about translation, counter of digits in maximum
    int maximum = input[0];
    bool negative = false;
    //находим максимум
    for (int i = 0; i < input.size(); ++i)
    {
        maximum = std::max(input[i], maximum);
        if (input[i] < 0)
        {
            negative = true;
        }
    }

    //находим количество разрядов
    while (maximum > 0)
    {
        maximum = maximum / 10;
        exponent++;
    }

    //  разбираем на группы
    for (int i = 1; i <= exponent; ++i)
    {
        std::vector<int> tmp[10];
        int digitFinder = std::pow(10, i);
        for (int j = 0; j < input.size(); ++j)
        {
            //формула превращает интересующий нас разряд в индекс, соответствующий группе этого числа
            tmp[(std::abs(input[j]) % digitFinder) / (digitFinder / 10)].push_back(input[j]);
        }
        input.erase(input.begin(), input.end());
        // собираем назад
        
        for (int j = 0; j < 10; ++j)
        {
            for (int k = 0; k < tmp[j].size(); ++k)
            {
                input.push_back(tmp[j][k]);
            }
        }


    }


    // отдельно для сортировки по знаку
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