#pragma once
#include "stdc++.h"
using namespace std;

class Validator
{
public:
	static int8_t valid(ListNode* node, ListNode* node2) {
		if (node && node2)
			return  node->val == node2->val && valid(node->next, node2->next);
		return  (!node ^ !node2) == 0;
	}

	template<typename T, typename T2>
	static int8_t valid(const T& v, const T2& v2) {
		return v == v2;
	}

	static int8_t valid(const double& v, const double& v2) {
		return abs(v-v2) < 1e-5;
	}

	template<typename T, typename T2>
	static int8_t valid(const vector<T>& v, const vector<T2>& v2) {
		if (v.size() != v2.size()) return 0;

		for (int i = 0; i < v.size(); i++)
			if (!valid(v[i], v2[i])) return 0;

		return 1;
	}
};

