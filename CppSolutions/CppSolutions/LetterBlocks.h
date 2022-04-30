#include <bits/stdc++.h>
using namespace std;

// WA
int main()
{
	int T;
	cin >> T;
	for (size_t t = 1; t <= T; t++)
	{
		int n;
		cin >> n;

		int imp = 0;
		vector<string> wordsStart[26];
		vector<string> wordsEnd[26];
		vector<string> wordsSameLetter[26];
		for (size_t i = 0; i < n; i++)
		{
			string s;
			cin >> s;
			if (string(s.size(), s[0]) == s) {
				wordsSameLetter[s[0] - 'A'].push_back(s);
				continue;
			}
			if (wordsStart[s[0] - 'A'].size()) {
				imp = 1;
				break;
			}
			wordsStart[s[0] - 'A'].push_back(s);
			if (wordsEnd[s[s.size() - 1] - 'A'].size()) {
				imp = 1;
				break;
			}
			wordsEnd[s[s.size() - 1] - 'A'].push_back(s);
		}
		if (imp) {
			printf("Case #%d: %s\n", t, "IMPOSSIBLE");
			continue;
		}

		string res = "";

		while (true) {
			int done = 1;
			for (size_t i = 0; i < 26; i++)
			{
				if (wordsStart[i].size()) {
					string word = wordsStart[i][0];
					res += word;
					wordsEnd[word[word.size() - 1] - 'A'].pop_back();
					wordsStart[word[0] - 'A'].pop_back();
					done = 0;
					break;
				}
			}
			if (done) break;

			for (size_t i = 0; i < wordsSameLetter[res[res.size() - 1] - 'A'].size(); i++)
				res += wordsSameLetter[res[res.size() - 1] - 'A'][i];
			wordsSameLetter[res[res.size() - 1] - 'A'].clear();
			for (size_t i = 0; i < wordsSameLetter[res[0] - 'A'].size(); i++)
				res = wordsSameLetter[res[0] - 'A'][i] + res;
			wordsSameLetter[res[0] - 'A'].clear();

			while (wordsStart[res[res.size() - 1] - 'A'].size()) {
				string word = wordsStart[res[res.size() - 1] - 'A'][0];
				res += word;
				wordsEnd[word[word.size() - 1] - 'A'].pop_back();
				wordsStart[word[0] - 'A'].pop_back();
			}

			while (wordsEnd[res[0] - 'A'].size()) {
				string word = wordsEnd[res[0] - 'A'][0];
				res = word + res;
				wordsEnd[word[word.size() - 1] - 'A'].pop_back();
				wordsStart[word[0] - 'A'].pop_back();
			}
		}

		for (size_t i = 0; i < 26; i++)
		{
			for (size_t j = 0; j < wordsSameLetter[i].size(); j++)
			{
				res += wordsSameLetter[i][j];
			}
		}

		int vis[26] = { 0 };
		for (size_t i = 0; i < res.size(); i++)
		{
			if (!vis[res[i] - 'A']) {
				size_t j;
				for (j = i + 1; j < res.size(); j++)
					if (res[i] != res[j]) break;

				vis[res[i] - 'A'] = 1;
				i = j - 1;
			}
			else {
				imp = 1;
				break;
			}
		}
		if (imp) {
			printf("Case #%d: %s\n", t, "IMPOSSIBLE");
			continue;
		}
		printf("Case #%d: %s\n", t, res.c_str());
	}
}