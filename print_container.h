/* 
 * File:   print_container.h
 * Author: konstantin
 *
 * Created on 30 Сентябрь 2012 г., 1:03
 */

#ifndef _PRINT_CONTAINER_H
#define	_PRINT_CONTAINER_H



#endif	/* _PRINT_CONTAINER_H */
#include <iostream>
template <class In> void print_container(In first, In last)
{
    In temp = first;
    while(first!=last)
    {
        std::cout << *first << "[" << first-temp << "] ";
        first++;
    }
    std::cout << std::endl <<  std::endl;
}

