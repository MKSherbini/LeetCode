#pragma once
#include "stdc++.h"
using namespace std;

template<typename T>
class Printer
{
public:
	static void print(vector<T>& v) {
		for (auto a : v) {
			cout << a << " ";
		}
		cout << endl;
	}

	static void print(T v) {
		cout << v << endl;
	}

};

