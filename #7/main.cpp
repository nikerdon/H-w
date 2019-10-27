#include <iostream>
#include <cstdlib>

using namespace std;

int gcd(int a, int b)
{
    int del=1;
    for(int i=1; i<=min(a,b); i++)
    {
       if (a%i==0 && b%i==0) del=i;
    }
    return del;
}

struct fraction
{
    int num;
    int den;
};

int main()
{
  int a,b,c,d;
  cin>>a>>b>>c>>d;
  fraction one = {a/gcd(a,b),b/gcd(a,b)};
  fraction two = {c/gcd(c,d),d/gcd(c,d)};

  int x,y;
  x=one.num*two.den+two.num*one.den;
  y=one.den*two.den;
  fraction sum = {x/gcd(x,y),y/gcd(x,y)};

  x=one.num*two.den-two.num*one.den;
  y=one.den*two.den;
  fraction dif = {x/gcd(x,y),y/gcd(x,y)};

  x=one.num*two.num;
  y=one.den*two.den;
  fraction prod = {x/gcd(x,y),y/gcd(x,y)};

  x=one.num*two.den;
  y=one.den*two.num;
  fraction quo = {x/gcd(x,y),y/gcd(x,y)};

  cout<<one.num<<"/"<<one.den<<endl;
  cout<<two.num<<"/"<<two.den<<endl;

  cout<<sum.num<<"/"<<sum.den<<endl;
  cout<<dif.num<<"/"<<dif.den<<endl;
  cout<<prod.num<<"/"<<prod.den<<endl;
  cout<<quo.num<<"/"<<quo.den<<endl;

  if (dif.num > 0) cout<<"First fraction is bigger"<<endl;
  if (dif.num < 0) cout<<"Second fraction is bigger"<<endl;
  if (dif.num == 0) cout<<"Fractions are equal"<<endl;
  system("pause");
  return 0;
}
