#include "function.h"
#include <iostream>
using namespace std;

// #pragma once
// class VendingMachine
// {
// private:
//     int *data;
//     int capacity;
//     int size; // current amount

//     long long totalRevenue;
//     int totalSold;

// public: // these functions need to be implemented by you.
//     VendingMachine();

//     ~VendingMachine();

//     void store(int price);

//     void sell();

//     void printResult();
// };

VendingMachine::VendingMachine()
{
    capacity = 10;
    data = new int[capacity];
    size = 0;
    totalRevenue = 0;
    totalSold = 0;
}

VendingMachine::~VendingMachine()
{
    delete[] data;
}

void VendingMachine::store(int price)
{
    // dinamically adding new space...
    if (size == capacity)
    {
        capacity *= 2;
        int *newdata = new int[capacity];
        for (int i = 0; i < size; i++)
        {
            newdata[i] = data[i];
        }
        delete[] data;
        data = newdata;
    }

    data[size] = price;
    int cur = size++;
    while (cur > 0 && data[cur] < data[(cur - 1) / 2])
    {
        // swap(data[cur], data[(cur - 1) / 2]);
        // manual swap logic
        int temp = data[cur];
        data[cur] = data[(cur - 1) / 2];
        data[(cur - 1) / 2] = temp;

        cur = (cur - 1) / 2;
    }
}

void VendingMachine::sell()
{
    if (size <= 0)
        return;

    totalRevenue += data[0];
    totalSold += 1;

    // start cutting?
    size--;
    data[0] = data[size];
    int cur = 0;
    while (true)
    {
        int left = (cur * 2) + 1;
        int right = (cur * 2) + 2;
        int smallest = cur;

        if (left < size && data[left] < data[smallest])
            smallest = left;
        if (right < size && data[right] < data[smallest])
            smallest = right;

        if (smallest == cur)
            break;

        // swap(data[cur], data[smallest]);
        int temp = data[cur];
        data[cur] = data[smallest];
        data[smallest] = temp;

        cur = smallest;
    }
}

void VendingMachine::printResult()
{
    cout << totalSold << " " << totalRevenue << endl;
}