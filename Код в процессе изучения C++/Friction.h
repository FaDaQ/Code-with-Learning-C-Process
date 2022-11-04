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

		void print() {
			cout << spaces << numer << "\n" + dividerStrip + "\n" << spaces << denumer;
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
		double getDenumerator() {
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
			cout << i.getSpaces() << i.getNumerator() << i.getSpaces();
			moveCursor(getCursorPos().X + 4, getCursorPos().Y);
		}
		cout << endl;

		for (Friction i : frictionVec) {
			cout << i.getDivStrip() << i.getSpaces();
			moveCursor(getCursorPos().X + 3, getCursorPos().Y);
		}
		cout << endl;

		for (Friction i : frictionVec) {
			cout << i.getSpaces() << i.getDenumerator() << i.getSpaces();
			moveCursor(getCursorPos().X + 4, getCursorPos().Y);
		}
	}
}