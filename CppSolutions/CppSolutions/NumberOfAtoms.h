#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/number-of-atoms/description/

class NumberOfAtoms {
public:
    // 0 ms, faster than 100% : 8.67 MB, less than 81.51%
    string solution(string formula)
    {
        vector<pair<string, int>> elements;
        stack<int> st;
        int n = size(formula);
        for (size_t i = 0; i < n; i++) {
            if (formula[i] == '(')
                st.push(size(elements));
            else if (formula[i] == ')') {
                i++;
                string cnt;
                while (i < n && isdigit(formula[i])) {
                    cnt += formula[i++];
                }
                i--;
                int repeats = cnt == "" ? 1 : stoi(cnt);
                for (size_t j = st.top(); j < size(elements); j++) {
                    elements[j].second *= repeats;
                }
                st.pop();
            } else {
                while (i < n && isupper(formula[i])) {
                    string el;
                    el += formula[i++];
                    while (i < n && islower(formula[i])) {
                        el += formula[i++];
                    }
                    string cnt;
                    while (i < n && isdigit(formula[i])) {
                        cnt += formula[i++];
                    }
                    elements.push_back({ el, cnt == "" ? 1 : stoi(cnt) });
                }
                i--;
            }
        }

        sort(begin(elements), end(elements));
        Printer::print(elements);

        string ans;
        n = size(elements);
        for (size_t i = 0; i < n; i++) {
            if (i + 1 < n && elements[i].first == elements[i + 1].first) {
                elements[i + 1].second += elements[i].second;
                continue;
            }
            ans += elements[i].first;
            if (elements[i].second > 1)
                ans += to_string(elements[i].second);
        }

        return ans;
    }
    vector<string> output = {
        "H2O",
        "H2MgO2",
        "K4N2O14S4"
    };
    static constexpr int const& inputs = 1;
    vector<string> input1 = {
        "H2O",
        "Mg(OH)2",
        "K4(ON(SO3)2)2"
    };
};