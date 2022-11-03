#include <iostream>
#include <vector>
#include "myFunc.h"
#include "Complex.h"

using namespace std;
using namespace myDoodles;
using namespace complex;

int main()
{
    system("chcp 1251"); system("cls");

    Complex num1(212, 342);
    num1.setRound(4);
    num1.printTrigonometric();
    cout << endl;

    double a = 56.305;
    cout << mround(a, 2);



    return 0;
}