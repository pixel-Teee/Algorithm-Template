#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 100005;

int q[N];
int p[N];

void merge_sort(int l, int r)
{
    if(l >= r) return;
    int mid = l + r >> 1;
    merge_sort(l, mid), merge_sort(mid + 1, r);
    
    int i = l, j = mid + 1;
    int k = 0;
    while(i <= mid && j <= r)
    {
        if(q[i] <= q[j]) p[k++] = q[i++];
        else p[k++] = q[j++];
    }
    
    while(i <= mid) p[k++] = q[i++];
    while(j <= r) p[k++] = q[j++];
    
    for(int i = l, k = 0; i <= r; ++i)
    {
        q[i] = p[k++];
    }
}

int main()
{
    int n;
    cin >> n;
    
    for(int i = 0; i < n; ++i) cin >> q[i];
    
    merge_sort(0, n - 1);
    
    for(int i = 0; i < n; ++i) cout << p[i] << " ";
    return 0;
}