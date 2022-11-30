#include "stdc++.h"
#include "InsertDeleteGetrandomO1.h"

//#include <bits/stdc++.h>
//using namespace std;


int main()
{
	freopen("output.txt", "w", stdout);
	freopen("input.txt", "r", stdin);
	//Runner(false).run<FindPlayersWithZeroOrOneLosses>();
	InsertDeleteGetrandomO1 r;

	Printer::print(r.insert(1));
	Printer::print(r.remove(2));
	Printer::print(r.insert(2));
	Printer::print(r.getRandom());
	Printer::print(r.remove(1));
	Printer::print(r.insert(2));
	Printer::print(r.getRandom());

}

