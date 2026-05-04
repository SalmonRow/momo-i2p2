#include "function.h"

void Matrix::add(const Matrix &rhs)
{
    for (long long i = 0; i < this->rows; i++)
    {
        for (long long j = 0; j < this->cols; j++)
        {
            this->data[i][j] += rhs.data[i][j];
        }
    }
}

void Matrix::subtract(const Matrix &rhs)
{
    for (long long i = 0; i < this->rows; i++)
    {
        for (long long j = 0; j < this->cols; j++)
        {
            this->data[i][j] -= rhs.data[i][j];
        }
    }
}

void Matrix::multiply(const Matrix &rhs)
{
    // checking condition
    if (this->cols != rhs.rows)
        return;

    // if valid
    // create a empty canvas for putting in otuputs
    // the new matrix after multi will be mat(this..row rhs.col)
    long long **temp = new long long *[this->rows];
    for (long long i = 0; i < this->rows; i++)
    {
        temp[i] = new long long[rhs.cols];
    }

    // iterate though
    for (long long i = 0; i < this->rows; i++)
    {
        for (long long j = 0; j < rhs.cols; j++)
        {
            temp[i][j] = 0;
            for (long long k = 0; k < rhs.rows; k++)
            {
                temp[i][j] += this->data[i][k] * rhs.data[k][j];
            }
        }
    }

    // handle when the matrix change shape ?
    // delete the old data.
    for (long long i = 0; i < this->rows; i++)
    {
        delete[] this->data[i];
    }

    delete[] this->data;

    this->cols = rhs.cols;
    this->data = temp;
}

void Matrix::transpose()
{
    // creating a temp with changed shapes
    //  rows go to column -> column to to rows
    long long **temp = new long long *[this->cols];
    for (long long i = 0; i < this->cols; i++)
    {
        temp[i] = new long long[this->rows];
    }

    for (long long i = 0; i < this->cols; i++)
    {
        for (long long j = 0; j < this->rows; j++)
        {
            temp[i][j] = this->data[j][i];
        }
    }

    for (long long i = 0; i < this->rows; i++)
    {
        delete[] this->data[i];
    }
    delete[] this->data;

    long long place = this->rows;
    this->rows = this->cols;
    this->cols = place;

    this->data = temp;
}

void Matrix::power(long long x)
{
    if (this->rows != this->cols)
        return;

    Matrix result(this->rows, this->cols);

    Matrix base(this->rows, this->cols, this->data);

    while (x > 0)
    {
        if (x % 2 == 1)
        {
            result.multiply(base);
        }
        base.multiply(base);
        x /= 2;
    }

    for (long long i = 0; i < this->rows; i++)
    {
        for (long long j = 0; j < this->cols; j++)
        {
            this->data[i][j] = result.data[i][j];
        }
    }
}