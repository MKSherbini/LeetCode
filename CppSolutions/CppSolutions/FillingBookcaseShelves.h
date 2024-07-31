#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/filling-bookcase-shelves/description/

class FillingBookcaseShelves {
public:
    // 0 ms, faster than 100% : 21.96 MB, less than 12.54%
    int solution(vector<vector<int>> books, int shelfWidth)
    {
        int n = size(books);
        vector mem(n, vector(shelfWidth + 1, -1));
        function<int(int, int, int)> f = [&](int i, int w, int h) -> int {
            if (i >= n)
                return 0;

            if (mem[i][w] != -1)
                return mem[i][w];

            int ret = f(i + 1, books[i][0], books[i][1]) + books[i][1];
            if (w && w + books[i][0] <= shelfWidth) {
                ret = min(ret,
                    max(0, books[i][1] - h)
                        + f(i + 1, w + books[i][0], max(h, books[i][1])));
            }

            return mem[i][w] = ret;
        };

        return f(0, 0, 0);
    }
    vector<int> output = {
        6,
        4
    };
    static constexpr int const& inputs = 2;
    vector<vector<vector<int>>> input1 = {
        { { 1, 1 }, { 2, 3 }, { 2, 3 }, { 1, 1 }, { 1, 1 }, { 1, 1 }, { 1, 2 } },
        { { 1, 3 }, { 2, 4 }, { 3, 2 } }
    };
    vector<int> input2 = {
        4,
        6
    };
};