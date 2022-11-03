#pragma once
#include "myFunc.h"
#include <iostream>
#include <format>
#include <fstream>

using std::format; using std::cout; using std::string; using std::ofstream;

using myDoodles::mround; using myDoodles::randint; using myDoodles::randchoice; using myDoodles::randreal;

namespace student {
    class Student {
    public:
        Student() {}
        Student(string name, string surname, int age, int height, double performance) {
            this->name = name;
            this->surname = surname;
            this->age = age;
            this->height = height;
            avgPerformance = performance;
        }

        string strF() {
            return format("Студент {0} {1}, {2}; Ср.Балл = {3}", name, surname, age, mround(avgPerformance, 2));;
        }

        string getStrForHTMLTable() {
            return format("<tr>\n\t<td>{0} {1}</td><td>{2}</td><td>{3}</td>\n</tr>", name, surname, age, mround(avgPerformance, 2));
        }

        void setName(string newName) {
            name = newName;
        }

    private:
        string name = "NA";
        string surname = "NA";
        int age = 0;
        int height = 0;
        double avgPerformance = 0;
    };

    void studentsDBToHTML(vector <Student> studentsDB) {
        string studentsTableList = "";
        for (auto i : studentsDB) {
            studentsTableList += i.getStrForHTMLTable() + "\n";
        }
        string base = format("<!DOCTYPE html>\n"
            "<html>\n"
            "<head>\n"
            "\t<meta charset = \windows-1251\">"
            "\n\t<meta name = \"viewport\" content = \"width=device-width, initial-scale=1\">"
            "\n\t<title>Таблица</title>"
            "</head>\n"
            "<body>\n"
            "\t<table border = \"2\" align=\"center\">"
            "\n\t\t<caption><b>Список учеников и их успеваемости</b></caption>"
            "\n\t<tr>"
            "\n\t\t<th>Имя и Фамилия учащегося</th><th>Возраст</th><th>Средний балл</th>"
            "\n\t</tr>"
            "\n\t<tr>"
            "\n\t\t{0}"
            "\n\t</tr>"
            "\n</table>"
            "\n</body>"
            "\n</html>", studentsTableList);

        ofstream htmlFile("Таблица студентов и успеваемости.html");

        htmlFile << base;
        htmlFile.close();
    }

    vector <Student> generateDB(int N) {
        vector <Student> studentsDB;
        vector <string> manNames = { "Миша", "Никита", "Данил", "Ислам", "Кирилл", "Артемий", "Алексей", "Арсений"};
        vector <string> womanNames = { "Ксюша", "Арина", "Карина", "Даша", "Юля", "Оля", "Полина" };
        vector <string> manSurnames = { "Дёмин", "Владимиров", "Филипов", "Кузьмин", "Федосеев", "Таркаев", "Имулин" };
        vector <string> womanSurnames = { "Юматова", "Алошкина", "Кузьмина", "Тамарова", "Анискина", "Владимирова", "Фалена" };

        for (int i = 1; i <= N; i++) {
            int temp = randint(1, 2);
            string name = temp % 2 == 0 ? randchoice(manNames) : randchoice(womanNames);
            string surname = temp % 2 == 0 ? randchoice(manSurnames) : randchoice(womanSurnames);
            studentsDB.push_back(Student(name, surname, randint(15, 21), randreal(150, 220), randreal(2.0, 5.0)));
        }

        return studentsDB;
    }
}