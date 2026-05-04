#include "function.h"
#include <iostream>

using namespace std;

VendingMachine::VendingMachine()
{
    capacity = 2000000;
    data = new int[capacity];
    size = 0; // index
    totalRevenue = 0;
    totalSold = 0;
}

VendingMachine::~VendingMachine()
{
    delete[] data;
}

void VendingMachine::store(int price)
{
    data[size] = price;
    int cur = size++;
    while (cur > 0 && data[cur] < data[(cur - 1) / 2])
    {
        swap(data[cur], data[(cur - 1) / 2]);
        cur = (cur - 1) / 2;
    }
}

void VendingMachine::sell()
{
    if (size <= 0)
        return;

    totalSold++;
    totalRevenue += data[0];

    size--;
    data[0] = data[size]; // swap the last one to the root of the BT

    int cur = 0;
    while (true)
    {
        int left = (cur * 2) + 1;
        int right = (cur * 2) + 2;
        int parent = (cur);

        if (left < size && data[parent] > data[left])
            parent = left;
        if (right < size && data[parent] > data[right])
            parent = right;

        if (parent == cur)
            break;

        swap(data[parent], data[cur]);
        cur = parent;
    }
}

void VendingMachine::printResult()
{
    cout << totalSold << " " << totalRevenue << endl;
}