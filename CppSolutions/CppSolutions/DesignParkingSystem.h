#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/design-parking-system/

class DesignParkingSystem
{
public:
	// 48 ms, faster than 91.97% : 33 MB, less than 75.78%
	DesignParkingSystem(int big, int medium, int small) {
		this->big = big;
		this->medium = medium;
		this->small = small;
	}

	bool addCar(int carType) {
		switch (carType)
		{
		case 1:
			return big-- > 0;
		case 2:
			return medium-- > 0;
		default:
			return small-- > 0;
		}
	}

private:
	int big, medium, small;
};

