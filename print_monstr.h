/* 
 * File:   print_vector.h
 * Author: konstantin
 *
 * Created on 29 Сентябрь 2012 г., 17:50
 */

#ifndef _PRINT_VECTOR_H
#define	_PRINT_VECTOR_H


#endif	/* _PRINT_VECTOR_H */

#include "monstr.h"
#include <vector>
#include <iostream>

class print_monstr
{
    std::vector<monstr>& v;
public:
    explicit print_monstr(std::vector<monstr>& vms) : v(vms){}
    void operator()(const monstr& M) const
    {
        std::cout << "Monster health: " << M.get_health() << std::endl
             << "Monster name: "   << M.get_name()   << std::endl << std::endl;
    }

};
