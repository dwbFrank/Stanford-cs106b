#include "combinatorics.h"

int permutations(int n, int k)
{
    int result = 1;

    for (int i = 0; i < k; i++)
    {
        result *= (n - i);
    }

    return result;
}

int combinations(int n, int k)
{
    return permutations(n, k) / permutations(k, k);
}