#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/prefix-and-suffix-search/

class PrefixAndSuffixSearch
{
public:
	// what did he mean by largest??
	// 881 ms, faster than 31.35% : 150 MB, less than 72.39%
	PrefixAndSuffixSearch(vector<string>& words) {
		for (size_t i = 0; i < words.size(); i++)
		{
			for (size_t j = 1; j <= words[i].size(); j++)
			{
				for (size_t k = 1; k <= words[i].size(); k++)
				{
					m[words[i].substr(0, j) + " " +
						words[i].substr(words[i].size() - k, k)] = i + 1;
				}
			}
		}
	}

	int f(string prefix, string suffix) {
		return m[prefix + " " + suffix] - 1;
	}
private:
	unordered_map<string, int> m;


	//public:
		//PrefixAndSuffixSearch(vector<string> words) {
		//	this->words = words;
		//	for (size_t i = 0; i < words.size(); i++)
		//	{
		//		string s;
		//		for (size_t j = 0; j < words[i].size(); j++)
		//		{
		//			s += words[i][j];
		//			pre[s].push_back(i);
		//		}
		//		s = "";
		//		for (int j = (int)words[i].size() - 1; j >= 0; j--)
		//		{
		//			s = words[i][j] + s;
		//			post[s].push_back(i);
		//		}
		//	}
		//	for (auto& m : pre)
		//		sort(begin(m.second), end(m.second), [&](int i, int j) {return words[i] < words[j]; });
		//	for (auto& m : post)
		//		sort(begin(m.second), end(m.second), [&](int i, int j) {return words[i] < words[j]; });
		//	Printer::print(pre, post);
		//}

		//int f(string prefix, string suffix) {
		//	vector<int>& v = pre[prefix];
		//	vector<int>& v2 = post[suffix];

		//	int ans = -1;
		//	int i = 0, j = 0;
		//	while (i < v.size() && j < v2.size())
		//	{
		//		if (v[i] == v2[j] && (ans == -1 || words[ans] < words[v[i]])) {
		//			ans = v[i];
		//			while (i < v.size() && words[v[i]] == words[ans]) i++;
		//			while (j < v2.size() && words[v2[j]] == words[ans]) j++;
		//		}
		//		else if (words[v[i]] < words[v2[j]])
		//			i++;
		//		else
		//			j++;
		//	}
		//	return ans;
		//}
	//
	//private:
	//	unordered_map<string, vector<int>> pre;
	//	unordered_map<string, vector<int>> post;
	//	vector<string> words;
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */