#include <stdlib.h>
#include <conio.h>
#include <iostream>

int f(const void *a, const void *b)
{
  return (*(int*)a-*(int*)b);
}

using namespace std;

int main ()
{
  int n,i;
  cin>>n;
  int A[n];
  for (i=0; i<n; i++) cin>>A[i];

  qsort (A,n,sizeof(int),f);

  for(i=0; i<n; i++) cout<<A[i]<<" ";

  _getch();
}
