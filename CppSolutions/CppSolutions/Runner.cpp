#include "stdc++.h"
#include "TimeBasedKeyValueStore.h"

//#include <bits/stdc++.h>
//using namespace std;


int main()
{
	freopen("output.txt", "w", stdout);
	freopen("input.txt", "r", stdin);
	//Runner(true).run<MinimumTimeToMakeRopeColorful>();
	TimeBasedKeyValueStore t;
	t.set("foo", "bar", 10);
	t.set("foo", "baz", 20);
	Printer::print(t.get("foo", 5));
	Printer::print(t.get("foo", 10));
	Printer::print(t.get("foo", 15));
	Printer::print(t.get("foo", 20));
	Printer::print(t.get("foo", 25));

	map<int, int> m;
	m[0] = 0;
	auto it = begin(m);
	--it;
	Printer::print(it == end(m));
	--it;
	Printer::print(it == end(m));
	--it;
	Printer::print(it == end(m));

}

