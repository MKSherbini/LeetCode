//#include <bits/stdc++.h>
using namespace std;
#include "stdc++.h"

int main()
{

	int T;
	cin >> T;
	for (size_t t = 1; t <= T; t++)
	{
		printf("Case #%d:\n", t);
		int r, c;
		cin >> r >> c;

		for (size_t j = 0; j < r * 2 + 1; j++) {
			for (size_t i = 0; i < c * 2 + 1; i++)
			{
				if (i <= 1 && j <= 1) {
					cout << ".";
				}
				else if (i % 2 && j % 2) {
					cout << ".";
				}
				else if (i % 2 == 0 && j % 2 == 1) {
					cout << "|";
				}
				else if (i % 2 == 1 && j % 2 == 0) {
					cout << "-";
				}
				else if (i % 2 == 0 && j % 2 == 0) {
					cout << "+";
				}
				else {
					cout << " ";
				}
			}
			cout << '\n';
		}
	}
}