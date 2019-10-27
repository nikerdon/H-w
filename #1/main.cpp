#include <iostream>
#include <conio.h>
using namespace std;

int fact(int a)
{
  int s1=1;
  for (int i=1; i<=a; i++)
      s1=s1*i;
    return s1;
}

int main()
{
    int n,sum=0;
    cin >> n;
    int mas[n];
    for (int i=1; i<=n; i++)
        {cin >> mas[i];
        sum=sum+fact(mas[i]);}
    cout<<(sum/n)<<endl;
    _getch();
}

