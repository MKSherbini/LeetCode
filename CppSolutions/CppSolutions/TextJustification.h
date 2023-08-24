#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/text-justification/

class TextJustification
{
public:
	// 0 ms, faster than 100% : 7.3 MB, less than 69.74%
	vector<string> solution(vector<string> words, int maxWidth) {
		int n = size(words);
		int i = 0;
		vector<string> ans;
		while (true) {
			ans.push_back("");
			vector<int> row;
			int w = 0;
			for (int j = i; j < n; j++) {
				if (w + (int)size(words[j]) + (int)size(row) > maxWidth) break;
				row.push_back(j);
				w += size(words[j]);
			}
			i += size(row);
			Printer::print(i, w);

			if (i < n) {
				int spaces = maxWidth - w;
				int cnt = size(row) - 1;
				int spaceCnt = cnt == 0 ? 0 : spaces / cnt;
				int extras = cnt == 0 ? 0 : spaces % cnt;

				for (auto j : row)
					ans.back() += words[j] + (row.back() == j ? "" : string(spaceCnt + (extras-- > 0), ' '));

				if (maxWidth != size(ans.back()))
					ans.back() += string(maxWidth - size(ans.back()), ' ');
			}
			else {
				for (auto j : row)
					ans.back() += words[j] + (row.back() == j ? "" : " ");

				if (maxWidth != size(ans.back()))
					ans.back() += string(maxWidth - size(ans.back()), ' ');
				break;
			}
		}

		return ans;
	}
	vector<vector<string>> output = {
		{"This is an","example  of text","justification.  "},
		{"What must be","acknowledgment  ","shall be  "},
		{"Science  is  what we","understand   well","enough to explain to","a  computer.  Art is","everything  else  we","do      "}
	};
	static constexpr int const& inputs = 2;
	vector<vector<string>> input1 = {
		{"This","is","an","example","of","text","justification."},
		{"What","must","be","acknowledgment","shall","be"},
		{"Science","is","what","we","understand","well","enough","to","explain","to","a","computer.","Art","is","everything","else","we","do"}
	};
	vector<int> input2 = {
		16,
		16,
		20
	};
};