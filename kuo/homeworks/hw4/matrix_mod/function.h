#ifndef FUNCTION_H
#define FUNCTION_H

#include <iostream>

using namespace std;

class Matrix
{
public:
    Matrix() : rows(0), cols(0), data(nullptr) {}

    // Construct a matrix of size R x C.
    // Acts as Identity if R==C, otherwise fills with 0.
    Matrix(long long r, long long c)
    {
        this->rows = r;
        this->cols = c;
        this->data = new long long *[r];
        for (long long i = 0; i < r; i++)
        {
            this->data[i] = new long long[c];
            for (long long j = 0; j < c; j++)
            {
                if (r == c && i == j)
                    this->data[i][j] = 1;
                else
                    this->data[i][j] = 0;
            }
        }
    }

    // Construct a matrix with the given data.
    Matrix(long long r, long long c, long long **Data)
    {
        this->rows = r;
        this->cols = c;
        this->data = new long long *[r];
        for (long long i = 0; i < r; i++)
        {
            this->data[i] = new long long[c];
            for (long long j = 0; j < c; j++)
            {
                this->data[i][j] = Data[i][j];
            }
        }
    }

    ~Matrix()
    {
        if (this->data != nullptr)
        {
            for (long long i = 0; i < this->rows; i++)
            {
                delete[] this->data[i];
            }
            delete[] this->data;
        }
    };

    // Print out the matrix.
    void print() const
    {
        for (long long i = 0; i < this->rows; i++)
        {
            for (long long j = 0; j < this->cols; j++)
            {
                cout << this->data[i][j] << " ";
            }
            cout << endl;
        }
    }

    // To be implemented in function.cpp
    void add(const Matrix &rhs);
    void subtract(const Matrix &rhs);
    void multiply(const Matrix &rhs);
    void transpose();
    void power(long long x);

private:
    long long rows;
    long long cols;
    long long **data;
};

#endif