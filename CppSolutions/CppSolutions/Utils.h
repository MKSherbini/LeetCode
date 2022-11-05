#pragma once
//#include "stdc++.h"
using namespace std;

class Utils
{
public:
	template<typename T, typename... Others>
	auto coalesce(T option, Others... others) {
		return option != NULL ? option : coalesce(forward<Others>(others)...);
	}
	template<typename T>
	T coalesce(T option) {
		return option;
	}
};

