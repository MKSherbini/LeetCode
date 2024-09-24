#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/find-the-length-of-the-longest-common-prefix/description/

class TrieNode {
public:
    bool isTerminal = false;
    TrieNode* next[10] = { NULL };
    TrieNode()
    {
    }
    ~TrieNode()
    {
    }
    void add(string& s)
    {
        TrieNode* node = findNode(s, true);
        node->isTerminal = true;
    }

    bool search(string& s)
    {
        TrieNode* node = findNode(s, false);
        return node && node->isTerminal;
    }

    bool searchPrefix(string& s)
    {
        return findNode(s, false);
    }

    void remove(string& s)
    {
        TrieNode* node = findNode(s, false);
        node->isTerminal = false;
    }

    int findMaxPrefix(string& s)
    {
        TrieNode* node = this;
        int len = 0;
        for (auto c : s) {
            c = tolower(c) - '0';
            if (!node->next[c]) {
                return len;
            }
            node = node->next[c];
            len++;
        }
        return len;
    }

private:
    TrieNode* findNode(string& s, bool createPath)
    {
        TrieNode* node = this;
        for (auto c : s) {
            c = tolower(c) - '0';
            if (!node->next[c]) {
                if (createPath)
                    node->next[c] = new TrieNode();
                else
                    return NULL;
            }
            node = node->next[c];
        }
        return node;
    }
};

class FindTheLengthOfTheLongestCommonPrefix {
public:
    // 206 ms, faster than 95.1% : 169.21 MB, less than 48.6%
    int solution(vector<int> arr1, vector<int> arr2)
    {
        TrieNode trie;

        for (int x : arr1) {
            string s = to_string(x);
            trie.add(s);
        }

        int ans = 0;
        for (int x : arr2) {
            string s = to_string(x);
            ans = max(ans, trie.findMaxPrefix(s));
        }

        return ans;
    }
    vector<int> output = {
        3,
        0
    };
    static constexpr int const& inputs = 2;
    vector<vector<int>> input1 = {
        { 1, 10, 100 },
        { 1, 2, 3 }
    };
    vector<vector<int>> input2 = {
        { 1000 },
        { 4, 4, 4 }
    };
};