#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/sum-of-prefix-scores-of-strings/description/

class TrieNode {
public:
    bool isTerminal = false;
    int cameThroughHere = 0;
    TrieNode* next[26] = { NULL };
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
        node->cameThroughHere++;
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

    int sumPrefix(string& s)
    {
        TrieNode* node = this;
        int sum = 0;
        for (auto c : s) {
            c = tolower(c) - 'a';
            node = node->next[c];
            sum += node->cameThroughHere;
        }

        return sum;
    }

private:
    TrieNode* findNode(string& s, bool createPath)
    {
        TrieNode* node = this;
        for (auto c : s) {
            node->cameThroughHere++;
            c = tolower(c) - 'a';
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

class SumOfPrefixScoresOfStrings {
public:
    // 467 ms, faster than 87.78% : 703.96 MB, less than 74.56%
    vector<int> solution(vector<string> words)
    {
        TrieNode trie;
        for (auto& w : words)
            trie.add(w);

        vector<int> ans;
        for (auto& w : words)
            ans.push_back(trie.sumPrefix(w));

        return ans;
    }
    vector<vector<int>> output = {
        { 5, 4, 3, 2 },
        { 4 }
    };
    static constexpr int const& inputs = 1;
    vector<vector<string>> input1 = {
        { "abc", "ab", "bc", "b" },
        { "abcd" }
    };
};