#pragma once
#include <string>
#include <iostream>
using namespace std;
class Error {
private:
	string str;
public:
	Error(string s) {
		str = s;
	}
	void what() {
		cout << str << endl;
	}
};