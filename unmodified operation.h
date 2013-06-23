/* 
 * File:   f3.h
 * Author: konstantin
 *
 * Created on 29 Сентябрь 2012 г., 18:50
 */

#ifndef _F3_H
#define	_F3_H



#endif	/* _F3_H */

#include <algorithm>
#include <queue>
#include "monstr.h"
#include <fstream>
#include <iomanip>

using namespace std;
bool over10(int& a)
{
    return a>10;
}
void plus10(int& a)
{
    a+=10;
}

void unmodified_operation()
{
    ifstream in("data.txt");
    deque<int> DQ;
    int x;
    while(in >> x, !in.eof())
    {
        DQ.push_back(x);
    }
    ifstream in1("data1.txt");
    deque<int> DQ1;
    while(in1 >> x, !in1.eof())
    {
        DQ1.push_back(x);
    }
    cout << "deque<int> DQ:   ";
    print_container(DQ.begin(), DQ.end());
    cout << "deque<int> DQ1:   ";
    print_container(DQ1.begin(), DQ1.end());
    deque<int> DQ2(DQ.begin()+2, DQ.begin()+6);
    cout << "deque<int> DQ2:   ";
    print_container(DQ2.begin(), DQ2.end());
    cout << "******************* UNMODIFIED OPERATION *******************" << endl;
   /*
    * 1. Алгоритм adjacent_find выполняет нахождение пары соседних значений
    * (также можно задать условие предикатом). Возвращает итератор на первое
    * значение или конец последовательности.
    */

    cout << "[adjacent_find, DQ]";
    cout.width(40);
    cout.setf(ios::right);
    cout << setfill('.') << "[" << adjacent_find(DQ.begin(), DQ.end())-DQ.begin() << "]" << endl;
    /*
     * 2. Алгоритм count выполняет подсчет количества вхождений значения в последовательность
     * результат имеет тип разности между двумя итераторами: difference_type
     * */
    cout << "[count, DQ, 6]";
    cout.width(47);
    cout.setf(ios::right);
    cout << count(DQ.begin(), DQ.end(), 6) << endl;
    /*
     * 3. Алгоритм count_if выполняет подсчет количества выполнений условия в
     * последовательности. Эта форма алгоритма вычисляет в последовательном
     * контейнере количество элементов, удовлетворяющих условию, заданному предикатом
     * в виде функции или функционального объекта.
     */
    cout << "[count_if, DQ, over10]";
    cout.width(39);
    cout << count_if(DQ.begin(), DQ.end(), over10) << endl;
    /*
     * 4. Алгоритм equal выполняет попарное сравнение элементов двух
     * последовательностей. Можно задать предикат, определяющий, что
     * считать равенством.
     */
    cout << "[equal, DQ, DQ1]";
    cout.width(45);
    cout << equal(DQ.begin(), DQ.end(), DQ1.begin()) << endl;
    /*
     * 5. Алгоритм find осуществляет поиск в последовательности. Возвращает итератор на самое
     * левое найденное значение в случае успешного поиска и на конец последовательности -
     * в противном случае.
     */
    cout << "[find, DQ, 87]";
    cout.width(45);
    cout << "[" << find(DQ.begin(), DQ.end(), 87)-DQ.begin() << "]" << endl;
    /*
     * 6. Алгоритм find_if выполняет поиск значения, соответствующего заданному
     * предикату. Возвращает итератор на самое левое найденное значение в случае
     * успешного поиска и на конец последовательности - в противном случае.
     */
    cout << "[find_if, DQ, over10]";
    cout.width(38);
    cout << "[" << find_if(DQ.begin(), DQ.end(), over10)-DQ.begin() << "]" << endl;
    /*
     * 7. Алгоритм find_first_of находит первое вхождение в первую последовательность элемента
     * из второй последовательности. Можно искать любой элемент или задать условие предикатом
     */
    cout << "[find_first_of, DQ, DQ1]";
    cout.width(35);
    cout << "[" << find_first_of(DQ.begin(), DQ.end(), DQ1.begin(), DQ1.end())-DQ.begin() << "]" << endl;
    /* 8. Алгоритм find_end находит первое вхождение в первую последовательность 
     * второй последовательности (с анализом предиката или без) и возвращает итератор
     * на последний совпадающий элемент. (реально возвращается почему то итератор на первый элемент)
     */
    cout << "[find_end, DQ, DQ2]";
    cout.width(40);
    cout << "[" << find_end(DQ.begin(), DQ.end(), DQ2.begin(), DQ2.end())-DQ.begin() << "]" << endl;
    /*
     * 9. Алгоритм search находит первое вхождение в первую последовательность второй
     * последовательности (с анализом предиката или без) и возвращает итератор на
     * первый совпадающий элемент.
     */
    cout << "[search, DQ, DQ2]";
    cout.width(42);
    cout << "[" << search(DQ.begin(), DQ.end(), DQ2.begin(), DQ2.end())-DQ.begin() << "]" << endl;
    /*
     * 10. Алгоритм search_n находит в последовательности подпоследовательность,
     * состояющую из по крайней мере n значений value (с анализом предиката или без)
     * и возвращает итератор на первый совпадающий элемент
     */
    cout << "[search_n, 2, 4]";
    cout.width(43);
    cout << "[" << search_n(DQ.begin(), DQ.end(), 2, 4)-DQ.begin() << "]" << endl;
     /*
    Алгоритм mismatch ищет первую пару несовпадающих элементов двух
    последовательностей и возвращает итераторы не эту пару.
    Длина второй последовательности считается большей или равное длине первой.
    Можно задать предикат, определяющий, что считать несовпадением.
     */
    typedef deque<int>::iterator pv;
    typedef deque <int>::iterator pl;
    pair<pv, pl> p1 = mismatch(DQ.begin(), DQ.end(), DQ1.begin(), greater_equal<int>());
    cout << "[mismatch, greater_equal, DQ, DQ1]";
    cout.width(18);
    cout << "(" << *(p1.first) << ", " << *(p1.second) << ")[" << p1.first-DQ.begin() << "]" << endl;
    /* Алгоритм for_each вызывает для каждого элемента последовательности заданную 
     * функцию
     */
    for_each(DQ2.begin(), DQ2.end(), plus10);
    cout << "[for_each, DQ2, plus10]";
    cout.width(17);
    print_container(DQ2.begin(), DQ2.end());
}