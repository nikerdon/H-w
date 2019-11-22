//Hamming code
#include <iostream>
#include <cstdlib>
#include <string>
#include <cmath>

using namespace std;

int Dv(int l)
{
    int i=0,sum=0;
    while (true)
    {
        if (l>sum)
        {
            sum+=pow(2,i);
            i++;
        }
        if (l<=sum) return i;
    }
}

bool Deg(int i)
{
    bool b=false;
    int j=0;
    while (i>=pow(2,j))
    {
        if (i==pow(2,j)) b=true;
        j++;
    }
    return b;
}

int Cont(int* w,int g, string s, int* a,int n)
{
   int h=0,k1=0,f=0;
   for (int t=0; t<=g; t++)
   {
        h=0;
        for (int i=0; i<8*s.length()+n; i++)
        {
            if (i+1==pow(2,t))
            {
                f=i;
                while (f<8*s.length()+n)
                {
                    k1=0;
                    while (k1<pow(2,t) && f+k1<8*s.length()+n)
                    {
                        if (a[f+k1]==1) h++;
                        k1++;
                    }
                    f+=pow(2,t+1);
                    w[t]=h;
                }
                break;
            }

        }
   }

   int k2=0,i2=0;
   while (i2<pow(2,g))
   {
       if (Deg(i2+1)==true)
            {
                if (w[k2]%2==1) a[i2]=1;
                k2++;
            }
       i2++;
   }
}
int main()
{
   string s;
   cin>>s;
   int n,k,g=0;
   n=Dv(8*s.length());
   int a[8*s.length()+n],b[8*s.length()+n];
   for(int i=0; i<8*s.length()+n; i++)
   {
       a[i]=0;
       b[i]=0;
   }
   for (int i=0; i<s.length(); i++)
   {
        k=128;
        while (k>0)
        {
            a[g]=bool(s[i]&k);
            g++;
            k=k>>1;
        }
   }
   g=-1;
   for (int i=0; i<8*s.length()+n; i++)
   {
        if (Deg(i+1)==true)
        {
            g++;
            for (int j=8*s.length()+n-1; j>i; j--)
            {
                a[j]=a[j-1];
            }
            a[i]=0;
        }
   }

   int w[g];
   Cont(w,g,s,a,n);
   cout<<"Coded message: ";
   for (int i=0; i<8*s.length()+n; i++)
   {
        cout<<a[i];
   }

   cout<<endl;

   cout<<"Enter the wrong message: "<<endl;
   for (int i=0; i<8*s.length(); i++)
   {
        cin>>b[i];
   }

   for (int i=0; i<8*s.length()+n; i++)
   {
        if (Deg(i+1)==true)
        {
            for (int j=8*s.length()+n-1; j>i; j--)
            {
                b[j]=b[j-1];
            }
            b[i]=0;
        }
   }

   int w1[g];

   Cont(w1,g,s,b,n);

   int sum=0;
   for (int i=0; i<=g; i++)
   {
        if (w[i]!=w1[i]) sum+=pow(2,i);
   }
   b[sum-1]=abs(b[sum-1]-1);
   cout<<"Corrected code: ";
   for (int i=0; i<=8*s.length()+n-1; i++)
   {
        if (Deg(i+1)==false) cout<<b[i];
   }
   cout<<endl;
   system("pause");
}
