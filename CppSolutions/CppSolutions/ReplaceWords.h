#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/replace-words/description/

class ReplaceWords {
public:
    // 115 ms, faster than 49.07% : 44.67 MB, less than 86.74%
    string solution(vector<string> dictionary, string sentence)
    {
        sort(begin(dictionary), end(dictionary));
        string ans;

        int lst = 0, nxt = 0;
        while (nxt = sentence.find(' ', lst)) {
            string s = sentence.substr(lst, nxt - lst);
            lst = nxt + 1;
            Printer::print(s);

            bool picked = 0;
            for (auto& w : dictionary) {
                if (s.starts_with(w)) {
                    ans += w + " ";
                    picked = 1;
                    break;
                }
            }
            if (!picked)
                ans += s + " ";

            if (nxt == -1)
                break;
        }

        ans.pop_back();
        return ans;
    }
    vector<string> output = {
        "the cat was rat by the bat",
        "a a b c"
    };
    static constexpr int const& inputs = 2;
    vector<vector<string>> input1 = {
        { "cat", "bat", "rat" },
        { "a", "b", "c" }
    };
    vector<string> input2 = {
        "the cattle was rattled by the battery",
        "aadsfasf absbs bbab cadsfafs"
    };
};