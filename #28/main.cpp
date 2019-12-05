#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
   int x,y;
   cout<<"Enter the number of columns and rows: ";
   cin>>x>>y;
   cout<<"Enter the matrix:"<<endl;
   int a[x][y];
   for (int i=0; i<y; i++)
      for (int j=0; j<x; j++)
         cin>>a[j][i];

   int b[x];
   int sum=0;
   for (int i=0; i<x; i++)
   {
       for (int j=0; j<y; j++)
       {
           if (a[i][j]==1) sum++;
       }
       b[i]=sum%2;
       sum=0;
   }

   cout<<"Enter the incorrect matrix:"<<endl;
   int c[x][y-1];
   for (int i=0; i<y-1; i++)
      for (int j=0; j<x; j++)
         cin>>c[j][i];

   int t[x],g[x];
   for (int i=0; i<x; i++)
   {
       for (int j=0; j<y-1; j++)
       {
           if (c[i][j]==1) sum++;
       }
       t[i]=sum%2;
       sum=0;
   }
   cout<<"The lost line is: "<<endl;
   for (int i=0; i<x; i++)
   {
       if (b[i]==t[i])
       {
           g[i]=0;
       } else
       {
           g[i]=1;
       }
       cout<<g[i]<<" ";
   }

   system("pause");
}
