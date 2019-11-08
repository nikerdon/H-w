#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
   int n;
   cin>>n;
   int k[n];
   k[0]=0;
   for (int i=1; i<=n; i++)
   {
       k[i]=INT_MAX;
       for (int j=1; j*j<=i; j++)
       {
           k[i]=min(k[i],k[i-j*j]+1);
       }
   }
   cout<<k[n]<<endl;
   system("pause");
}
