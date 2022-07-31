#include "stdc++.h"
#include "RangeSumQueryMutable.h"

//#include <bits/stdc++.h>
//using namespace std;


int main()
{
	freopen("output.txt", "w", stdout);
	freopen("input.txt", "r", stdin);
	//Runner(false).run<WordSubsets>();
	for (size_t i = 0; i < 20; i++)
	{
		cout << i << " ";
	}
	cout << endl;
	auto numArray = RangeSumQueryMutable({ 1, 3, 5 , 9, 6, 7 });
	Printer::print(numArray.sumRange(0, 2)); // return 1 + 3 + 5 = 9
	numArray.update(1, 2);   // nums = [1, 2, 5]
	Printer::print(numArray.sumRange(0, 2)); // return 1 + 2 + 5 = 8

}

