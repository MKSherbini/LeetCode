#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/design-add-and-search-words-data-structure/

class TrieNode {
public:
	bool isTerminal = false;
	TrieNode* next[26] = { NULL };
	TrieNode() {
	}
	~TrieNode() {
	}
	void add(string& s) {
		TrieNode* node = this;
		for (auto c : s) {
			c = tolower(c) - 'a';
			if (!node->next[c]) {
					node->next[c] = new TrieNode();
			}
			node = node->next[c];
		}
		node->isTerminal = true;
	}

	bool search(string& s, int i = 0) {
		if (i == size(s)) return isTerminal;

		bool ret = false;
		int c = s[i] - 'a';
		if (s[i] == '.') {
			for (auto p : next)
				if (p)
					ret |= p->search(s, i + 1);
		}
		else if (next[c]) {
			ret |= next[c]->search(s, i + 1);
		}
		return ret;
	}

};

class DesignAddAndSearchWordsDataStructure
{
public:
	// 946 ms, faster than 83.51% : 558.3 MB, less than 75.96%
	DesignAddAndSearchWordsDataStructure() {

	}

	void addWord(string word) {
		trie.add(word);
	}

	bool search(string word) {
		return trie.search(word);
	}
private:
	TrieNode trie;
};