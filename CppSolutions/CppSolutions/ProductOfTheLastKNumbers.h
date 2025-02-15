#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/product-of-the-last-k-numbers

class ProductOfTheLastKNumbers {
public:
    // 4 ms, faster than 99.74% : 78.12 MB, less than 41.53%
    ProductOfTheLastKNumbers()
    {
    }

    void add(int num)
    {
        if (!num) {
            lastZero = size(v), v.push_back(0);
        } else if (empty(v) || v.back() == 0) {
            v.push_back(num);
        } else {
            v.push_back(num * v.back());
        }
    }

    int getProduct(int k)
    {
        int st = size(v) - k;
        if (st <= lastZero)
            return 0;

        if (st == 0 || v[st - 1] == 0)
            return v.back();

        return v.back() / v[st - 1];
    }

private:
    vector<int> v;
    int lastZero = -1;
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */
