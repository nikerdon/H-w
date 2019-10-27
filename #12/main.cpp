//–еализовать решето Ёратосфена
#include <iostream>
#include <cstdlib>

using namespace std;

int Prime(int n)
{
    bool m[n];
    for(int i=1;i<=n;i++)
    {
        m[i]=true;
    }

    for(int i=2; i*i<=n;i++)
    {
        if (m[i]==true)
            for(int j=i*i; j<=n; j+=i)
                {
                    m[j]=false;
                }
    }
    for (int i=2; i<=n; i++)
    {
      if (m[i]==true) cout<<i<<endl;
    }
}

int main()
{
  int n;
  cin>>n;
  Prime(n);
  system("pause");
}
