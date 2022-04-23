#include <bits/stdc++.h>
using namespace std;
//#include "stdc++.h"

int main()
{
	int T;
	cin >> T;
	for (size_t t = 1; t <= T; t++)
	{
		string s, res;
		cin >> s;


		size_t j = 0;
		for (size_t i = 0; i < s.length() - 1; i++)
		{
			j = i;
			for (; j < s.length(); j++)
				if (s[i] != s[j]) break;

			if (j - 1 < s.length() && s[i] < s[j])
				res += string((j - i) * 2, s[i]);
			else if (j > i + 1)
				res += string((j - i), s[i]);
			else
				res += s[i];


			i = j - 1;
		}
		if (j < s.size())
			res += s[s.size() - 1];
		//Printer::print(s.size(), res.size());

		printf("Case #%d: %s\n", t, res.c_str());

	}
}