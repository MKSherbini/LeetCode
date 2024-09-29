#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/all-oone-data-structure/description/

class AllOoneDataStructure {

public:
    // 79 ms, faster than 92.02% : 54.19 MB, less than 80.69%
    void AllOne()
    {
    }

    void inc(string key)
    {
        s.erase({ m[key], key });
        m[key]++;
        s.insert({ m[key], key });
    }

    void dec(string key)
    {
        s.erase({ m[key], key });
        if (m.count(key))
            m[key]--;

        if (m[key])
            s.insert({ m[key], key });
    }

    string getMaxKey()
    {
        if (s.empty())
            return "";

        return s.rbegin()->second;
    }

    string getMinKey()
    {
        if (s.empty())
            return "";

        return s.begin()->second;
    }

private:
    unordered_map<string, int> m;
    set<pair<int, string>> s;
};