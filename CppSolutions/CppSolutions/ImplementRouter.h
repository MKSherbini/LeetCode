#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/implement-router

class ImplementRouter {
public:
    // 218 ms, faster than 81.16% : 436.6 MB, less than 68.15%
    ImplementRouter(int memoryLimit)
    {
        limit = memoryLimit;
    }

    bool addPacket(int source, int destination, int timestamp)
    {
        auto packet = make_tuple(source, destination, timestamp);
        if (seen.count(packet))
            return false;

        if (packets.size() >= limit)
            forwardPacket();

        packets.push_front(packet);
        seen.insert(packet);
        destMap[destination].push_back(timestamp);
        return true;
    }

    vector<int> forwardPacket()
    {
        if (packets.empty())
            return {};
        auto packet = packets.back();
        packets.pop_back();
        seen.erase(packet);
        destMap[get<1>(packet)].pop_front();
        return { get<0>(packet), get<1>(packet), get<2>(packet) };
    }

    int getCount(int destination, int startTime, int endTime)
    {
        if (!destMap.count(destination) || packets.empty())
            return 0;
        auto& times = destMap[destination];
        auto it1 = lower_bound(times.begin(), times.end(), startTime);
        auto it2 = upper_bound(times.begin(), times.end(), endTime);
        return it2 - it1;
    }

private:
    deque<tuple<int, int, int>> packets;
    set<tuple<int, int, int>> seen;
    unordered_map<int, deque<int>> destMap;
    int limit;
};