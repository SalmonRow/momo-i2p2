#include "function.h"

void Matrix::add(const Matrix &rhs)
{
    for (long long i = 0; i < this->n; i++)
    {
        for (long long j = 0; j < this->n; j++)
        {
            this->data[i][j] += rhs.data[i][j];
        }
    }
}
void Matrix::subtract(const Matrix &rhs)
{
    for (long long i = 0; i < this->n; i++)
    {
        for (long long j = 0; j < this->n; j++)
        {
            this->data[i][j] -= rhs.data[i][j];
        }
    }
}
void Matrix::multiply(const Matrix &rhs)
{
    long long **temp = new long long *[this->n];
    for (long long i = 0; i < this->n; i++)
    {
        temp[i] = new long long[this->n];
    }

    for (long long i = 0; i < this->n; i++)
    {
        for (long long j = 0; j < this->n; j++)
        {
            temp[i][j] = 0;
            for (long long k = 0; k < this->n; k++)
            {
                temp[i][j] += this->data[i][k] * rhs.data[k][j];
            }
        }
    }

    for (long long i = 0; i < this->n; i++)
    {
        delete[] this->data[i];
    }
    delete[] this->data;

    // pointing to the newone.
    this->data = temp;
}
void Matrix::transpose()
{
    // no temp matrix appraoch
    for (long long i = 0; i < this->n; i++)
    {
        for (long long j = i + 1; j < this->n; j++)
        {
            long long temp = this->data[i][j];
            this->data[i][j] = this->data[j][i];
            this->data[j][i] = temp;
            // avoiding stl ...
        }
    }
}
void Matrix::power(long long x)
{
    Matrix result(this->n);

    Matrix base(this->n, this->data);

    while (x > 0)
    {
        if (x % 2 == 1)
        {
            result.multiply(base);
        }
        base.multiply(base);
        x /= 2;
    }

    // project because the result dat will be deleted after
    for (long long i = 0; i < this->n; i++)
    {
        for (long long j = 0; j < this->n; j++)
        {
            this->data[i][j] = result.data[i][j];
        }
    }
}
