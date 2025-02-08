#pragma once
#include "stdc++.h"

// https://leetcode.com/problems/design-a-number-container-system

class DesignaNumberContainerSystem {
public:
    // 92 ms, faster than 90% : 195.76 MB, less than 71.56%
    DesignaNumberContainerSystem()
    {
    }

    void change(int index, int number)
    {
        if (indexToNum.count(index)) {
            m[indexToNum[index]].erase(index);
            if (m[indexToNum[index]].empty()) {
                m.erase(indexToNum[index]);
            }
        }

        indexToNum[index] = number;
        m[number].insert(index);
    }

    int find(int number)
    {
        if (!m.count(number))
            return -1;

        return *m[number].begin();
    }

private:
    unordered_map<int, set<int>> m;
    unordered_map<int, int> indexToNum;
};