#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/find-the-lexicographically-largest-string-from-the-box-i

class FindTheLexicographicallyLargestStringFromTheBoxI {
public:
    // 11 ms, faster than 91.42% : 37.05 MB, less than 76.49%
    string solution(string word, int numFriends)
    {
        if (numFriends == 1) {
            return word;
        }

        int n = word.size();
        set<char> s;
        for (int i = 0; i < n; i++) {
            s.insert(word[i]);
        }
        char maxChar = *s.rbegin();

        string ans;
        for (int i = 0; i < n; i++) {
            if (word[i] == maxChar) {
                int left = max(0, numFriends - i - 1);
                Printer::print(i, n, left, numFriends);
                ans = max(ans, word.substr(i, n - left - i));
            }
        }

        return ans;
    }
    vector<string> output = {
        "dbc",
        "g"
    };
    static constexpr int const& inputs = 2;
    vector<string> input1 = {
        "dbca",
        "gggg"
    };
    vector<int> input2 = {
        2,
        4
    };
};