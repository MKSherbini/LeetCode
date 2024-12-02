#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/check-if-a-word-occurs-as-a-prefix-of-any-word-in-a-sentence

class CheckIfAWordOccursAsAPrefixOfAnyWordInASentence {
public:
    // 0 ms, faster than 100% : 8.05 MB, less than 8.49%
    int solution(string sentence, string searchWord)
    {
        if (sentence.starts_with(searchWord))
            return 1;

        int i = 0, n = size(sentence), m = size(searchWord);
        int ans = 1;
        while (i < n) {
            if (sentence[i] != ' ') {
                i++;
                continue;
            }
            i++;
            ans++;

            for (size_t j = 0; j < m; j++) {
                if (sentence[i] != searchWord[j])
                    goto skp;
                i++;
                if (i == n && j != m - 1)
                    return -1;
            }
            return ans;
        skp:;
        }

        return -1;
    }
    vector<int> output = {
        4,
        2,
        -1
    };
    static constexpr int const& inputs = 2;
    vector<string> input1 = {
        "i love eating burger",
        "this problem is an easy problem",
        "i am tired"
    };
    vector<string> input2 = {
        "burg",
        "pro",
        "you"
    };
};