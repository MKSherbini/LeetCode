#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/maximum-product-of-word-lengths/

class MaximumProductOfWordLengths
{
public:
	// 52 ms, faster than 81.88% : 17.5 MB, less than 33.55%
	int solution(vector<string> words) {
		map<int, size_t> mp;
		vector<int> mem(words.size());

		for (size_t i = 0; i < words.size(); i++) {
			int bits = toBitmap(words[i]);
			mp[bits] = max(mp[bits], words[i].size());
			mem[i] = bits;
		}

		size_t mx = 0;
		for (size_t i = 0; i < words.size(); i++)
			for (auto& w2 : mp)
				if (((~mem[i]) & w2.first) == w2.first) {
					mx = max(mx, w2.second * words[i].size());
					Printer::print(words[i], w2.second);
				}

		return mx;
	}

	// 83 ms, faster than 48.33% : 16.5 MB, less than 48.59%
	int solution2(vector<string> words) {
		vector<int> mem(words.size());

		for (size_t i = 0; i < words.size(); i++) {
			int bits = toBitmap(words[i]);
			mem[i] = bits;
		}

		size_t mx = 0;
		for (size_t i = 0; i < words.size(); i++)
			for (size_t j = 0; j < words.size(); j++)
				if (((~mem[i]) & mem[j]) == mem[j]) {
					mx = max(mx, words[i].size() * words[j].size());
					Printer::print(words[i], words[j]);
				}

		return mx;
	}

	int toBitmap(string word) {
		int x = 0;
		for (auto c : word)
			x |= 1 << (c - 'a');
		return x;
	}

	vector<int> output = {
		16,
		4,
		0,
		45
	};
	static constexpr int const& inputs = 1;
	vector<vector<string>> input1 = {
		{"abcw","baz","foo","bar","xtfn","abcdef"},
		{"a","ab","abc","d","cd","bcd","abcd"},
		{"a","aa","aaa","aaaa"},
		{"bdcecbcadca","caafd","bcadc","eaedfcd","fcdecf","dee","bfedd","ffafd","eceaffa","caabe","fbdb","acafbccaa","cdc","ecfdebaafde","cddbabf","adc","cccce","cbbe","beedf","fafbfdcb","ceecfabedbd","aadbedeaf","cffdcfde","fbbdfdccce","ccada","fb","fa","ec","dddafded","accdda","acaad","ba","dabe","cdfcaa","caadfedd","dcdcab","fadbabace","edfdb","dbaaffdfa","efdffceeeb","aefdf","fbadcfcc","dcaeddd","baeb","beddeed","fbfdffa","eecacbbd","fcde","fcdb","eac","aceffea","ebabfffdaab","eedbd","fdeed","aeb","fbb","ad","bcafdabfbdc","cfcdf","deadfed","acdadbdcdb","fcbdbeeb","cbeb","acbcafca","abbcbcbaef","aadcafddf","bd","edcebadec","cdcbabbdacc","adabaea","dcebf","ffacdaeaeeb","afedfcadbb","aecccdfbaff","dfcfda","febb","bfffcaa","dffdbcbeacf","cfa","eedeadfafd","fcaa","addbcad","eeaaa","af","fafc","bedbbbdfae","adfecadcabe","efffdaa","bafbcbcbe","fcafabcc","ec","dbddd","edfaeabecee","fcbedad","abcddfbc","afdafb","afe","cdad","abdffbc","dbdbebdbb" }
	};
};