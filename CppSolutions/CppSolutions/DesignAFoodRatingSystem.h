#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/design-a-food-rating-system/

struct Rating {
	int rate;
	string food;
	Rating(int rate, string food) :food(food), rate(rate) {};
	bool operator <(const Rating& o) const {
		return rate != o.rate ? rate > o.rate: food < o.food;
	};
};

class DesignAFoodRatingSystem
{
public:
	// 387 ms, faster than 84.69% : 164.7 MB, less than 74.64%
	DesignAFoodRatingSystem(vector<string> foods, vector<string> cuisines, vector<int> ratings) {
		int c = 0;
		for (size_t i = 0; i < size(foods); i++) {
			if (!cat.count(cuisines[i])) {
				cat[cuisines[i]] = c++;
				cats.push_back({});
			}
			cats[m[foods[i]] = cat[cuisines[i]]].insert(Rating{ ratings[i], foods[i] });
			rates[foods[i]] = ratings[i];
		}
	}
	void changeRating(string food, int newRating) {
		cats[m[food]].erase(Rating{ rates[food], food });
		cats[m[food]].insert(Rating{ newRating, food });
		rates[food] = newRating;
	}

	string highestRated(string cuisine) {
		return cats[cat[cuisine]].begin()->food;
	}
	unordered_map<string, int> m;
	unordered_map<string, int> rates;
	unordered_map<string, int> cat;
	vector<set<Rating>> cats;
};

/**
 * Your DesignAFoodRatingSystem object will be instantiated and called as such:
 * DesignAFoodRatingSystem* obj = new DesignAFoodRatingSystem(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */