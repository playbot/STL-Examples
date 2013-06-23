/* 
 * File:   f2.h
 * Author: konstantin
 *
 * Created on 29 Сентябрь 2012 г., 17:54
 */

#ifndef _F2_H
#define	_F2_H



#endif	/* _F2_H */

#include <vector>
#include <algorithm>
#include "monstr.h"
#include "print_monstr.h"

/*
Алгоритм for_each вызывает для каждого элемента последовательности
заданную функцию (функциональный объект).
*/
class over50
{
public:
    bool operator()(const monstr& M)const
    {
        return M.get_health()>50;
    }
};

bool f50 (monstr& M)
{
    return M.get_health()>50;
}

void f2()
{
    std::vector<monstr> vector_monstr(5, monstr(50, "goblin"));
    monstr Sauron(800, "Sauron");
    vector_monstr.push_back(Sauron);
    std::for_each(vector_monstr.begin(), vector_monstr.end(), print_monstr(vector_monstr));
    std::cout << std::count_if(vector_monstr.begin(), vector_monstr.end(), f50) << std::endl;

}
