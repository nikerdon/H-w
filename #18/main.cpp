#include <iostream>
#include <cstdlib>

using namespace std;

int part(int* x, int l, int r)
{
     int v=x[(l+r)/2];
     int i=l;
     int j=r;
     while (i<=j)
     {
        while (x[i]<v)
           i++;
        while (x[j]>v)
           j--;
        if (i>=j)
           break;
        swap(x[i++],x[j--]);
     }
     return j;
}

int Stat(int* x, int le, int k)
{
  int left=0, right=le;
  while (true)
    {
    int mid=part(x,left,right);
    if (mid == k)
    {
      for (int i=0; i<le; i++)
      return x[mid];
    }
    if (k < mid)
    {
      right = mid;
    }
    if (k > mid)
    {
      left = mid + 1;
    }
  }
}

int main()
{
    int le;
    cin>>le;
    int x[le];
    for (int i=0; i<le; i++)
    {
        cin>>x[i];
    }
    int k;
    cin>>k;
    cout<<Stat(x,le,k-1)<<endl;
    system("pause");
}
