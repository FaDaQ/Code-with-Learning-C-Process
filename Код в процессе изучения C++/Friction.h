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
	}

	void print() {
		int N = numerLen >= denumerLen ? numerLen - (denumerLen - 1) : denumerLen - (numerLen - 1);
		numerLen >= denumerLen
			? cout << multStr(" ", numerLen - N) << numer << "\n" + multStr("--", numerLen) << endl << multStr(" ", numerLen - N) << denumer
			: cout << multStr(" ", numerLen - N) << numer << "\n" + multStr("--", denumerLen) << endl << multStr(" ", numerLen - N)<<  denumer;
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
};

