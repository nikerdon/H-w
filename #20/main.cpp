//Решить непрерывную задачу о рюкзаке и доказать через матроиды корректность алгоритма.
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int w,n,k,l;
    cin>>w>>n;
    vector<int> weight,cost;

    for (int i=0; i<n; i++)
    {
        cout<<"#"<<i+1<<" - ";
        cin>>k>>l;
        weight.push_back(k);
        cost.push_back(l);
    }

    int a[n+1][w+1];
    for (int i=0; i<=w; i++)
        a[0][i]=0;
    for (int i = 0;i<=n;++i)
        a[i][0]=0;
    for (int i = 1;i<=n;++i)
    {
        for (int j=1; j<=w; j++)
            if (j>=weight[i-1])
            {
                a[i][j] = max(a[i-1][j], a[i-1][j-weight[i-1]]+cost[i-1]);
            }
            else a[i][j] = a[i-1][j];
    }

    vector<int> ans;
    int i=n, j=w, mc=0, mw=0;
    while (true)
    {
        while (true)
        {
            if (i<1 || j<1) break;
            if (a[i][j]!=a[i-1][j])
            {
                ans.push_back(i);
                mc+=cost[i-1];
                mw+=weight[i-1];
                j-=weight[i-1];
            }
            i--;
        }
        break;
        }
    sort(ans.begin(),ans.end());
    cout<<"Used space is "<<mw<<" out of "<<w<<endl;
    cout<<"Max cost is "<<mc<<endl;
    cout<<"Take object(-s): ";
    for (int i=0; i<ans.size(); i++)
        cout<<"#"<<ans[i]<<" ";

    system("pause");
}
