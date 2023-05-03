#include <iostream>
using namespace std;

int f(int x)
{
    return x * x * x - 10 * x * x - 15 * x - 20;
}

int findPositiveZero(int left, int right)
{
    if (f(left) <= 0 && f(left + 1) > 0)
    {
        return left + 1;
    }
    int mid = (left + right) / 2;
    if (f(mid) < 0)
    {
        return findPositiveZero(mid, right);
    }
    else
    {
        return findPositiveZero(left, mid);
    }
}

int main()
{
    int n = findPositiveZero(0, 100);
    cout << "\nSmallest integer value of n for which f(n) is positive: " << n << endl;
    return 0;
}
