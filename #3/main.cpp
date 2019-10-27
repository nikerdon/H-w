#include <iostream>
#include <conio.h>

using namespace std;

int main()
{
  int x,n;
  cin >> x;
  n=0;
  for(int i =1; i <=x; i++)
  {
      if (x%i==0) n++;
  }
  cout<<n<<endl;
 _getch();
}
