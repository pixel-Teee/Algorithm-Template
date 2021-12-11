/*
去重:第一种，手写。
第二种，使用STL的set。
第三种，使用STL的algorithm。
*/

/*
手写
*/

vector<int>::iterator unique(vector<int>& a)
{
    int j = 0;
    for(int i = 0; i < a.size(); ++i)
    {
        if(!i || (a[i] != a[i - 1]))
            a[j++] = a[i];
    }
    /*返回尾后指针*/
    return a.begin() + j;
}

sort(alls.begin(), alls.end());
//或者使用STL的unique(alls.begin(), alls.end());
alls.erase(unique(alls), alls.end());

