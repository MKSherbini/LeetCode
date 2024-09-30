#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/design-a-stack-with-increment-operation/description/

class DesignAStackWithIncrementOperation {
public:
    // 19 ms, faster than 95.87% : 25.86 MB, less than 92.52%
    DesignAStackWithIncrementOperation(int maxSize)
    {
        v.resize(maxSize);
    }
    void push(int x)
    {
        if (top < size(v))
            v[top++] = x;
    }

    int pop()
    {
        if (top > 0)
            return v[--top];

        return -1;
    }

    void increment(int k, int val)
    {
        for (size_t i = 0; i < min(k, top); i++) {
            v[i] += val;
        }
    }

private:
    vector<int> v;
    int top = 0;
};