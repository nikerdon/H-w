#include <bits/stdc++.h>
using namespace std;

struct zd
{
    int t;
    int tau;
    int ind;
};

bool cmp(zd a, zd b)
{
    return (a.t < b.t);
}

int main()
{
    int k;
    cin >> k;
    vector<zd> m(k);
    for (int i=0; i<k; ++i)
    {
        cin >> m[i].t >> m[i].tau;
        m[i].ind=i+1;
    }
    sort(m.begin(),m.end(),cmp);

    int t_start, t_end;
    cin >> t_start >> t_end;
    int i=0;
    while (m[i].t<t_start && i<k) ++i;
    if (i == k)
    {
        cout << "nope\n";
        return 0;
    }
    vector<int> d(k,-1);
    d[i]=i;
    int j=i, st=i;
    for (i=i; i<k; ++i)
    {
        if(m[d[j]].t + m[d[j]].tau > m[i].t)
        {
            if (m[d[j]].t+m[d[j]].tau>m[i].t+m[i].tau)
            {
                d[j]=i;
            }
        }
        else
        {
            ++j;
            d[j]=i;
        }
    }
    bool b=true;
    cout<<"Complete tasks: ";
    for (st=st; st<=j; ++st)
    {
        if (m[d[st]].t+m[d[st]].tau>t_end) break;
        cout<<m[d[st]].ind<<" ";
        b=false;
    }
    if (b)
    {
        cout<<"nope\n";
    }
}
