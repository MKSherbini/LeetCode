#pragma once
#include "stdc++.h"
using namespace std;

class TrieNode {
public:
	bool isTerminal = false;
	TrieNode* next[26] = { NULL };
	TrieNode() {
	}
	~TrieNode() {
	}
	void add(string& s) {
		TrieNode* node = findNode(s, true);
		node->isTerminal = true;
	}

	bool search(string& s) {
		TrieNode* node = findNode(s, false);
		return node && node->isTerminal;
	}

	bool searchPrefix(string& s) {
		return findNode(s, false);
	}

	void remove(string& s) {
		TrieNode* node = findNode(s, false);
		node->isTerminal = false;
	}

private:
	TrieNode* findNode(string& s, bool createPath) {
		TrieNode* node = this;
		for (auto c : s) {
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
