//Написать программу, выводящую все палиндромы длины n
//Эффективно, поскольку перебираются не все значения от 0 до 10^(n+1)-1. Производится симметричное отображение половины числа.
#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

int main()
{
  int n,l,p;

  cin>>n;

  char s[n],s1[n];
  l=(n-n%2)/2;
  int i=pow(10,l-1);
  float k=pow(10,l)-1;

  for (i;i<=k;i++)
  {
     itoa(i,s,10);
     if (n%2==0)
     {
         cout<<s;
         for (int j=l-1;j>=0;j--)
            {
                cout<<s[j];
            }
         cout<<""<<endl;
     }
     else {
        for (int r=0;r<=9;r++)
        {
            cout<<s;
            cout<<r;
            for (int j=l-1;j>=0;j--)
            {
                cout<<s[j];
            }
            cout<<""<<endl;
        }
     }
  }
  system("pause");
}

