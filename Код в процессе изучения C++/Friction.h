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

		spaceCount = numerLen >= denumerLen ? numerLen - (denumerLen - 1) : denumerLen - (numerLen - 1);
		dividerStrip = numerLen >= denumerLen ? multStr("--", numerLen) : multStr("--", denumerLen);
	}

	void print() {
		cout << multStr(" ", spaceCount) << numer << "\n" + dividerStrip + "\n" << multStr(" ", spaceCount) << denumer;
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
};

