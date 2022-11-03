#pragma once
#include <iostream>
#include <vector>
#define _USE_MATH_DEFINES
#include <math.h>
#include "myFunc.h"

using namespace std;
using myDoodles::Range; using myDoodles::randint;
using myDoodles::multStr;


//Пространство имён для работы с матрицами
namespace matrix {
    class Matrix {
    public:
        //Перегрузка метода для введения данных в матрицу вручную
        void setMatrix() {
            cout << "Введите количество строчек массива: ";
            cin >> this->row;

            cout << "Введите количество столбцов массива: ";
            cin >> this->column;

            for (int i = 0; i < row; i++) {
                arr.push_back(vector <double> {});
            }

            for (int i = 0; i < row; i++) {
                for (int j = 0; j < column; j++) {
                    cout << "Строка " << i << ", столбец " << j << ": ";
                    int inputNum; cin >> inputNum;
                    arr.at(i).push_back(inputNum);
                }
                cout << endl;
            }
        }
        //Перегрузка метода для того, чтобы задать уже готовую матрицу-объект класса vector с элементами double
        void setMatrix(vector <vector <double>> matrix) {
            row = matrix.size();
            column = matrix.at(0).size();
            arr = matrix;
        }

        //Генерирует матрицу по заданным параметрам
        void generate(int min, int max, int columns, int rows) {
            this->column = columns;
            this->row = rows;
            if (arr.size() != 0) {
                arr.clear();
            }
            for (int i = 0; i < rows; i++) {
                arr.push_back(vector <double> {});
            }

            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < columns; j++) {
                    arr.at(i).push_back(randint(min, max));
                }
            }
        }

        //Генерирует матрицу с рандомным количеством строк и столбцов(до 50) с заданными параметрами диапазона чисел
        void generate(int min, int max) {
            int columns = randint(1, 50);
            int rows = randint(1, 50);

            this->column = columns;
            this->row = rows;

            if (arr.size() != 0) {
                arr.clear();
            }
            for (int i = 0; i < rows; i++) {
                arr.push_back(vector <double> {});
            }

            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < columns; j++) {
                    arr.at(i).push_back(randint(min, max));
                }
            }
        }

        void printMatrix(int spaceCount = 2) {
            for (int i = 0; i < arr.size(); i++) {
                for (int j = 0; j < arr.at(i).size(); j++) {
                    cout << arr.at(i).at(j) << multStr(" ", spaceCount);
                }
                cout << endl;
            }
        }

        //Метод превращает столбцы матрицы в строки
        void reverseRowsToColumns() {
            swap(this->row, this->column);
            vector <vector <double>> temp;

            for (int i = 0; i < row; i++) {
                temp.push_back(vector <double> {});
            }
            for (int i = 0; i < row; i++) {
                for (int j = 0; j < column; j++) {
                    temp.at(i).push_back(arr.at(j).at(i));
                }

            }
            this->arr = temp;
        }

        //Метод возвращает количество строк при параметре true(по умолчанию), при параметре 0 - возвращает количество столбцов
        int getSize(bool strsOrColmn = true) {
            if (strsOrColmn) {
                return row;
            }
            else {
                return column;
            }

        }

        vector <vector <double>> getMatrix() {
            return arr;
        }

    private:
        int row; int column;
        vector <vector <double>> arr;
    };


    //Вспомогательная функция для actionWithMatrix(), чтобы не пришлось повторять один и тот же код по несколкьо раз
    /*Получает на вход предполагаемую матрицу-результат какого-либо действия, матрицу с которой будет производится действие и знак
      самого действия*/
    void calculateMatrix(vector <vector<double>>& result, Matrix matrix, char act) {
        switch (act)
        {
        case '+':
            for (int i : Range(0, matrix.getMatrix().size() - 1).range) {
                for (int j : Range(0, matrix.getSize(0) - 1).range) {
                    result.at(i).at(j) += matrix.getMatrix().at(i).at(j);
                }
            }
            break;
        case '-':
            for (int i : Range(0, matrix.getMatrix().size() - 1).range) {
                for (int j : Range(0, matrix.getSize(0) - 1).range) {
                    result.at(i).at(j) -= matrix.getMatrix().at(i).at(j);
                }
            }
            break;
        case '*':
            for (int i : Range(0, matrix.getMatrix().size() - 1).range) {
                for (int j : Range(0, matrix.getSize(0) - 1).range) {
                    result.at(i).at(j) *= matrix.getMatrix().at(i).at(j);
                }
            }
            break;
        case '/':
            for (int i : Range(0, matrix.getMatrix().size() - 1).range) {
                for (int j : Range(0, matrix.getSize(0) - 1).range) {
                    result.at(i).at(j) /= matrix.getMatrix().at(i).at(j);
                }
            }
            break;
        }

    }
    //Функция для сложения матриц. Принимает на вход 2 матрицы, которые нужно сложить.
    Matrix actionWithMatrix(Matrix matrix1, Matrix matrix2, char act) {
        vector <vector<double>> result;
        int matrixMin;
        int rows1 = matrix1.getSize(); int column1 = matrix1.getSize(0);
        int rows2 = matrix2.getSize(); int column2 = matrix2.getSize(0);
        int matrix1Size = matrix1.getSize() + matrix1.getSize(0);
        int matrix2Size = matrix2.getSize() + matrix2.getSize(0);

        if (matrix1Size > matrix2Size) {
            result = matrix1.getMatrix();
            matrixMin = 2;
        }
        else {
            result = matrix2.getMatrix();
            matrixMin = 1;
        }

        try {
            switch (act) {
            case '+':
                matrixMin == 1 ? calculateMatrix(result, matrix1, act) : calculateMatrix(result, matrix2, act);
                break;
            case '-':
                matrixMin == 1 ? calculateMatrix(result, matrix1, act) : calculateMatrix(result, matrix2, act);
                break;
            case '*':
                matrixMin == 1 ? calculateMatrix(result, matrix1, act) : calculateMatrix(result, matrix2, act);
                break;
            case '/':
                matrixMin == 1 ? calculateMatrix(result, matrix1, act) : calculateMatrix(result, matrix2, act);
                break;
            }
        }
        catch (exception) {
            cout << "Приношу извинения! Что-то пошло не так...\n"
                << "Возможно количество столбцов обеих матриц больше, чем количество строк или количество столбцов одной из матриц больше, "
                << "чем количество строк\n";
        }

        //Старый, отнюдь не самый лучший способ реализации.(Хотя у меня все способы не лучшие, вхаха)
        //Пусть это будет примером для тех, кто не понимает того, как у одной и той же задачи могут быть разные решения
        /*for (int i : Range(0, matrixMaxSize).range) {
            for (int j : Range(0, matrixMaxSize).range) {
                try
                {
                    result.at(i).push_back(matrix1.getMatrix().at(i).at(j) + matrix2.getMatrix().at(i).at(j));
                }
                catch (const std::exception&)
                {
                    continue;
                }
            }
        }*/

        Matrix resultMatrix;
        resultMatrix.setMatrix(result);

        return resultMatrix;
    }
}