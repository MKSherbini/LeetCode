#pragma once
#include "stdc++.h"
using namespace std;

class Printer
{
public:
	template<typename T>
	static void printOne(const T& v, bool newLine = 0) {
		cout << v << (newLine ? "\n" : " ");
	}

	template<typename... Args>
	static void print(const Args&... args) {
		//((cout << " " << std::forward<Args>(args)), ...);
		//(cout << ... << forward<Args>(args)) << '\n';
		//((cout << std::forward<Args>(args) << " "), ...);
		((printOne(std::forward<const Args>(args))), ...);
		cout << '\n';
	}

	static void printOne(ListNode* head) {
		auto t = head;
		while (t)
		{
			cout << t->val << " ";
			t = t->next;
		}
		cout << endl;
	}

	static const int SPACING = 1;

	static void printOne(TrieNode* root, char c = '.', int space = 0) {
		if (root == NULL)
			return;

		for (int i = 0; i < space; i++)
			cout << "\t";
		printOne(c);
		printOne(root->isTerminal, 1);

		for (auto& [c, trie] : root->next) {
			printOne(trie, c, space + 1);
		}
	}

	static void printOne(TreeNode* root, int space = 0) {
		if (root == NULL)
			return;
		space += SPACING;
		printOne(root->right, space);
		for (int i = SPACING; i < space; i++)
			cout << "\t";
		cout << root->val << "\n";
		printOne(root->left, space);
	}

	template<typename T>
	static void printOne(const vector<T>& v) {
		for (auto a : v) {
			printOne(a);
		}
		cout << '\n';
	}

	template<typename ...T>
	static void printOne(const set<T...>& v) {
		for (auto a : v) {
			printOne(a);
		}
		cout << '\n';
	}

	template<typename ...T>
	static void printOne(const unordered_set<T...>& v) {
		for (auto a : v) {
			printOne(a);
		}
		cout << '\n';
	}

	template<typename ...T>
	static void printOne(const multiset<T...>& v) {
		for (auto a : v) {
			printOne(a);
		}
		cout << '\n';
	}

	template<typename ...T>
	static void printOne(const list<T...>& v) {
		for (auto a : v) {
			printOne(a);
		}
		cout << '\n';
	}

	template<typename T>
	static void printOne(const queue<T>& v) {
		auto t = v;
		while (!t.empty())
		{
			printOne(t.front());
			t.pop();
			if (!t.empty()) printOne(", ");
		}
		cout << '\n';
	}

	template<typename T>
	static void printOne(const priority_queue<T>& v) {
		priority_queue<T> t = v;
		while (!t.empty())
		{
			printOne(t.top());
			t.pop();
			if (!t.empty()) printOne(", ");
		}
		cout << '\n';
	}

	template<typename T>
	static void printOne(const stack<T>& v) {
		auto t = v;
		while (!t.empty())
		{
			printOne(t.top());
			t.pop();
			if (!t.empty()) printOne(", ");
		}
		cout << '\n';
	}

	template<typename T, typename R, typename V>
	static void printOne(const priority_queue<T, R, V>& v) {
		auto t = v;
		while (!t.empty())
		{
			printOne(t.top());
			t.pop();
			if (!t.empty()) printOne(", ");
		}
		cout << '\n';
	}

	template<typename T, typename R>
	static void printOne(const map<T, R>& v) {
		for (auto a : v) {
			printOne(a);
			cout << '\n';
		}
		cout << '\n';
	}

	template<typename T, typename R>
	static void printOne(const unordered_map<T, R>& v) {
		for (auto a : v) {
			printOne(a);
			cout << '\n';
		}
		cout << '\n';
	}

	template<typename T, typename R>
	static void printOne(const pair<T, R>& v) {
		cout << "(";
		printOne(v.first);
		cout << ", ";
		printOne(v.second);
		cout << ")";
	}

	template<typename T, typename R, typename V>
	static void printOne(const tuple<T, R, V>& v) {
		cout << "(";
		printOne(get<0>(v));
		cout << ", ";
		printOne(get<1>(v));
		cout << ", ";
		printOne(get<2>(v));
		cout << ")";
	}

	static void printOne(const vector<string>& v) {
		for (auto a : v) {
			printOne(a);
			cout << '\n';
		}
		cout << '\n';
	}

	template<typename T>
	static void printBinary(T t, int sz = 32) {
		for (uint64_t i = (1ULL << (sz - 1)); i > 0; i >>= 1)
			cout << ((t & i) > 0);
		cout << endl;
	}
};

