#include <iostream>
#include <conio.h>

using namespace std;

void P(int* A,int n)
{
    for (int i=0;i<n;i++)
    {
        if (A[i]%2==1) cout<<A[i]<<" ";
    }
}

int main()
{
  int n;
  cin>>n;
  int A[n];
  for (int i=0; i<n; i++) cin>>A[i];

  P(A,n);
  _getch();
}
