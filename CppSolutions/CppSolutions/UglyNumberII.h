#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/ugly-number-ii/description/

class UglyNumberII {
public:
    // 70 ms, faster than 32.28% : 32.62 MB, less than 19.62%
    int solution(int n)
    {
        unordered_set<int> s;
        priority_queue<int, vector<int>, greater<int>> pq;
        pq.push(1);
        s.insert(1);

        while (--n) {
            int el = pq.top();
            Printer::print(n, el);
            pq.pop();
            for (auto x : { el * 2ll, el * 3ll, el * 5ll }) {
                if (x <= INT_MAX && !s.count(x)) {
                    pq.push(x);
                    s.insert(x);
                }
            }
        }

        return pq.top();
    }
    vector<int> output = {
        12,
        1
    };
    static constexpr int const& inputs = 1;
    vector<int> input1 = {
        10,
        1
    };
};