/*
相关例题:
leetcode2096:2104.子数组范围和 https://leetcode-cn.com/problems/sum-of-subarray-ranges/
思路:两个滑动窗口求最值一起做，时间卡的很严，用STL容器和线段树都无法过
*/

//对于i < j,并且a[i] >= a[j],那么a[i]是可以舍弃的
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1000005;

int a[N], q[N];

int main()
{
    int n, k;
    
    cin >> n >> k;
    
    for(int i = 0; i < n; ++i) cin >> a[i];
    
    int hh = 0, tt = -1;
    for(int i = 0; i < n; ++i)
    {
        if(hh <= tt && i - k + 1 > q[hh]) ++hh;
        while(hh <= tt && a[q[tt]] >= a[i]) --tt;
        q[++tt] = i;
        if(i >= k - 1) printf("%d ", a[q[hh]]);
    }
    
    puts(" ");
    
    hh = 0, tt = -1;
    
    for(int i = 0; i < n; ++i)
    {
        if(hh <= tt && i - k + 1 > q[hh]) ++hh;
        while(hh <= tt && a[q[tt]] <= a[i]) --tt;
        q[++tt] = i;
        if(i >= k - 1) printf("%d ", a[q[hh]]);
    }
    
    puts(" ");
    
    return 0;
}





