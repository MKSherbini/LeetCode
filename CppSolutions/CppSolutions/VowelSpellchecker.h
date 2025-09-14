#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/vowel-spellchecker

class VowelSpellchecker {
public:
    // 33 ms, faster than 87.97% : 42.96 MB, less than 24.68%
    vector<string> solution(vector<string> wordlist, vector<string> queries)
    {
        unordered_map<string, string> exact, lower, vowel;

        for (const auto& word : wordlist) {
            exact[word] = word;

            string t = word;
            transform(t.begin(), t.end(), t.begin(), ::tolower);

            if (!lower.count(t))
                lower[t] = word;

            string vowels = "aeiou";
            transform(t.begin(), t.end(), t.begin(), [&](char c) {
               return vowels.find(c) != string::npos ? c = '#' : c;
            });
            if (!vowel.count(t))
                vowel[t] = word;
        }
        vector<string> ans;
        for (const auto& query : queries) {
            if (exact.count(query))
                ans.push_back(exact[query]);
            else {
                string t = query;
                transform(t.begin(), t.end(), t.begin(), ::tolower);
                if (lower.count(t))
                    ans.push_back(lower[t]);
                else {
                    string vowels = "aeiou";
                    transform(t.begin(), t.end(), t.begin(), [&](char c) {
                        return vowels.find(c) != string::npos ? c = '#' : c;
                    });
                    if (vowel.count(t))
                        ans.push_back(vowel[t]);
                    else
                        ans.push_back("");
                }
            }
        }

        return ans;
    }
    vector<vector<string>> output = {
        { "kite", "KiTe", "KiTe", "Hare", "hare", "", "", "KiTe", "", "KiTe" },
        { "yellow" }
    };
    static constexpr int const& inputs = 2;
    vector<vector<string>> input1 = {
        { "KiTe", "kite", "hare", "Hare" },
        { "yellow" }
    };
    vector<vector<string>> input2 = {
        { "kite", "Kite", "KiTe", "Hare", "HARE", "Hear", "hear", "keti", "keet", "keto" },
        { "YellOw" }
    };
};