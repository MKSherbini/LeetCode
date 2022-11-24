#pragma once
#include "stdc++.h"
using namespace std;

class TrieNode {
public:
	string word = "";
	char c = 0;
	bool isTerminal = false;
	bool isDeleted = false;
	TrieNode* parent = NULL;
	unordered_map<char, TrieNode*> next;
	TrieNode() {
	}
	~TrieNode() {
		for (auto c : next)
			delete c.second;
	}
	TrieNode(char c) {
		this->c = c;
	}
	void add(string& s, int i = 0) {
		int c = s[i];
		if (i < size(s)) {
			if (!next[c]) {
				auto newnode = new TrieNode(c);
				next[c] = newnode;
			}
			next[c]->add(s, i + 1);
		}
		else
		{
			isTerminal = true;
			word = s;
		}
	}
	void remove() {
		isTerminal = false;
		//if (next.empty() && parent) deleted = true, parent->remove(this->c);
	}
	void remove(char c) {
		//delete next[c];
		next.erase(c);
		if (next.empty() && parent) isDeleted = true, parent->remove(this->c);
	}
};
