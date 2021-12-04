/*
第k个算法，这个算法，找到第k个数后，并不能将原先的数组排好序
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
const int N = 100005;
int q[N];

int quick_sort(int l, int r, int k)
{
    if(l >= r) return q[l];
    int i = l - 1, j = r + 1, x = q[l + r >> 1];
    while(i < j)
    {
        do i++; while(q[i] < x);
        do j--; while(q[j] > x);
        if(i < j) swap(q[i], q[j]);
    }
    int sl = j - l + 1;
    if(k <= sl) return quick_sort(l, j, k);
    else return quick_sort(j + 1, r, k - sl);
}
int main()
{
    int n, k;
    cin >> n >> k;
    for(int i = 1; i <= n; ++i) cin >> q[i];
    
    cout << quick_sort(1, n, k) << endl;
    return 0;
}