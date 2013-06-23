/* 
 * File:   monstr.h
 * Author: konstantin
 *
 * Created on 25 Сентябрь 2012 г., 16:03
 */

#ifndef _MONSTR_H
#define	_MONSTR_H

#ifdef	__cplusplus
extern "C" {
#endif

#include <string>

class monstr{
    int health;
    std::string name;
public:
    monstr(int he = 100, std::string na = "noname")
    {
        health = he;
        name = na;
    }
    int get_health() const {return health;}
    void change_health(int he){health = he;}
    std::string get_name() const {return name;}
};


#ifdef	__cplusplus
}
#endif

#endif	/* _MONSTR_H */

