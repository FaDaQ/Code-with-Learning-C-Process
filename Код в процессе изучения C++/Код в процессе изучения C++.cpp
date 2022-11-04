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

    for (int i = 0; i < 10; i++) {
        frictVec.push_back(Friction(randint(10, 20), randint(12, 20)));
    }
    

    printFrictionsVector(frictVec);

    return 0;
}