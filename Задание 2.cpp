#include <iostream>
#include <stdlib.h>
using namespace std;
/**
* @breef Считывает значение с клавиатуры с проверкой ввода
* @return Введённое значение
*/
double getValue();
/**
* @breef Проверяет число на то, чтобы оно не было равно нулю или меньше нуля
* @return Введённое значение
*/
void checkValue(const double value);
/**
* @breef Считает площадь треугольника
* @param a - первый катет треугольника
* @param b - второй катет треугольника
* @return Площадь треугольника
*/
double triangleSurface(const double a, const double b);
/**
* @breef - главная функция программы
* @return - возвращает 0, если функция выполнена верно, иначе 1
*/
int main()
{
    cout << "Enter the first catheter = " << endl;
    double a = getValue();
    checkValue(a);
    cout << "Enter the second catheter = " << endl;
    double b = getValue();
    checkValue(b);
    double c = sqrt(pow(a, 2) + pow(b, 2));
    cout << "Area of a triangle = " << a + b + c << endl;
    cout << "Surface area of a triangle = " << triangleSurface(a,b) << endl;
    return 0;
}
double getValue()
{
    double value;
    cin >> value;
    if (cin.fail())
    {
        cout << "incorrect value" << endl;
        abort();
    }
    return value;
}
void checkValue(const double value)
{
    if (value <= 0)
    {
        abort();
    }
}
double triangleSurface(const double a, const double b)
{
    return 0.5 * a * b;
}