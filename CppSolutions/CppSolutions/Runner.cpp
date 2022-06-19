#include "stdc++.h"
#include "PrefixAndSuffixSearch.h"

// todo improve printing + examples running

//#include <bits/stdc++.h>
//using namespace std;


int main()
{
	freopen("output.txt", "w", stdout);
	freopen("input.txt", "r", stdin);
	//Runner(true).run<IntersectionOfTwoArrays>();
	auto x = PrefixAndSuffixSearch({ "cabaabaaaa", "ccbcababac", "bacaabccba", "bcbbcbacaa", "abcaccbcaa", "accabaccaa", "cabcbbbcca", "ababccabcb", "caccbbcbab", "bccbacbcba" });

	vector<pair<string, string>> y = { {"bccbacbcba", "a"} , {"ab", "abcaccbcaa"}, {"a", "aa"}, {"cabaaba", "abaaaa"}, {"cacc", "accbbcbab"}, {"ccbcab", "bac"}, {"bac", "cba"}, {"ac", "accabaccaa"}, {"bcbb", "aa"}, {"ccbca", "cbcababac"} };
	for (auto p : y)
		Printer::print(p.first, p.second, x.f(p.first, p.second));

}

