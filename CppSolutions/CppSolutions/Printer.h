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

	template<typename... Args>
	static void printAll(Args&... args) {
		//((cout << " " << std::forward<Args>(args)), ...);
		//(cout << ... << forward<Args>(args)) << '\n';
		//((cout << std::forward<Args>(args) << " "), ...);
		((print(std::forward<Args>(args))), ...);
		cout << '\n';
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

	template<typename T>
	static void printBinary(T t, int sz = 32) {
		for (uint64_t i = (1ULL << (sz - 1)); i > 0; i >>= 1)
			cout << ((t & i) > 0);
		cout << endl;
	}
};

