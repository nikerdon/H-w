//Решить непрерывную задачу о рюкзаке и доказать через матроиды корректность алгоритма.
#include <iostream>
#include <cstdlib>

using namespace std;

void Qs(float* x, int* l, int* t, int left, int right)
{
    int i=left, j=right;
    float mid=1.0*x[(left+right)/2];
    while (i<=j)
    {
       while (x[i]<mid)
          i++;
       while (x[j]>mid)
          j--;
       if (i<=j)
       {
           swap(x[i],x[j]);
           swap(l[i],l[j]);
           swap(t[i],t[j]);
           i++;
           j--;
       }
    };
    if (left<j)
       Qs(x,l,t,left,j);
    if (i<right)
       Qs(x,l,t,i,right);
}

int main()
{
   int n,W;
   float cuw=0,cuc=0;
   cin>>n>>W;
   int c[n]={0},w[n]={0},t[n]={0};
   float u[n];
   for (int i=0; i<n; i++)
   {
       cin>>c[i];
   }
   for (int i=0; i<n; i++)
   {
       cin>>w[i];
       u[i]=1.0*c[i]/w[i];
       t[i]=i;
   }

   Qs(u,w,t,0,n);
   cout<<endl;
   cout<<"Take object(-s): "<<endl;
   for (int i=n; i>0; i--)
   {
       if (cuw==W) break;
       if (cuw+w[i]<=W)
       {
           cuc+=1.0*u[i]*w[i];
           cuw+=1.0*w[i];
           cout<<w[i]<<" c.u. of #"<<t[i]+1<<endl;
           continue;
       }
       if (cuw+w[i]>W)
       {
           cuc+=1.0*(W-cuw)*u[i];
           cout<<(W-cuw)<<" c.u. of #"<<t[i]+1<<endl;
           cuw=W;
           break;
       }
   }
   cout<<"Max cost is: "<<cuc<<endl;
   cout<<"Max weight is: "<<cuw<<endl;
   system("pause");
}
