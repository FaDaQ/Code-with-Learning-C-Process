#include <iostream>
#include <vector>
#include "myFunc.h"
#include "Friction.h"

using namespace std;
using namespace myDoodles;

int main()
{
    system("chcp 1251"); system("cls");

    
    Friction test(21, 711);
    test.print();


    return 0;
}