#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/uncommon-words-from-two-sentences/description/

class UncommonWordsFromTwoSentences {
public:
    // 0 ms, faster than 100% : 8.63 MB, less than 97.06%
    vector<string> uncommonFromSentences(string s1, string s2)
    {
        s1.push_back(' ');
        s2.push_back(' ');
        vector<string> ans;
        unordered_map<string, int> m;

        int i = 0, last = 0;
        while ((i = s1.find(" ", i)) != string::npos) {
            i++;
            m[s1.substr(last, i - last - 1)]++;
            last = i;
        }

        i = 0, last = 0;
        while ((i = s2.find(" ", i)) != string::npos) {
            i++;
            m[s2.substr(last, i - last - 1)]++;
            last = i;
        }

        for (auto& [w, f] : m)
            if (f == 1)
                ans.push_back(w);

        return ans;
    }
};