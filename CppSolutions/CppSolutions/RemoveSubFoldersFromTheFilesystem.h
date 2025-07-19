#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/remove-sub-folders-from-the-filesystem

class RemoveSubFoldersFromTheFilesystem {
public:
    // 57 ms, faster than 63.66% : 51.26 MB, less than 63.44%
    vector<string> solution(vector<string> folder)
    {
        sort(folder.begin(), folder.end());
        vector<string> ans;
        unordered_set<string> seen;
        for (const auto& f : folder) {
            int size = f.size();
            for (int i = 1; i < size; ++i) {
                if (f[i] == '/') {
                    if (seen.count(f.substr(0, i))) {
                        goto end;
                    }
                }
            }
            ans.push_back(f);
            seen.insert(f);

        end:;
        }

        return ans;
    }
    vector<vector<string>> output = {
        { "/a", "/c/d", "/c/f" },
        { "/a" },
        { "/a/b/c", "/a/b/ca", "/a/b/d" }
    };
    static constexpr int const& inputs = 1;
    vector<vector<string>> input1 = {
        { "/a", "/a/b", "/c/d", "/c/d/e", "/c/f" },
        { "/a", "/a/b/c", "/a/b/d" },
        { "/a/b/c", "/a/b/ca", "/a/b/d" }
    };
};