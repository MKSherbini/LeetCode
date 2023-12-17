#include "stdc++.h"
#include "DesignAFoodRatingSystem.h"

//#include <bits/stdc++.h>
//using namespace std;


int main()
{
	freopen("output.txt", "w", stdout);
	freopen("input.txt", "r", stdin);
	//Runner(false).run<DesignAFoodRatingSystem>();
	DesignAFoodRatingSystem* obj = new DesignAFoodRatingSystem(
		{ "kimchi", "miso", "sushi", "moussaka", "ramen", "bulgogi" },
		{ "korean", "japanese", "japanese", "greek", "japanese", "korean" },
		{ 9, 12, 8, 15, 14, 7 });

	Printer::print(obj->highestRated("korean"));
	Printer::print(obj->highestRated("japanese"));
	obj->changeRating("sushi", 16);
	Printer::print(obj->highestRated("japanese"));
	obj->changeRating("ramen", 16);
	Printer::print(obj->highestRated("japanese"));
}
