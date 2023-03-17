#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/implement-trie-prefix-tree/


class ImplementTriePrefixTree
{
public:
	ImplementTriePrefixTree() {
	}

	// 48 ms, faster than 97.06% : 44.8 MB, less than 81.92%
	void insert(string word) {
		trie.add(word);
	}

	bool search(string word) {
		return trie.search(word);
	}

	bool startsWith(string prefix) {
		return trie.searchPrefix(prefix);
	}

	TrieNode trie;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */