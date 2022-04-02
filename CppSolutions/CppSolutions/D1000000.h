//#include <bits/stdc++.h>
using namespace std;
#include "stdc++.h"

int main()
{

	int T;
	cin >> T;
	for (size_t t = 1; t <= T; t++)
	{
		int n;
		cin >> n;
		multiset<int> s;
		while (n--) {
			int x;
			cin >> x;
			s.insert(x);
		}
		int i = 1;
		for (auto x : s)
			if (x >= i) i++;
		printf("Case #%d: %d\n", t, i - 1);

	}
}