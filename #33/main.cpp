#include <iostream>
#include <vector>
#include <stack>
#include <cstdlib>

using namespace std;

int main()
{
    int y,x,k=0;
    cout<<"Enter the number of rows and columns: ";
    cin>>y>>x;
    stack<int> s;
    vector<int> v(x,-1),v1(x),v2(x);
    vector <vector<int> > a (y, vector<int> (x));

    for (int i=0; i<y; i++)
        for (int j=0; j<x; j++)
            cin>>a[i][j];

    for (int i=0; i<y; i++)
    {
        for (int j=0; j<x; j++)
            if (a[i][j]==1) v[j]=i;

        for (int j=0; j<x; j++)
        {
            while (!s.empty() && v[s.top()]<=v[j]) s.pop();
            v1[j]=s.empty() ? -1 : s.top();
            s.push(j);
        }

        while (!s.empty()) s.pop();
        for (int j=x-1; j>=0; j--)
        {
            while (!s.empty() && v[s.top()]<=v[j]) s.pop();
            v2[j]=s.empty() ? x : s.top();
            s.push(j);
        }

        for (int j=0; j<x; j++)
        k=max(k,(i-v[j])*(v2[j]-v1[j]-1));
    }
    cout<<"Max square of null rectangular is "<<k<<endl;
    system("pause");
}
