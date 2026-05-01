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
    // temp matrix for temp result and read from the current matrix "this"
    long long n = this->n;
    long long **tmp = new long long *[n];
    for (long long i = 0; i < n; i++)
    {
        tmp[i] = new long long[n];
    }
    for (long long i = 0; i < n; i++)
    {
        for (long long j = 0; j < n; j++)
        {
            tmp[i][j] = 0;

            for (long long k = 0; k < n; k++)
            {
                tmp[i][j] += this->data[i][k] * rhs.data[k][j];
            }
        }
    }

    for (long long i = 0; i < this->n; i++)
    {
        for (long long j = 0; j < this->n; j++)
        {
            this->data[i][j] = tmp[i][j];
        }
    }

    // free()
    for (long long i = 0; i < n; i++)
    {
        delete[] tmp[i];
    }
    delete[] tmp;
}
void Matrix::transpose()
{
    for (long long i = 0; i < this->n; i++)
    {
        for (long long j = i + 1; j < this->n; j++) // iterate only the top half of the triangle
        {
            long long temp = this->data[i][j];
            this->data[i][j] = this->data[j][i];
            this->data[j][i] = temp;
            // normal swap logic
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
            result.multiply(base); // run at least once here
        }
        base.multiply(base); // overshoot but it's alr
        x /= 2;
    }

    // project
    for (long long i = 0; i < this->n; i++)
    {
        for (long long j = 0; j < this->n; j++)
        {
            this->data[i][j] = result.data[i][j];
        }
    }
}
