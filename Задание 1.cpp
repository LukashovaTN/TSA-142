#include <iostream>
#include <cmath>
using namespace std;
/**
* @breef - функция, производящая вычисление результата
* param x - число х
* param y - число y
* param z - число z
* @return результат работы функции
*/
double getResultA(const double x, const double y, const double z);
/**
* @breef - функция, производящая вычисление результата
* param x - число х
* param y - число y
* param z - число z
* @return результат работы функции
*/
double getResultB(const double x, const double y, const double z);
/**
* @breef - главная функция программы
* @return - возвращает 0, если функция выполнена верно, иначе 1.
*/
int main()
{
    const double x = 1.7;
    cout << "x = " << x << endl;
    const double y = 1.08;
    cout << "y = " << y << endl;
    const double z = 0.5;
    cout << "z = " << z << endl;
    cout << "A = " << getResultA(x, y, z) << endl;
    cout << "B = " << getResultB(x, y, z) << endl;
    return 0;
}

double getResultA(double x, double y, double z)
{
    return (sin(x) / sqrt(y * y + pow(sin(x), 2))) - (x * x * y * z);
}
double getResultB(double x, double y, double z)
{
    return exp(-z * x) * sqrt(x + 1) + exp(-y * x);
}