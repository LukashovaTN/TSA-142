#include <iostream>
#include <ctime>
using namespace std;
/**
 * @brief оператор выбоа способа заполнения массива
 * @param RANDOM = 0 автоматическое заполнение
 * @param MANUALLY =1 ручное заполнение
 */
enum SELECT
{
    RANDOM = 0,
    MANUALLY = 1
};
/**
 * @brief считывает размер массива
 * @return размер массива в беззнаковом типе данных
 */
size_t getSize();
/**
 * @brief считывает значение типа int
 * @return считанное значение целочисленное
 */
int getNumber();
/**
 * @brief заполнение массива вручную
 * @param arr - массив
 * @param n - размер массива
 * @param min - минимальное значение диапазона значений элементов массива
 * @param max - максимальное значение диапазона значений элементов массива
 */
void fillArray(int* arr, const int n, int const min, int const max);

/**
 * @brief проверяет диапазон
 * @param min - минимальное значение диапазона значений элементов массива
 * @param max - максимальное значение диапазона значений элементов массива
 */
void checkRange(int const min, int const max);
/**
 * @brief Выводит сумму положительных элементов, состоящих из двух знаков
 * @param arr - массив
 * @param n - размер массива
 */
int sumOfPositiveTwoDigitNumbers(int* arr, int const n);
/**
 * @brief Умножает четные положительные элементы массива на последний элемент массива 
 * @param arr - массив
 * @param n - размер массива
 */
void multiplyEvenPositiveByLastElement(int* arr, int const n);
/**
 * @brief Находит первую пару элементов с разными знаками, сумма которых меньше введённого числа x.
 * @param arr - массив
 * @param n - размер массива
 * @param x - сравниваемое число
 * @return Номер пары элементов, если их нет, то -1
 */
int findFirstOppositeSignsPairLessThan(int* arr, int const n, int const x);
/**
 * @brief заполнение массива автоматически случайнвми числами в заданном диапазоне
 * @param arr - массив
 * @param n - размер массива
 * @param min - минимальное значение диапазона значений элементов массива
 * @param max - максимальное значение диапазона значений элементов массива
 */
void fillArrayRandom(int* arr, const int n, int const min, int const max);

/**
 * @brief Выводит массив на экран
 * @param arr - массив
 * @param n - размер массива
 */
void printArray(int* arr, const int n);

/**
* @brief точка входа в программу
* @return 0 - если программма выполнена корректно, инече -1
*/
int main()
{
    cout << "Enter size of array: " << endl;
    int n = getSize();
    int* arr = new int[n];
    cout << "Enter min and max values of range: " << endl;
    int minValue = getNumber();
    int maxValue = getNumber();
    checkRange(minValue, maxValue);
    cout << "Enter your choice to fill array: " << endl
        << RANDOM << " to fill random" << endl
        << MANUALLY << " to fill manually" << endl;
    int choice = getNumber();
    switch ((enum SELECT)choice)
    {
    case 0:
        fillArrayRandom(arr, n, minValue, maxValue);
        break;
    case 1:
        fillArray(arr, n, minValue, maxValue);
        break;
    default:
        cout << "Your choise is wrong" << endl;
        return 1;
        break;
    }
    cout << "Array: " << endl;
    printArray(arr, n);
    cout << "Sum of positive elements with two digit numbers: " << endl;
    cout << sumOfPositiveTwoDigitNumbers(arr, n) << endl;
    cout << "Enter a number: ";
    int x = getNumber();
    cout << "The number of the first pair of adjacent elements with different signs, the sum of which is less than the specified number: " << endl;
    cout << findFirstOppositeSignsPairLessThan(arr, n, x) << endl;
    cout << "All even positive elements are multiplied by the last number: " << endl;
    multiplyEvenPositiveByLastElement(arr, n);
    printArray(arr, n);
    delete[] arr;
    return 0;
}

size_t getSize()
{
    size_t n;
    if (!(cin >> n))
    {
        cout << "error" << endl;
        abort();
    }
    return n;
}

void fillArray(int* arr, const int n, int const min, int const max)
{
    for (size_t i = 0; i < n; i++)
    {
        cout << "Enter " << i << " element of array: ";
        arr[i] = getNumber();
        if (arr[i] > max || arr[i] < min)
        {
            cout << "Wrong value entered" << endl;
            abort();
        }

    }
}

int getNumber()
{
    int number;
    cin >> number;
    if (cin.fail())
    {
        cout << "Incorrect input";
        abort();
    }
    return number;
}

void checkRange(int const min, int const max)
{
    if (min >= max)
    {
        cout << "Wrong range entered" << endl;
        abort();
    }
}

void fillArrayRandom(int* arr, const int n, int const min, int const max)
{
    srand(time(0));
    for (size_t i = 0; i < n; i++)
    {
        arr[i] = rand() % (max - min) + min;
    }
}

void printArray(int* arr, const int n)
{
    for (size_t i = 0; i < n; i++)
    {
        cout << "arr[" << i << "]=" << arr[i] << endl;
    }
}

int sumOfPositiveTwoDigitNumbers(int* arr, int const n)
{
    int sum = 0;
    for (size_t i = 0; i < n; ++i)
    {
        if (arr[i] >= 10 && arr[i] <= 99)
        {
            sum += arr[i];
        }
    }
    return sum;
}

void multiplyEvenPositiveByLastElement(int* arr, int const n)
{
    int lastElement = arr[n - 1];
    for (size_t i = 0; i < n; ++i)
    {
        if (arr[i] > 0 && arr[i] % 2 == 0)
        {
            arr[i] *= lastElement;
        }
    }
}

int findFirstOppositeSignsPairLessThan(int* arr, int const n, int const x)
{
    for (size_t i = 0; i < n - 1; ++i)
    {
        if ((arr[i] > 0 && arr[i + 1] < 0) || (arr[i] < 0 && arr[i + 1] > 0))
        {
            if (arr[i] + arr[i + 1] < x)
            {
                return i;
            }
        }
    }
    return -1;
}