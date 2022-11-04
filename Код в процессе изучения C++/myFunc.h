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

//������� ��������� ���������� boost
#ifdef BOOST
#include <boost/lexical_cast.hpp>
#endif



using namespace std;

namespace myDoodles {
    //�������� ������
    string reverseStr(string str) {
        string reverseStr = "";
        for (int i = str.length(); i >= 0; i--) {
            reverseStr += str[i];
        }

        return reverseStr;
    }

    //������� ����� � BIN(2-����) �������
    string bin(int num) {
        string binNum = "";
        int remain = num;

        while (remain > 0) {
            binNum += to_string(remain % 2);
            remain /= 2;
        }

        return reverseStr(binNum);
    }

    //������� ����� � OCT(8-������) �������
    string oct(int num) {
        string octNum = "";
        int remain = num;

        while (remain > 0) {
            octNum += to_string(remain % 8);
            remain /= 8;
        }

        return reverseStr(octNum);
    }

    //������� ����� � HEX(16-������) �������
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

    //������� ��� ����� �����. ����� ������ ��� �������� ��� ������������ ����� ������������ � �������, 
    //����� �� ������ �������������� 2 ������� ����, � �������� ������� ������� � ��������� ������ �������
    //��� ���� ������ �� ������� ����, ��� int - ����� �������� ����� ����� � �������, ��� �����������
    //�������� � ��������� ������, � double - ������ �������� ��������������� � int
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


    //������� ����� � ����� ������� ���������
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
            cout << "������� ��������� �� ����� ���� �����, ��� 36-������!" << endl;
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

    //������� �� ����� ���������� ������
    void printArray(double arr[], int N) {
        for (int i = 0; i < N; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    //������� ��� ��������� ������
    string multStr(string str, int N) {
        string a = str;
        for (int i = 1; i < N; i++)
            a += str;

        return a;
    }

#ifdef BOOST
    //������� ��� ������ ���������� ���� � �����(��������� ���������� boost)
    int countNumsInNum(double num) {
        std::string strNum = boost::lexical_cast<string>(num);
        return strNum.length();
    }
#endif

    //���������� ��������� ����� int
    int randint() {
        random_device rd;
        mt19937 gen(rd());
        int randNum = gen();

        return randNum;
    }
    //(����������) ���������� ��������� ����� int � ��������� ����������
    int randint(int min, int max) {
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> dist(min, max);
        int randNum = dist(gen);

        return randNum;
    }

    //���������� ��������� ������� �����
    double randreal() {
        random_device rd;
        mt19937 gen(rd());
        double randNum = gen();

        return randNum;
    }
    //(����������) ���������� ������� ��������� ����� � ��������� �����������
    double randreal(double min, double max) {
        random_device rd;
        mt19937 gen(rd());
        uniform_real_distribution dist(min, max);
        double randNum = dist(gen);

        return randNum;
    }

    //������� ��� ���������� � ����� �������
    double degr(double num, double N) {
        double degrNum = num;
        for (int i = 1; i < N; i++) {
            degrNum *= num;
        }
        return degrNum;
    }

    //������� ��� ���������� � �������
    double sqr(double num) {
        return num * num;
    }

    //����� Range - ������� range � Python. ������ ������������ ��� ������. ����� ����������� ��� ���������� ��������� ������ �������.
    class Range {
    public:
        Range(int min, int max) {
            for (int i = min; i <= max; i++) {
                range.push_back(i);
            }
        }
        vector <int> range;
    };

    //������� ��� ������ ������ �������� ������ ���������� ������ ����
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

    //������� ��� �������� ���������� �������� � ���������� �������
    template<typename T>
    auto randchoice(vector <T> vec) -> T {
        int randNum = randint(0, vec.size() - 1);
        return vec.at(randNum);
    }
    //(����������) ������� ��� �������� ���������� �������� ���������� ������
    char randchoice(string str) {
        int randNum = randint(0, str.length() - 1);
        return str[randNum];
    }

    //���������� ����� �� N ������ ����� �������
    double mround(double num, int N) {
        int temp = degr(10, N);
        return round(num * temp) / temp;
    }

    COORD getCurPos() // ��������� ������� ������� �������
    {
        CONSOLE_SCREEN_BUFFER_INFO buf; // ��������� ����������, ������� �������� ���������� �� �������� ������ �������
        COORD coord_new = { 0,0 }; // ��������� ���������, ������� ����� ������� ������� ���������� �������
        // �� ��������� �������� ����(� ������ ������� ������ ����� ��)

        // �������� �������, ������� ��������� ���������� �  ������� �������� ������ �������
        // ���� ����� - ���������� ������� �����
        // ������� - ������ 0
        if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &buf))
            // ���������: ���������� ��������� ������, � ����������, ������� �������� ���������� �� �������� ������ �������
        {
            coord_new.X = buf.dwCursorPosition.X; // �������� ���������� x �� ������
            coord_new.Y = buf.dwCursorPosition.Y; // �������� ���������� y �� ������
            return coord_new; // � ���������� ���������� ����������
        }
        // ���� �������, �� ������ ���� ����
        return coord_new;
    }

    void moveCursor(int X, int Y) // ��������� ������� ������� �������
    {
        COORD coord = { X, Y };
        COORD new_pos; // ��������� �������, ����� ������� ����� �������
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);  // ��������� ����������� ���������� ������������ ������
        new_pos.X = coord.X;    // ��������� ���������� X
        new_pos.Y = coord.Y;    // ��������� ���������� Y
        SetConsoleCursorPosition(hConsole, coord);      // ����������� ������� �� �������� �����������
    }
}