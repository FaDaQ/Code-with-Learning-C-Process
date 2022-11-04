#include <iostream>
#include <vector>
#include "myFunc.h"
#include "Friction.h"

using namespace std;
using namespace myDoodles;
using namespace friction;


int main()
{
    system("chcp 1251"); system("cls");

    vector <Friction> frictVec;

    for (int i = 0; i < 5; i++) {
        frictVec.push_back(Friction(randint(10, 20), randint(10, 23)));
    }
    printFrictionsVector(frictVec);

    return 0;
}