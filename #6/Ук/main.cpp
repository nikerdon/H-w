#include <iostream>

using namespace std;

int main()
{
  int A[1000];
  for (int i=0; i<1000; i++)
  {
      A[i]=i;
  }
  int s=0;
  int *q=A+1000;
  for (int * p=A; p!=q; p++)
  {
      s+=*p;
  }
  cout<<s<<endl;

}
