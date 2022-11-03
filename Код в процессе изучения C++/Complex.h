#pragma once
#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>
#include <format>
#include "myFunc.h"

using namespace std;
using myDoodles::sqr; using myDoodles::mround;

//������������ ��� ��� ������ � ������������ �������
namespace complex {
    //����� ��� ������ � ������������ �������
    class Complex {
    public:
        //����� ��������� �������� � ������ �����
        Complex(double numReal, double numImaginary) {
            real = numReal;
            imaginary = numImaginary;
            setValuesForTrigonometric();
        }
        //����� ��������� �������� � ������ �����, � ��� �� ���
        Complex(double numReal, double numImaginary, string Name) {
            real = numReal;
            imaginary = numImaginary;
            name = Name;
            setValuesForTrigonometric();
        }
        //����� ��������� ������ ���
        Complex(string Name) {
            real = 0;
            imaginary = 0;
            name = Name;
            setValuesForTrigonometric();
        }
        Complex() {
#ifdef DEBUG
            cout << "����������� ����� ���� ������� ��� ��������!" << endl;
#endif
            real = 0;
            imaginary = 0;
            name = "NA";
            setValuesForTrigonometric();
        }

        double getReal() {
            return real;
        }
        double getImaginary() {
            return imaginary;
        }

        void print() {
            if (imaginary >= 0) {
                cout << format("{0}+{1}i", real, imaginary);
            }
            else {
                cout << format("{0}{1}i", real, imaginary);

            }
        }

        string strForm() {
            if (imaginary >= 0) {
                return format("{0}+{1}i", real, imaginary);
            }
            else {
                return format("{0}{1}i", real, imaginary);
            }
        }

        //����� ��� ��������� �������� ������������ ����� �������
        void set() {
            cout << format("������� �������� ����� {0}: ", name);
            cin >> real;
            cout << format("������� ������ ����� {0}: ", name);
            cin >> imaginary;
            setValuesForTrigonometric();
        }
        //����� ��� ��������� �������� ������������ ����� � ��������� ����������
        void set(double real, double img) {
            this->real = real;
            this->imaginary = img;
        }

        void setRound(int N) {
            rounder = N;
            setValuesForTrigonometric();
        }

        //������� ������������������ ����� ������������ �����
        void printTrigonometric() {
            cout << "����������� ���:\t " << format("{0} * cos({1}) + i * sin({2})", rStr, phiStr, phiStr) << endl
                << "��� � ����������� �:\t " << format("{0} * cos({1}) + i * sin({2})", rStr, phi, phi) << endl
                << "��� � ����������� r:\t " << format("{0} * cos({1}) + i * sin({2})", r, phi, phi) << endl
                << "��� � � � ���� ����:\t " << format("{0} * cos({1}) + i * sin({2})", r, phi2, phi2);
        }

        //�������� ������������ ����� � ���������� ������
        Complex sum(Complex num) {
            double real = this->real + num.getReal();
            double imaginary = this->imaginary + num.getImaginary();
            Complex result(real, imaginary);
            return result;
        }

        //��������� ����������� ������������ ����� �� ��������
        Complex sub(Complex num) {
            double real = this->real - num.getReal();
            double imaginary = this->imaginary - num.getImaginary();
            Complex result(real, imaginary);
            return result;
        }

        //��������� ������������ ����� �� ����������� ����������� �����
        Complex mult(Complex num) {
            double real = (this->real * num.getReal()) - (this->imaginary * num.getImaginary());
            double imaginary = (this->imaginary * num.getReal()) + (this->real * num.getImaginary());
            Complex result(real, imaginary);
            return result;
        }

        //������� ������������ ����� �� ���������� ����������� �����
        Complex div(Complex num1, Complex num) {
            double real = ((num1.getReal() * num.getReal()) + (num1.getImaginary() * num.getImaginary())) /
                (sqr(num.getReal()) + sqr(num.getImaginary()));
            double imaginary = (num1.getImaginary() * num.getReal() - num1.getReal() * num.getImaginary()) /
                (sqr(num.getReal()) + sqr(num.getImaginary()));

            Complex result(real, imaginary);
            return result;
        }

    private:
        double real;
        double imaginary;
        int rounder = 3;
        string name = "";

        double r;
        string rStr;

        double phi;
        string phiStr;

        double phi2;

        double sinPhi;
        string sinPhiStr;

        double cosPhi;
        string cosPhiStr;

        void setValuesForTrigonometric() {
            setr();
            setSinPhi();
            setCosPhi();
            setPhi();
            phi2 = mround(asin(sinPhi), rounder);
#ifdef DEBUG_TRIGONOMETRIC
            cout << "\n\n" << real / imaginary << " - ��������� ������� �������� ����� �� ������" << endl;
            cout << "� = " << phi << endl;
            cout << "r = " << r << endl;
            cout << "rStr = " << rStr << endl;
            cout << "sin(�) = " << sinPhi << endl;
            cout << "cos(�) = " << cosPhi << endl;
            cout << "sin(�)str = " << sinPhiStr << endl;
            cout << "cos(�)str = " << cosPhiStr << endl;
#endif
        }

        void setPhi()
        {
            phi = mround(asin(sinPhi) * 180 / M_PI, rounder);
            phiStr = format("arctg({0}/{1})", imaginary, real);
        }

        void setCosPhi()
        {
            cosPhi = mround(real / r, rounder);
            cosPhiStr = format("{0} / {1}", real, r);
        }

        void setSinPhi()
        {
            sinPhi = mround(imaginary / r, rounder);
            sinPhiStr = format("{0} / {1}", imaginary, r);
        }

        void setr()
        {
            r = mround(sqrt(sqr(real) + sqr(imaginary)), rounder);
            rStr = format("sqrt({0})", sqr(real) + sqr(imaginary));
        }

    };
}