#include <iostream>
#include <conio.h>

using namespace std;

int main()
{
  int n;
  cin>>n;
  int A[n];
  for (int i=0; i<n; i++) cin>>A[i];

  int *q=A+n;
  for (int * p=A; p!=q; p++)
  {
    if (*p%2==1) cout<<*p<<' ';
  }
  _getch();
}
