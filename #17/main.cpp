//Реализовать алгоритм Карацубы
#include <bits/stdc++.h>

using namespace std;

vector<int> Re()
{
    string s;
    cin>>s;
    vector<int> v(s.size());
    for (int i=0; i<s.size(); i++)
    {
        v[i]=s[i]-'0';
    }
    reverse(v.begin(),v.end());
    return v;
}

vector<int> Sum(vector<int> a, vector<int> b)
{
    if (a.size()<b.size())
    {
        swap(a,b);
    }
    for (int i=0; i<b.size(); i++)
        a[i]+=b[i];

    int x=0;
    for(int i=0; i<a.size(); i++)
    {
        x=a[i]/10;
        a[i]=a[i]%10;
        if (x==1 && i==a.size()-1)
            a.push_back(1);
        else if (i<a.size()-1)
        {
            a[i+1]=a[i+1]+x;
        }
    }
    return a;
}

vector<int> Mi(vector<int> a, vector<int> b)
{
    for(int i=0; i<b.size(); i++)
    {
        a[i]=a[i]-b[i];
        if (a[i]<0)
        {
            a[i+1]--;
            a[i]=a[i]+10;
        }
    }
    int i=a.size()-1;
    while(a[i]==0 && i>0) i--;
    vector<int> ans(i+1);
    for (int j=0; j<=i; j++)
    {
        ans[j]=a[j];
    }
    return ans;
}

vector<int> Deg(vector<int> a, int n)
{
    reverse(a.begin(),a.end());
    for (int i=0; i<n; i++)
    {
        a.push_back(0);
    }
    reverse(a.begin(),a.end());
    return a;
}

vector<int> Kar(vector<int> a, vector<int> b) {
    if (a.size()!=b.size())
    {
        if (a.size()<b.size()) swap(a,b);
        while(b.size()<a.size()) b.push_back(0);
    }
    vector<int> a1,a2,b1,b2;
    int n=a.size();
    if (n==1)
    {
        vector<int> ans(1);
        ans[0]=a[0]*b[0];
        if (ans[0]>9)
        {
            ans.push_back(ans[0]/10);
            ans[0]%=10;
        }
        return ans;
    }
    for (int i=0; i<n/2; i++) a1.push_back(a[i]);
    for (int i=n/2; i<n; i++) a2.push_back(a[i]);
    for (int i=0; i<n/2; i++) b1.push_back(b[i]);
    for (int i=n/2; i<n; i++) b2.push_back(b[i]);
    vector<int> x=Kar(a1,b1);
    vector<int> y=Kar(a2,b2);
    vector<int> z=Kar(Sum(a1,a2),Sum(b1,b2));
    z = Mi(z,x);
    z = Mi(z,y);
    z = Deg(z,n/2);
    y = Deg(y,n/2+n/2);
    vector<int> ans=Sum(x,y);
    ans=Sum(ans,z);
    vector<int> r(1);
    ans=Mi(ans,r);
    return ans;
}

int main()
{
    vector<int> a,b;
    a=Re();
    b=Re();
    vector<int> c=Kar(a,b);
    for (int i=c.size()-1; i>=0; i--)
    {
        cout<<c[i];
    }
    return 0;
}
