#include <iostream>
#include <ctime>
using namespace std;

int main()
{
  int A[1000];
  for (int i=0; i<1000; i++)
  {
      A[i]=i;
  }
  int s=0;
  for (int i=0; i<1000; i++)
    {
        s+=A[i];
    }

  cout<<s<<endl;
  return 0;
}
