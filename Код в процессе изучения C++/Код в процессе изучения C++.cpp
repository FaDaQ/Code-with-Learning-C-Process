#include <iostream>
#include <vector>
#include "myFunc.h"
#include "Friction.h"

using namespace std;
using namespace myDoodles;

void printFrictionsVector(vector <Friction> frictionVec) {
    for (Friction i : frictionVec)
        i.getDivStrip().length() >= 8 ? cout << i.getSpaces() << i.getNumerator() << "\t\t" : cout << i.getSpaces() << i.getNumerator() << "\t";
    cout << endl;

    for (Friction i : frictionVec)
        cout << i.getDivStrip() << "\t";
    cout << endl;

    for (Friction i : frictionVec)
        i.getDivStrip().length() >= 8 ? cout << i.getSpaces() << i.getDenumrator() << "\t\t" : cout << i.getSpaces() << i.getDenumrator() << "\t";
}

int main()
{
    system("chcp 1251"); system("cls");

    
    vector <Friction> frictionVec;
    
    double input1;
    double input2;
    int count;

    cout << "Сколько дробей вы хотите ввести: ";
    cin >> count;

    for (int i = 1; i <= count; i++) {
        cout << i << "-я дробь > Введите числитель: ";
        cin >> input1;
        cout << i << "-я дробь > Введите знаменатель: ";
        cin >> input2;
        frictionVec.push_back(Friction(input1, input2));
        input1 = 0; input2 = 0;
        cout << endl;
    }
    

    printFrictionsVector(frictionVec);

    return 0;
}