#pragma once
#include <iostream>

using std::cout; using std::string;

namespace weapons {
    class Weapon {
    public:
        Weapon(string Name, double Damage) {
            name = Name;
            damage = Damage;
            setType("Weapon");
        }

        virtual void atack() = 0;

        void printSpec() {
            cout << "����������� ������:\n" << "��� " << type << "\n�������� - " << name << "\n����� ���� - " << damage << "\n\n";
        }

    private:
        double damage;
        string name;
        string type;

    protected:
        void setType(string type) {
            this->type = type;
        }
        string getType() {
            return type;
        }
        string getName() {
            return name;
        }
        int getDamage() {
            return damage;
        }
    };

    class Pistol : public Weapon {
    public:
        Pistol(string name, int damage) : Weapon(name, damage) {
            setType("Pistol");
        }

        void atack() override {
            cout << "��������� ������� �� " << getName() << "!(" << getType() << ")\n�������� �����: " << getDamage();
        }
    };
}