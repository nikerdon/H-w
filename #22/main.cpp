//Решить задачу о селениях и дорогах.
#include <iostream>
#include <cstdlib>

using namespace std;

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
           i++;
           j--;
       }
    };
    if (left<j)
       Qs(x,left,j);
    if (i<right)
       Qs(x,i,right);
}

int main()
{
    int k;
    cin>>k;
    int x[k][k],a[(k*k-k)/2];
    for (int i=0; i<k; i++)
        for (int j=0; j<k; j++)
        x[i][j]=-1;

    int c=0;
    for (int i=0; i<k; i++)
        for (int j=0; j<k; j++)
        {
           if (i<j)
           {
                cout<<"Price of the road from "<<i<<" to "<<j<<": ";
                cin>>x[i][j];
                a[c]=x[i][j];
                c++;
                x[j][i]=x[i][j];
           }
        }

    Qs(a,0,(k*k-k)/2);

    int x1=0,y1=0,u=0;
    int fi[k]={0};

    bool b1=false,b2=false;

    for (int i=0; i<(k*k-k)/2; i++)
    {
        for (int i1=0; i1<k; i1++)
            for (int j1=0; j1<k; j1++)
            {
                if (a[i]==x[i1][j1])
                {
                    x1=i1;
                    y1=j1;
                }
            }
        b1=false;
        b2=false;
        for (int h=0; h<k; h++)
        {
            if (fi[h]==x1) b1=true;
            if (fi[h]==y1) b2=true;
        }
        if (b1==false)
        {
            fi[u]=x1;
            u++;
            cout<<"Build the road between "<<x1<<" and "<<y1<<endl;
        }
        if (b2==false)
        {
            fi[u]=y1;
            u++;
            cout<<"Build the road between "<<x1<<" and "<<y1<<endl;
        }

        if (u-1==k) break;
    }
    system("pause");
}


