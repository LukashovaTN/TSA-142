#include <iostream>
#include <cmath> 
using namespace std;
/**
* @brief Проверяет условие
* @param a - вещественное число а
* @param b - вещественное число b
* @param c - вещественное число c
* @return Результат проверки трёх чисел
*/
void checkConditions(double& a, double& b, double& c);
/**
* @breef Считывает значение с клавиатуры с проверкой ввода
* @return Введённое значение
*/
double getValue();
/**
* @brief Проверяет число на вещественность
* @param a - проверяемое число
*/
void checkReal(const double a);
/**
* @breef - главная функция программы
* @return - возвращает 0, если функция выполнена верно, иначе 1.
*/
int main() {
    cout << "Enter a real numbers a, b, c: ";
    double a = getValue();
    checkReal(a);
    double b = getValue();
    checkReal(b);
    double c = getValue();
    checkReal(c);
    checkConditions(a, b, c);
    cout << "Result: a = " << a << ", b = " << b << ", c = " << c << endl;
    return 0;
}

void checkConditions(double& a, double& b, double& c) {
    if (a < b && b < c) {
        a *= 2;
        b *= 2;
        c *= 2;
    }
    else {
        a = abs(a);
        b = abs(b);
        c = abs(c);
    }
}

double getValue() {
    double value;
    cin >> value;
    if (cin.fail()) {
        cout << "incorrect value" << endl;
        abort();
    }
    return value;
}

void checkReal(const double a)
{
    if (a == int(a))
    {
        cout << "Wrong number!!!";
        abort();
    }
}