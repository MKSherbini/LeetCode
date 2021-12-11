#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/longest-substring-without-repeating-characters/

class LengthOfLongestSubstring
{
public:
	// 0 ms, faster than 100.00% : 6.8 MB, less than 95.61% 
	int solution(string s) {
		int lastPos[256] = { 0 }, sz = 0, maxSize = 0, closestCut = 0;
		memset(lastPos, -1, 256 * sizeof(int));

		for (int i = 0; i < s.size(); i++) {
			if (lastPos[s[i]] == -1) {
				sz++;
				lastPos[s[i]] = i;
			}
			else {
				closestCut = max(lastPos[s[i]], closestCut);
				sz = i - closestCut;
				lastPos[s[i]] = i;
			}
			maxSize = max(sz, maxSize);
			// cout << sz << " " << maxSize << endl;
		}

		return maxSize;
	}
};

