#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/decode-xored-array/

class DecodeXoredArray
{
public:
	// 24 ms, faster than 88.36% : 24.7 MB, less than 99.58%
	vector<int> solution2(vector<int>& encoded, int first) {
		vector<int> original(encoded.size() + 1);
		original[0] = first;
		for (int i = 0; i < encoded.size(); i++)
			original[i + 1] = encoded[i] ^ original[i];
		return original;
	}
	vector<int> solution(vector<int>& encoded, int first) {
		encoded.insert(begin(encoded), first);
		for (int i = 1; i < encoded.size(); i++)
			encoded[i] = encoded[i] ^ encoded[i - 1];
		return encoded;
	}
	vector<vector<int>> output = {
		{1,0,2,1},
		{4,2,0,7,4},
	};
	vector<vector<int>> input1 = {
		{1,2,3},
		{6,2,7,3},
	};
	vector<int> input2 = {
			1,
			4,
	};
};

