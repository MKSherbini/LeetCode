//#include <bits/stdc++.h>
using namespace std;
#include "stdc++.h"

int main()
{

	int T;
	cin >> T;
	for (size_t t = 1; t <= T; t++)
	{
		printf("Case #%d:", t);
		int arr[4] = { INT_MAX ,INT_MAX ,INT_MAX ,INT_MAX };
		for (size_t i = 0; i < 3; i++) {
			int x;
			for (size_t i = 0; i < 4; i++)
			{
				cin >> x;
				arr[i] = min(arr[i], x);
			}
		}

		int goal = 1000000;

		//Printer::print(arr[0], arr[1], arr[2], arr[3]);
		if (goal > arr[0] + arr[1] + arr[2] + arr[3]) cout << " IMPOSSIBLE\n";
		else {
			size_t i;
			for (i = 0; i < 4; i++)
			{
				goal -= arr[i];
				cout << " " << min(arr[i], goal + arr[i]);
				if (goal <= 0)
					break;
			}

			for (i = i + 1; i < 4; i++)
			{
				cout << " " << 0;
			}
			cout << "\n";
		}
	}
}