#pragma once
#include <iostream>
#define BOOST
#include "myFunc.h"
#define BOOST

using namespace std;
using namespace myDoodles;

class Friction
{
public:
	Friction(double numerator, double denumerator) {
		numer = numerator;
		denumer = denumerator;
		result = numer / denumer;
		numerLen = countNumsInNum(numer);
		denumerLen = countNumsInNum(denumer);
		
		setSpaces();
		setDeviderStrip();
	}

	void print() {
		cout << spaces << numer << "\n" + dividerStrip + "\n" << spaces << denumer;
	}

	string getDivStrip() {
		return dividerStrip;
	}
	string getSpaces() {
		return spaces;
	}
	int getSpaceCount() {
		return spaceCount;
	}
	double getNumerator() {
		return numer;
	}
	double getDenumrator() {
		return denumer;
	}
	double getResult() {
		return result;
	}

private:
	double numer;
	double denumer;
	double result;
	int numerLen;
	int denumerLen;
	string dividerStrip;
	int spaceCount;
	//��� �������, ������� ����� ��� �������� �� ����� ������ ����� �� �����
	string spaces;

	void setSpaces() {
		spaceCount = numerLen >= denumerLen ? numerLen - (denumerLen - 1) : denumerLen - (numerLen - 1);
		spaces = multStr(" ", spaceCount);
	}
	void setDeviderStrip() {
		dividerStrip = numerLen >= denumerLen ? multStr("--", numerLen) : multStr("--", denumerLen);
	}
};

