#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
   int n;
   cin>>n;
   int a[n+1][n+1],b[n+1][n+1],c[n+1][n+1];
   for (int i=1; i<=n; i++)
   {
       for (int j=1; j<=n; j++)
       {
            cin>>a[i][j];
       }
   }
      for (int i=1; i<=n; i++)
   {
       for (int j=1; j<=n; j++)
       {
            cin>>c[i][j];
       }
   }

   for (int i=0; i<=n; i++)
   {
       b[i][0]=0;
       b[0][i]=0;
   }
   for (int i=1; i<=n; i++)
   {
       for (int j=1; j<=n; j++)
       {
           if (c[i][j]==0) b[i][j]=max(b[i-1][j],b[i][j-1])+a[i][j];
           if (c[i][j]==1) b[i][j]=max(max(b[i-1][j],b[i][j-1]),b[i-1][j-1])+a[i][j];

       }
   }
   int i=n;
   int j=n,h=0;
   int g[2*n];
   while (i!=1 && j!=1)
   {
       if (c[i][j]==0)
       {
           if (b[i-1][j]>=b[i][j-1] && i-1>=1)
           {
               g[h]=a[i-1][j];
               h++;
               i--;
               continue;
           }
           if (b[i-1][j]<b[i][j-1] && j-1>=1)
           {
               g[h]=a[i][j-1];
               h++;
               j--;
               continue;
           }
        }
        if (c[i][j]==1)
        {
           if (b[i-1][j]>=b[i][j-1] && b[i-1][j]>=b[i-1][j-1] && i-1>=1)
           {
               g[h]=a[i-1][j];
               h++;
               i--;
               continue;
           }
           if (b[i][j-1]>b[i-1][j] && b[i][j-1]>=b[i-1][j-1] && j-1>=1)
           {
               g[h]=a[i][j-1];
               h++;
               j--;
               continue;
           }
           if (b[i-1][j-1]>b[i][j-1] && b[i-1][j-1]>b[i-1][j] && (i-1>=1) && (j-1>=1))
           {
               g[h]=a[i-1][j-1];
               h++;
               i--;
               j--;
               continue;
           }
        }
   }
   cout<<"The way goes via ";
   for (int r=0; r<h; r++)
   {
       cout<<g[h-r-1]<<" ";
   }
   cout<<endl;
   cout<<"The cost of the way is "<<b[n][n]<<endl;

   system("pause");
}
