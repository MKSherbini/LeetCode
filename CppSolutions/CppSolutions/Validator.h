#pragma once
#include "stdc++.h"
using namespace std;

class Validator
{
public:
	template<typename T>
	static int8_t valid(const T& v, const T& v2) {
		return v == v2;
	}

	template<typename T>
	static int8_t valid(const vector<T>& v, const vector<T>& v2) {
		if (v.size() != v2.size()) return 0;

		for (int i = 0; i < v.size(); i++)
			if (!valid(v[i], v2[i])) return 0;

		return 1;
	}
};

