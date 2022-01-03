#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/shuffle-string/

class ShuffleString
{
public:
    string solution(string s, vector<int>& indices) {
        string r(s.size(), 'x');
        for (int i = 0; i < s.size(); i++)
            r[indices[i]] = s[i];

        return r;
    }
};

