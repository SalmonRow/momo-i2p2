#include "function.h"
#include <iostream>

using namespace std;

VendingMachine::VendingMachine()
{
    int capacity = 2000000;
    int *data = new int[capacity];
    int size = 0; // index
    long long totalRevenue = 0;
    int totalSold = 0;
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
}

void VendingMachine::printResult()
{
    cout << totalSold << " " << totalRevenue << endl;
}