//На вещественную ось брошено N отрезков. Найти максимальное по включению множество непересекающихся отрезков. Доказать через матроиды корректность алгоритма.
#include <iostream>
#include <cstdlib>

using namespace std;

void Qs(int* x, int* l, int left, int right)
{
    int i=left, j=right;
    int mid=x[(left+right)/2];
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
           i++;
           j--;
       }
    };
    if (left<j)
       Qs(x,l,left,j);
    if (i<right)
       Qs(x,l,i,right);
}

int main()
{
   int n;
   cin>>n;
   int l[n],r[n];
   for (int i=0; i<n; i++)
   {
       cin>>l[i]>>r[i];
   }
   Qs(r,l,0,n);
   for (int i=0; i<n; i++)
   {
       if (r[i]==r[i+1] && l[i]>l[i+1]) swap(l[i],l[i+1]);
   }
   int c=1;
   int t=0;
   for (int i=0; i<n; i++)
   {
       if (l[i]>=r[t])
       {
           c++;
           t=i;
       }
   }
   cout<<c;
   system("pause");
}
