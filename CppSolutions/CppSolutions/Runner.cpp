#include "stdc++.h"
#include "ImplementTriePrefixTree.h"

//#include <bits/stdc++.h>
//using namespace std;


int main()
{
	freopen("output.txt", "w", stdout);
	freopen("input.txt", "r", stdin);
	//Runner(true).run<KokoEatingBananas>();
	ImplementTriePrefixTree t;
	t.insert("abcd");
	t.insert("abce");
	t.insert("abee");
	Printer::print(&t.trie);
}

