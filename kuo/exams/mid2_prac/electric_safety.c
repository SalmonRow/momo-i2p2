#include <stdio.h>
#include <stdlib.h>

// globals
int heap[10005];
int size = 0;

void push(int val)
{
    heap[++size] = val; // add at the end and then swapping it
    int i = size;
    while (i > 1 && heap[i] < heap[i / 2])
    {
        int temp = heap[i];
        heap[i] = heap[i / 2];
        heap[i / 2] = temp;

        i /= 2;
    }
}

int pop()
{
    int val = heap[1]; // pop from the beginning
    heap[1] = heap[size];
    size--;
    int i = 1;

    while (1)
    {
        int left = i * 2;
        int right = i * 2 + 1;
        int smallest = i;

        if (left < size && heap[smallest] > heap[left])
            smallest = left;
        if (right < size && heap[smallest] > heap[right])
            smallest = right;
        if (smallest == i)
            break;

        int temp = heap[i];
        heap[i] = heap[smallest];
        heap[smallest] = temp;

        i = smallest;
    }
    return val;
}

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int x;
        scanf("%d", &x);
        push(x);
    }

    long long total = 0;
    while (size > 1)
    {
        int a = pop(), b = pop();
        total += a;
        total += b;
        push(a + b);
    }

    printf("%lld", total);
    return 0;
}