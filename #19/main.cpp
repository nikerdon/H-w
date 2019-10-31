#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;
int time1=0,time2=0;

void Qs(int* x, int left, int right)
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
           time1+=3;
           i++;
           j--;
       }
    };
    if (left<j)
       Qs(x,left,j);
    if (i<right)
       Qs(x,i,right);
}

void Ss(int* y, int right)
{
    int cu;
    for (int i=0; i<right-1; i++)
    {
        cu=i;
        for (int j=i+1; j<right; j++)
        if (y[j]<y[cu])
        {
            cu=j;
            time2++;
        }
        if (cu!=i)
        {
                swap(y[i],y[cu]);
                time2+=3;
        }
    }
}


int main()
{
    int le;
    cin>>le;
    int x[le],y[le];
    srand(time(0));
    for (int i=0; i<le; i++)
    {
        x[i]=1+rand()%100;
        y[i]=x[i];
        cout<<x[i]<<" ";
    }
    cout<<""<<endl;
    Qs(x,0,le);
    Ss(y,le);
    cout<<time1<<" "<<time2<<endl;
}
