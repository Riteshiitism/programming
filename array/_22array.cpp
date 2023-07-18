#include <bits/stdc++.h>
using namespace std;
int main()
{
    deque<int> dq;
    dq.push_back(1);
    int c = 0;
    for (int i = 2; i <= 80; i++)
    {
        c = 0;
        int l = dq.size();
        while (l != 0)
        {
            
            int e = dq.back();
            dq.pop_back();
            l--;
            int mul = e * i + c;
            int res = mul % 10;
            c = mul / 10;
            dq.push_front(res);
        }
        while (c!=0)
        {
            int x = c%10;
            dq.push_front(x);
            c = c/10;
        }
    }
    vector<int>res;
    int b = true;
    while (dq.size() != 0)
    {
        int t = dq.front();
        dq.pop_front();
        if (t!=0 && b==1)
        {
            b=false;
        }
        if (b==0)
        {
            res.push_back(t);
        }
        
    }
    cout<<endl;
    for (int value:res)
    {
        cout<<value;
    }   
}