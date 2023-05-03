#pragma once
#include "stdc++.h"
using namespace std;

class Sorter
{
public:
	template<typename T>
	static void sort(T& v) {
	}

	template<typename T>
	static void sort(vector<T>& v) {
		std::sort(begin(v), end(v));
		for (auto& a : v)
			sort(a);
	}

};

