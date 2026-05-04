#include "function.h"
#include <iostream>

using namespace std;

// Helper function to quickly spawn 2D arrays for testing
long long **create2DArray(int r, int c, int startVal)
{
    long long **arr = new long long *[r];
    int val = startVal;
    for (int i = 0; i < r; i++)
    {
        arr[i] = new long long[c];
        for (int j = 0; j < c; j++)
        {
            arr[i][j] = val++;
        }
    }
    return arr;
}

int main()
{
    cout << "--- Level 1: Matrix Shape-Shifter Arena ---" << endl;

    // 1. Spawn a 2x3 Matrix
    long long **dataA = create2DArray(2, 3, 1);
    Matrix A(2, 3, dataA);
    cout << "\nMatrix A (2x3):" << endl;
    A.print(); // Expected: 1 2 3 \n 4 5 6

    // 2. Transpose Test (Shape-shift to 3x2)
    cout << "\nTransposing A..." << endl;
    A.transpose();
    A.print(); // Expected: 1 4 \n 2 5 \n 3 6

    // 3. Multiply Test
    long long **dataB = create2DArray(2, 4, 1);
    Matrix B(2, 4, dataB);
    cout << "\nMatrix B (2x4):" << endl;
    B.print(); // Expected: 1 2 3 4 \n 5 6 7 8

    cout << "\nMultiplying A (3x2) * B (2x4)..." << endl;
    A.multiply(B);
    A.print(); // Expected result should be a 3x4 Matrix!

    // Cleanup raw arrays
    for (int i = 0; i < 2; i++)
        delete[] dataA[i];
    delete[] dataA;
    for (int i = 0; i < 2; i++)
        delete[] dataB[i];
    delete[] dataB;

    cout << "\nArena cleared. If this printed correctly without a Segfault, you pass." << endl;
    return 0;
}