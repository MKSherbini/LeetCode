#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/maximum-score-words-formed-by-letters/

class MaximumScoreWordsFormedByLetters
{
public:
	// 5 ms, faster than 77.76% : 15.6 MB, less than 57.52%
	int solution(vector<string>& words, vector<char>& letters, vector<int>& score) {
		return curse(words, letters, score, 0, 0);
	}
	int curse(vector<string>& words, vector<char>& letters, vector<int>& score, int index, int accScore) {
		if (index == words.size()) return accScore;

		int mx = accScore;

		mx = max(mx, curse(words, letters, score, index + 1, accScore));
		int wordScore = 0, satisfied = 1;
		vector<char> tempLetters = letters;
		for (int j = 0; j < words[index].size(); j++)
		{
			vector<char>::iterator found;
			if ((found = find(begin(tempLetters), end(tempLetters), words[index][j])) != end(tempLetters)) {
				wordScore += score[*found - 'a'];
				tempLetters.erase(found);
			}
			else {
				satisfied = 0;
				break;
			}
		}
		if (satisfied)
			mx = max(mx, curse(words, tempLetters, score, index + 1, accScore + wordScore));

		return mx;
	}

	vector<int> output = {
		23,
		27,
		0,
		51,
	};
	vector<vector<string>> input1 = {
		{"dog","cat","dad","good"},
		{"xxxz","ax","bx","cx"},
		{"leetcode"},
		{"add", "dda", "bb", "ba", "add"},
	};

	vector<vector<char>> input2 = {
		{'a','a','c','d','d','d','g','o','o'},
		{'z','a','b','c','x','x','x'},
		{'l','e','t','c','o','d'},
		{'a', 'a', 'a', 'a', 'b', 'b', 'b', 'b', 'c', 'c', 'c', 'c', 'c', 'd', 'd', 'd'},
	};
	vector<vector<int>> input3 = {
		{1,0,9,5,0,0,3,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0},
		{4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0,10},
		{0,0,1,1,1,0,0,0,0,0,0,1,0,0,1,0,0,0,0,1,0,0,0,0,0,0},
		{3, 9, 8, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	};

};

