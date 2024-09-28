#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/design-circular-deque/description/

class DesignCircularDeque {
public:
    // 14 ms, faster than 95.58% : 22.83 MB, less than 17.67%

    int maxSize;
    list<int> l;

public:
    void MyCircularDeque(int k)
    {
        maxSize = k;
    }

    bool insertFront(int value)
    {
        if (isFull())
            return false;

        l.push_front(value);
        return true;
    }

    bool insertLast(int value)
    {
        if (isFull())
            return false;

        l.push_back(value);
        return true;
    }

    bool deleteFront()
    {
        if (isEmpty())
            return false;

        l.pop_front();
        return true;
    }

    bool deleteLast()
    {
        if (isEmpty())
            return false;

        l.pop_back();
        return true;
    }

    int getFront()
    {
        if (isEmpty())
            return -1;

        return l.front();
    }

    int getRear()
    {
        if (isEmpty())
            return -1;

        return l.back();
    }

    bool isEmpty()
    {
        return l.empty();
    }

    bool isFull()
    {
        return size(l) == maxSize;
    }
};