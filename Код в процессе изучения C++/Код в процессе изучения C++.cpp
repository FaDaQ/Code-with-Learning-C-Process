#include <iostream>
#include "Weapons.h"

using namespace std;
using namespace weapons;


int main()
{
    system("chcp 1251"); system("cls");

    Pistol weap("Desert Eagle", 450);
    weap.printSpec(); cout << endl;

    weap.atack(); cout << endl;

    return 0;
}
