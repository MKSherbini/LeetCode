#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/find-duplicate-file-in-system/

class FindDuplicateFileInSystem
{
public:
	// 102 ms, faster than 96.95% : 39.8 MB, less than 56.49%
	vector<vector<string>> solution(vector<string> paths) {
		map<string, vector<string>> m;

		for (auto p : paths) {
			stringstream ss(p);
			string root;
			ss >> root;

			string file;
			while (ss >> file) {
				file.pop_back();
				int it = file.find('(');
				m[file.substr(it + 1)].push_back(root + '/' + file.substr(0, it));
			}
		}

		vector<vector<string>> ans;
		for (auto v : m) {
			if (v.second.size() > 1)
				ans.push_back(move(v.second));
		}

		return ans;
	}
	vector<vector<vector<string>>> output = {
		{{"root/a/2.txt","root/c/d/4.txt","root/4.txt"},{"root/a/1.txt","root/c/3.txt"}},
		{{"root/a/2.txt","root/c/d/4.txt"},{"root/a/1.txt","root/c/3.txt"}}
	};
	static constexpr int const& inputs = 1;
	vector<vector<string>> input1 = {
		{"root/a 1.txt(abcd) 2.txt(efgh)","root/c 3.txt(abcd)","root/c/d 4.txt(efgh)","root 4.txt(efgh)"},
		{"root/a 1.txt(abcd) 2.txt(efgh)","root/c 3.txt(abcd)","root/c/d 4.txt(efgh)"}
	};
};