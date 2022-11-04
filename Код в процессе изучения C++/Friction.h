#pragma once
#include <iostream>
#define BOOST
#include "myFunc.h"
#define BOOST

using namespace std;
using namespace myDoodles;

namespace friction {
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

		void print(string opt = "") {
			cout << spaces << numer;
			moveCursor(getCurPos().X - spaceCount - numerLen, getCurPos().Y + 1);
			cout << dividerStrip + opt;
			moveCursor(getCurPos().X - dividerStrip.length(), getCurPos().Y + 1);
			cout << spaces << denumer;
		}

		string getDivStrip() {
			return dividerStrip;
		}
		string getSpaces() {
			return spaces;
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
		//Это пробелы, которые нужны для отступов во время вывода дроби на экран
		string spaces;

		void setSpaces() {
			spaceCount = numerLen >= denumerLen ? numerLen - (denumerLen - 1) : denumerLen - (numerLen - 1);
			spaces = multStr(" ", spaceCount);
		}
		void setDeviderStrip() {
			dividerStrip = numerLen >= denumerLen ? multStr("--", numerLen) : multStr("--", denumerLen);
		}
	};


	void printFrictionsVector(vector <Friction> frictionVec) {
		for (Friction i : frictionVec) {
			i.print();
			moveCursor(getCurPos().X + 5, getCurPos().Y - 2);
		}
		cout << "\n\n\n";
	}
}