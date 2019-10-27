//Напишите программу перебирающую все перестановки массива букв в лексикографическом порядке. Программа должна работать не более чем за O(n!*n) шагов.
#include <iostream>
#include <cstdlib>

using namespace std;

char m[100];
int n;

void Swap(int a,int b)
{
    int t=m[a];
    m[a]=m[b];
    m[b]=t;
}

void Gen(int k)
{
    if (k==n)
    {
      for(int i=0;i<n;i++)
        {
            cout<<m[i];
        }
      cout<<""<<endl;;
    }
    else
    {
        for(int j=k;j<n;j++)
        {
            Swap(k,j);
            Gen(k+1);
            Swap(k,j);
        }
    }
}

int main()
{
    string s;
    cin>>s;
    n=s.length();
    for(int i=0;i<n;i++)
        m[i]=s[i];
    Gen(0);
    system("pause");
}
