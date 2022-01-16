#pragma once
#include "stdc++.h"
using namespace std;

class Printer
{
public:
	template<typename T>
	static void print(const T& v, bool newLine = 0) {
		cout << v << (newLine ? "\n" : " ");
	}

	template<typename T>
	static void print(const vector<T>& v) {
		for (auto a : v) {
			print(a);
		}
		cout << '\n';
	}

	static void print(const vector<string>& v) {
		for (auto a : v) {
			print(a);
			cout << '\n';
		}
		cout << '\n';
	}
};

