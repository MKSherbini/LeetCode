#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/seat-reservation-manager/

class SeatReservationManager
{
public:
	// 232 ms, faster than 99.86% : 141.8 MB, less than 98.85%
	SeatReservationManager(int n) {

	}

	int reserve() {
		if (pq.empty()) return ++n;
		int seat = pq.top();
		pq.pop();
		return seat;
	}

	void unreserve(int seatNumber) {
		pq.push(seatNumber);
	}
private:
	priority_queue<int, vector<int>, greater<int>> pq;
	int n = 0;
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */