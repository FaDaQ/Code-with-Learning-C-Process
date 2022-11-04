#pragma once
#define BOOST
//#define DEBUG
#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <format>
#include <iterator>
#include <Windows.h>
#define _USE_MATH_DEFINES
#include <math.h>

//Требует установки библиотеки boost
#ifdef BOOST
#include <boost/lexical_cast.hpp>
#endif



using namespace std;

namespace myDoodles {
    //отразить строку
    string reverseStr(string str) {
        string reverseStr = "";
        for (int i = str.length(); i >= 0; i--) {
            reverseStr += str[i];
        }

        return reverseStr;
    }

    //перевод числа в BIN(2-чную) систему
    string bin(int num) {
        string binNum = "";
        int remain = num;

        while (remain > 0) {
            binNum += to_string(remain % 2);
            remain /= 2;
        }

        return reverseStr(binNum);
    }

    //перевод числа в OCT(8-ричную) систему
    string oct(int num) {
        string octNum = "";
        int remain = num;

        while (remain > 0) {
            octNum += to_string(remain % 8);
            remain /= 8;
        }

        return reverseStr(octNum);
    }

    //перевод числа в HEX(16-ричную) систему
    string hex(int num) {
        string hexNum = "";
        int remain = num;
        int temp;


        char hexNumArr[6] = { 'A', 'B', 'C', 'D', 'E', 'F' };

        while (remain > 0) {
            temp = remain % 16;
            if (temp > 9) {
                hexNum += hexNumArr[temp - 10];
                remain /= 16;
            }
            else {
                hexNum += to_string(remain % 16);
                remain /= 16;
            }

        }

        return reverseStr(hexNum);
    }

    //Функция для ввода числа. Нужна просто для удобства при тестировании ввода пользователя в консоли, 
    //чтобы не писать дополнительные 2 строчки кода, а обойтись вызовом функции в аргументе другой функции
    //Тип дабл выбран по причине того, что int - может помешать вводу числа в функцию, где вычисляется
    //значение с плавающей точкой, а double - неявно способен преобразоваться в int
    double inputNum() {
        double a;
        cin >> a;
        return a;
    }
    string inputStr() {
        string a;
        cin >> a;
        return a;
    }


    //перевод числа в любую систему счисления
    string ons(int num, int base) {
        string outputNum = "";
        int remain = num;
        int temp;


        char lettNumArr[26] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G',
                                'H', 'I', 'J', 'K', 'L', 'M', 'N',
                                'O', 'P', 'Q', 'R', 'S', 'T', 'U',
                                'V', 'W', 'X', 'Y', 'Z' };

        if (base > 36) {
#ifdef DEBUG
            cout << "Система счисления не может быть более, чем 36-ричной!" << endl;
#endif
            return NULL;
        }
        else {
            while (remain > 0) {
                temp = remain % base;
                if (temp > 9) {
                    outputNum += lettNumArr[temp - 10];
                    remain /= base;
                }
                else {
                    outputNum += to_string(remain % base);
                    remain /= base;
                }
            }
            return reverseStr(outputNum);
        }
    }

    //Вывести на экран одномерный массив
    void printArray(double arr[], int N) {
        for (int i = 0; i < N; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    //Функция для умножения строки
    string multStr(string str, int N) {
        string a = str;
        for (int i = 1; i < N; i++)
            a += str;

        return a;
    }

#ifdef BOOST
    //Функция для поиска КОЛИЧЕСТВА цифр в числе(требуется библиотека boost)
    int countNumsInNum(double num) {
        std::string strNum = boost::lexical_cast<string>(num);
        return strNum.length();
    }
#endif

    //Возвращает случайное число int
    int randint() {
        random_device rd;
        mt19937 gen(rd());
        int randNum = gen();

        return randNum;
    }
    //(Перегрузка) Возвращает случайное число int с заданными диапазоном
    int randint(int min, int max) {
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> dist(min, max);
        int randNum = dist(gen);

        return randNum;
    }

    //Возвращает рандомное дробное число
    double randreal() {
        random_device rd;
        mt19937 gen(rd());
        double randNum = gen();

        return randNum;
    }
    //(Перегрузка) Возвращает дробное радномное число с заданными параметрами
    double randreal(double min, double max) {
        random_device rd;
        mt19937 gen(rd());
        uniform_real_distribution dist(min, max);
        double randNum = dist(gen);

        return randNum;
    }

    //функция для возведения в любую степень
    double degr(double num, double N) {
        double degrNum = num;
        for (int i = 1; i < N; i++) {
            degrNum *= num;
        }
        return degrNum;
    }

    //Функция для возведения в квадрат
    double sqr(double num) {
        return num * num;
    }

    //Класс Range - подобие range в Python. Удобно использовать для циклов. Может пригодиться для реализации некоторых других функций.
    class Range {
    public:
        Range(int min, int max) {
            for (int i = min; i <= max; i++) {
                range.push_back(i);
            }
        }
        vector <int> range;
    };

    //Функция для поиска одного элемента внутри контейнера любого типа
    template<typename type, typename type2>
    bool findIn(const type& container, type2 searcheable)
    {
        for (auto i : container) {
            if (i == searcheable) {
                return true;
            }
        }
        return false;
    }

    //Функция для возврата рандомного элемента в переданном векторе
    template<typename T>
    auto randchoice(vector <T> vec) -> T {
        int randNum = randint(0, vec.size() - 1);
        return vec.at(randNum);
    }
    //(Перегрузка) Функция для возврата рандомного элемента переданной строки
    char randchoice(string str) {
        int randNum = randint(0, str.length() - 1);
        return str[randNum];
    }

    //Округление числа до N знаков после запятой
    double mround(double num, int N) {
        int temp = degr(10, N);
        return round(num * temp) / temp;
    }

    COORD getCurPos() // получение текущей позиции курсора
    {
        CONSOLE_SCREEN_BUFFER_INFO buf; // объявляем переменную, которая содержит информацию об экранном буфере консоли
        COORD coord_new = { 0,0 }; // объявляем структуру, которая будет хранить текущие координаты консоли
        // по умолчанию выставим нули(в случае неудачи вернем сразу же)

        // вызываем функцию, которая извлекает информацию о  текущем экранном буфере консоли
        // если успех - возвращает текущий буфер
        // неудача - вернет 0
        if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &buf))
            // аргументы: дескриптор экранного буфера, и переменная, которая содержит информацию об экранном буфере консоли
        {
            coord_new.X = buf.dwCursorPosition.X; // получаем координату x из буфера
            coord_new.Y = buf.dwCursorPosition.Y; // получаем координату y из буфера
            return coord_new; // и возвращаем полученные координаты
        }
        // если неудача, то вернем наши нули
        return coord_new;
    }

    void moveCursor(int X, int Y) // изменение текущей позиции курсора
    {
        COORD coord = { X, Y };
        COORD new_pos; // структура позиции, будет хранить новую позицию
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);  // Получение дескриптора устройства стандартного вывода
        new_pos.X = coord.X;    // Установка координаты X
        new_pos.Y = coord.Y;    // Установка координаты Y
        SetConsoleCursorPosition(hConsole, coord);      // Перемещение каретки по заданным координатам
    }
}