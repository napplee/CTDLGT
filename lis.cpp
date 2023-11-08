#include <bits/stdc++.h>
using namespace std;
int n,a[30001];
int f[30001];
int main()
{
    cin >> n;
    for(int i = 1 ;i<=n;i++)
    {
        cin >> a[i];
    }
    f[1] = 1;
    int res = 1;
    for(int i = 2;i<=n;i++)
    {
        int j=0;
        int l,r;
        l = 1,r = res;
        while(l <= r)
        {
            int mid = (l+r)/2;
            if(a[i] > a[f[mid]])
            {
                j = mid;
                l = mid + 1;
            }
            else
            {
                r = mid -1;
            }
        }
        if(j == res)
        {
            res++;
            f[res] = i;
        }
        if(a[i] < a[f[j + 1]]) f[j+1] = i;
    }
    cout << res;
}
/*
5
2 1 4 3 5


3
*/
