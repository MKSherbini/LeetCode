#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/integer-to-english-words/description/

class IntegerToEnglishWords {
public:
    // 0 ms, faster than 100% : 12.57 MB, less than 16.4%
    string solution(int num)
    {
        if (!num)
            return "Zero";

        const vector<string> ones = { "", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine" };
        const vector<string> elevens = { "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen" };
        const vector<string> tens = { "", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety" };
        const vector<string> ranks = { "", "Thousand", "Million", "Billion" };

        function<string(int)> spell3Digit = [&](int x) -> string {
            if (x < 10)
                return ones[x];
            else if (x < 20)
                return elevens[x - 10];
            else if (x < 100) {
                auto t = spell3Digit(x % 10);
                return tens[x / 10] + (empty(t) ? "" : " ") + t;
            } else {
                auto t = spell3Digit(x % 100);
                return ones[x / 100] + " Hundred" + (empty(t) ? "" : " ") + t;
            }
        };

        stack<string> st;
        while (num) {
            st.push(spell3Digit(num % 1000));
            num /= 1000;
        }

        string ans;
        int i = size(st) - 1, start = i;
        while (!empty(st)) {
            if (!st.top().empty()) {
                if (start != i)
                    ans += " ";
                ans += st.top();
                if (i)
                    ans += " " + ranks[i];
            }
            i--;
            st.pop();
        }

        return ans;
    }
    vector<string> output = {
        "One Hundred Twenty Three",
        "Twelve Thousand Three Hundred Forty Five",
        "One Million Two Hundred Thirty Four Thousand Five Hundred Sixty Seven",
        "One Billion Two Hundred Ninety Four Million Nine Hundred Sixty Seven Thousand Two Hundred Ninety Five",
        "Twenty"
    };
    static constexpr int const& inputs = 1;
    vector<int> input1 = {
        123,
        12345,
        1234567,
        1294967295,
        20
    };
};