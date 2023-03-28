#include <bits/stdc++.h>
using namespace std;
long long trappingWater(long long *a, long long n)
{
    long long start = 0, end = n - 1, leftmax = a[0], rightmax = a[n - 1], ans = 0;
    /*
    leftmax --> store maximum hight of block upto a index from left
    rightmax --> store maximum hight of block upto a index from right
    */
    while (start < end)
    {
        if (leftmax < rightmax)
        {
            start++;
            if (a[start] > leftmax)
                leftmax = a[start];
            ans += leftmax - a[start];
        }
        else
        {
            end--;
            if (a[end] > rightmax)
                rightmax = a[end];
            ans += rightmax - a[end];
        }
    }
    return ans;
}
int main()
{
    long long n;
    cin >> n;
    long long a[n];
    for (long long i = 0; i < n; i++)
        cin >> a[i];
    long long ans = trappingWater(a, n);
    cout << "Maximum water can store is --> " << ans << " units" << endl;
    return 0;
}
